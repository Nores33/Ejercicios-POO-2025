#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QWidget>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui {
class registrar;
}
QT_END_NAMESPACE

class Registrar : public QWidget
{
    Q_OBJECT

public:
    Registrar(QWidget *parent = nullptr);
    ~Registrar();

private slots:
    void on_signupButton_clicked();
    void on_cancelButton_clicked();
    void onRegisterReply();

private:
    Ui::registrar *ui;
    QNetworkReply *replyActual = nullptr;
};

#endif // REGISTRAR_H
