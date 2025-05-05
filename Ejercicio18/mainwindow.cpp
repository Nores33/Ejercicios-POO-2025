#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , gameOver(false)
    , velocidad(5)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(800, 300);

    for (int i = 0; i < 7; ++i) {
        fondo.append(QRect(i * 200, 0, 200, 300));
    }

    cactus.append(QRect(400, 200, 40, 60));
    cactus.append(QRect(800, 200, 40, 60));

    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, SIGNAL(timeout()), this, SLOT(actualizarJuego()));
    timerPrincipal->start(30);

    timerPajaro = new QTimer(this);
    connect(timerPajaro, SIGNAL(timeout()), this, SLOT(crearPajaro()));
    timerPajaro->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QImage background("../../imagenes/fondo.png");
    for (const QRect &rect : fondo) {
        painter.drawImage(rect, background);
    }

    if (gameOver) {
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(rect(), Qt::AlignCenter, "GAME OVER\nPresione R para reiniciar");
        return;
    }

    // Dibujar los cactus
    QImage cactusImage("../../imagenes/cactus.png");
    if (cactusImage.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen de los cactus.";
        return;
    }
    for (const QRect &c : cactus) {
        painter.drawImage(c, cactusImage);
    }

    // Dibujar el TRex
    trex.paint(painter);

    // Dibujar los pájaros
    for (Pajaro *p : pajaros) {
        p->paint(painter);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (gameOver && event->key() == Qt::Key_R) {
        cactus.clear();
        cactus.append(QRect(400, 200, 40, 60));
        cactus.append(QRect(800, 200, 40, 60));
        for (Pajaro *p : pajaros) {
            p->deleteLater();
        }
        pajaros.clear();
        gameOver = false;
        velocidad = 5;
        timerPrincipal->start();
        timerPajaro->start();
        return;
    }

    if (gameOver)
        return;

    switch (event->key()) {
    case Qt::Key_Up:
        trex.saltar();
        break;
    case Qt::Key_Down:
        trex.agacharse();
        break;
    case Qt::Key_Right:
        trex.adelantarse();
        break;
    case Qt::Key_Left:
        trex.frenarse();
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down) {
        trex.levantarse();
    }
}

void MainWindow::actualizarJuego() {
    if (gameOver)
        return;

    for (int i = 0; i < fondo.size(); ++i) {
        fondo[i].moveLeft(fondo[i].x() - velocidad);
        if (fondo[i].x() + fondo[i].width() < 0) {
            fondo[i].moveLeft(width() + 200);
        }
    }
    
    trex.actualizarMovimiento();

    for (int i = 0; i < cactus.size(); ++i) {
        cactus[i].moveLeft(cactus[i].x() - velocidad);
        if (cactus[i].x() + cactus[i].width() < 0) {
            cactus[i].moveLeft(width() + 200);
        }
    }

    for (Pajaro *p : pajaros) {
        if (p->getRect().intersects(trex.getRect())) {
            gameOver = true;
        }
    }

    for (const QRect &c : cactus) {
        if (c.intersects(trex.getRect())) {
            gameOver = true;
        }
    }

    update();
}

void MainWindow::crearPajaro() {
    int altura = QRandomGenerator::global()->bounded(120, 200);
    Pajaro *p = new Pajaro(this, altura);
    connect(p, SIGNAL(salirDePantalla(Pajaro*)), this, SLOT(eliminarPajaro(Pajaro*)));
    pajaros.append(p);
}

void MainWindow::eliminarPajaro(Pajaro *pajaro) {
    pajaros.removeOne(pajaro);
    pajaro->deleteLater();
}
