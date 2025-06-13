#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Downloader;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartClicked();
    void onSelectDirectory();
    void onHtmlFetched(const QString& html);
    void onDownloadCompleted(const QString& filePath);
    void onErrorOccurred(const QString& message);

private:
    Ui::MainWindow *ui;
    Downloader* downloader;
    QString downloadDir;
};

#endif // MAINWINDOW_H
