#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>

class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = nullptr);
    void fetchHtml(const QUrl& url);
    void setDownloadDirectory(const QString& dir);

signals:
    void htmlFetched(const QString& html);
    void downloadCompleted(const QString& filePath);
    void errorOccurred(const QString& message);

private slots:
    void onReplyFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager manager;
    QString downloadDirectory;
    QUrl baseUrl;
    bool mainHtmlFetched;

    void parseAndDownloadResources(const QString& html);
    void downloadResource(const QUrl& resourceUrl);
};

#endif // DOWNLOADER_H
