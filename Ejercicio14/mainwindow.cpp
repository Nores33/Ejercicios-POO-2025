#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pintura.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("QT Paint");

    Pintura *pintura = new Pintura(this);
    setCentralWidget(pintura);
}

MainWindow::~MainWindow()
{
    delete ui;
}
