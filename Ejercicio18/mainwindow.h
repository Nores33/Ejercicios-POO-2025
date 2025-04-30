#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include "trex.h"
#include "pajaro.h"

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


protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void actualizarJuego();
    void crearPajaro();
    void eliminarPajaro(Pajaro *pajaro);

private:
    TRex trex;
    QVector<QRect> cactus;
    QVector<Pajaro*> pajaros;
    QList<QRect> fondo;
    QTimer *timerPrincipal;
    QTimer *timerPajaro;
    bool gameOver;
    int velocidad;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
