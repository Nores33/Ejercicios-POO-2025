#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_LoginButton_clicked();
    void on_SignUpButton_clicked();
    void onLoginReply();

private:
    Ui::Login *ui;
    QNetworkReply *replyActual = nullptr;
};
#endif // LOGIN_H
