#ifndef LOGINDESIGNER_H
#define LOGINDESIGNER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDesigner;
}
QT_END_NAMESPACE

class LoginDesigner : public QWidget
{
    Q_OBJECT

public:
    LoginDesigner(QWidget *parent = nullptr);
    ~LoginDesigner();

private:
    Ui::LoginDesigner *ui;

private slots:
    void slot_validarUsuario();

};
#endif // LOGINDESIGNER_H
