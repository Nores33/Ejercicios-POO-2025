#include <QJsonDocument>
#include <QJsonObject>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    setWindowTitle("Login");

    connect( ui->Cancel_Button, SIGNAL(pressed()), this, SLOT(slot_cancelar()));
    connect(ui->Login_Button, SIGNAL(pressed()), this, SLOT(slot_login()));

    ui->temp->setText("Cargando temperatura...");
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::procesarRespuesta);
    obtenerTemperatura();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_cancelar()
{
    QApplication::quit();
}

void MainWindow::slot_login()
{
    if(ui->user->text() == "admin" && ui->password->text() == "1234") {
        if(!ventanaSecundaria){
            ventanaSecundaria = new ventana_secundaria;
        }
        ventanaSecundaria->show();
        this->hide();
    }
}

void MainWindow::obtenerTemperatura()
{
    QString url = "https://api.open-meteo.com/v1/forecast?latitude=-31.4167&longitude=-64.1833&current_weather=true";
    manager->get(QNetworkRequest(QUrl(url)));
}

void MainWindow::procesarRespuesta(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        ui->temp->setText("Error");
        reply->deleteLater();
        return;
    }

    QByteArray respuesta = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(respuesta);
    QJsonObject obj = jsonDoc.object();

    if (obj.contains("current_weather")) {
        QJsonObject weather = obj["current_weather"].toObject();
        double temp = weather["temperature"].toDouble();
        ui->temp->setText(QString("Temperatura: %1 °C").arg(temp));
    } else {
        ui->temp->setText("Error");
    }

    reply->deleteLater();
}
