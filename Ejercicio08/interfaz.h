#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>

namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = nullptr);
    ~Interfaz();

private:
    Ui::Interfaz *ui;
};

#endif // INTERFAZ_H
