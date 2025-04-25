#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "ventana_secundaria.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;

    ventana_secundaria *ventanaSecundaria = nullptr;

    QNetworkAccessManager *manager;

private slots:
    void slot_cancelar();
    void slot_login();
};
#endif // LOGIN_H
