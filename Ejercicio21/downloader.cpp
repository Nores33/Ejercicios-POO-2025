#include "downloader.h"
#include <QNetworkReply>
#include <QRegularExpression>
#include <QFile>
#include <QFileInfo>

Downloader::Downloader(QObject *parent) : QObject(parent), mainHtmlFetched(false) {
    connect(&manager, &QNetworkAccessManager::finished, this, &Downloader::onReplyFinished);
}

void Downloader::setDownloadDirectory(const QString &dir) {
    downloadDirectory = dir;
}

void Downloader::fetchHtml(const QUrl &url) {
    baseUrl = url;
    QNetworkRequest request(url);
    manager.get(request);
}

void Downloader::onReplyFinished(QNetworkReply *reply) {
    QUrl url = reply->url();
    if (reply->error() != QNetworkReply::NoError) {
        //emit errorOccurred("Error al descargar " + url.toString() + ": " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    QString mimeType = reply->header(QNetworkRequest::ContentTypeHeader).toString();

    if (mimeType.contains("text/html")) {
        QString html = QString::fromUtf8(data);
        emit htmlFetched(html);
        if (!mainHtmlFetched) {
            mainHtmlFetched = true;
            parseAndDownloadResources(html);
        }
    } else {
        QString filename = QFileInfo(url.path()).fileName();
        if (filename.isEmpty()) filename = "resource";

        QFile file(downloadDirectory + "/" + filename);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(data);
            file.close();
            emit downloadCompleted(file.fileName());
        } else {
            emit errorOccurred("No se pudo guardar " + file.fileName());
        }
    }

    reply->deleteLater();
}

void Downloader::parseAndDownloadResources(const QString &html) {
    QRegularExpression re(R"((?:src|href)\s*=\s*["']([^"']+)["'])");
    QRegularExpressionMatchIterator it = re.globalMatch(html);
    while (it.hasNext()) {
        auto match = it.next();
        QString path = match.captured(1);
        QUrl fullUrl = baseUrl.resolved(QUrl(path));
        downloadResource(fullUrl);
    }
}

void Downloader::downloadResource(const QUrl &resourceUrl) {
    QNetworkRequest request(resourceUrl);
    manager.get(request);
}
