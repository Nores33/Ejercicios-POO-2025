#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "ventana_secundaria.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ventana_secundaria *ventanaSecundaria = nullptr;

    QNetworkAccessManager *manager;

    void obtenerTemperatura();

private slots:
    void slot_cancelar();
    void slot_login();
    void procesarRespuesta(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
