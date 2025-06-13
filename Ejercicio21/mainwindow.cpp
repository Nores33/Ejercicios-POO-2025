#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), downloader(new Downloader(this))
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->dirButton, &QPushButton::clicked, this, &MainWindow::onSelectDirectory);

    connect(downloader, &Downloader::htmlFetched, this, &MainWindow::onHtmlFetched);
    connect(downloader, &Downloader::downloadCompleted, this, &MainWindow::onDownloadCompleted);
    connect(downloader, &Downloader::errorOccurred, this, &MainWindow::onErrorOccurred);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onSelectDirectory() {
    QString dir = QFileDialog::getExistingDirectory(this, "Seleccione directorio de descarga");
    if (!dir.isEmpty()) {
        downloadDir = dir;
        ui->statusLabel->setText("Directorio: " + dir);
    }
}

void MainWindow::onStartClicked() {
    QUrl url(ui->urlInput->text());
    if (!url.isValid() || url.scheme().isEmpty()) {
        QMessageBox::warning(this, "URL inválida", "Ingrese una URL válida (con http:// o https://)");
        return;
    }
    if (downloadDir.isEmpty()) {
        QMessageBox::warning(this, "Directorio no seleccionado", "Seleccione un directorio de descarga primero");
        return;
    }
    downloader->setDownloadDirectory(downloadDir);
    downloader->fetchHtml(url);
}

void MainWindow::onHtmlFetched(const QString &html) {
    ui->statusLabel->setText("HTML descargado, buscando recursos...");
}

void MainWindow::onDownloadCompleted(const QString &filePath) {
    ui->statusLabel->setText("Descargado: " + filePath);
}

void MainWindow::onErrorOccurred(const QString &message) {
    QMessageBox::critical(this, "Error", message);
}
