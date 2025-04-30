#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QListWidgetItem>
#include "admindb.h"
#include "cajamedicamento.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Ventana;
}
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void onAgregarClicked();
    void onSumarClicked();
    void onCompararClicked();

private:
    Ui::Ventana *ui;
    void actualizarListaCajas();
};

#endif // VENTANA_H
