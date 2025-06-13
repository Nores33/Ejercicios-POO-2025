#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QColor>

class Boton : public QWidget
{
    Q_OBJECT

public:
    enum Color {
        Rojo,
        Magenta,
        Violeta,
        Azul,
        Verde
    };

    explicit Boton(QWidget *parent = nullptr);

    void colorear(Color color);

signals:
    void signal_clic();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QColor colorActual;
};

#endif // BOTON_H
