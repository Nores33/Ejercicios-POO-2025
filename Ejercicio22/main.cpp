#include <QApplication>
#include <QElapsedTimer>
#include <QDebug>
#include "sensor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Cambiado a QApplication

    Sensor sensor;

    const int N = 10'000'000;
    int sumaBruto = 0;
    int sumaBrutoOffline = 0;
    double sumaNorm = 0.0;
    double sumaNormOffline = 0.0;

    QElapsedTimer timer;

    // Benchmark getValorBruto (inline implícito)
    timer.start();
    for (int i = 0; i < N; ++i)
        sumaBruto += sensor.getValorBruto();
    qint64 tiempoBruto = timer.elapsed();
    qDebug() << "getValorBruto() (inline implícito):" << tiempoBruto << "ms";

    // Benchmark getValorBrutoOffline (offline)
    timer.restart();
    for (int i = 0; i < N; ++i)
        sumaBrutoOffline += sensor.getValorBrutoOffline();
    qint64 tiempoBrutoOffline = timer.elapsed();
    qDebug() << "getValorBrutoOffline() (offline):" << tiempoBrutoOffline << "ms";

    // Benchmark getValorNormalizado (inline explícito)
    timer.restart();
    for (int i = 0; i < N; ++i)
        sumaNorm += sensor.getValorNormalizado();
    qint64 tiempoNorm = timer.elapsed();
    qDebug() << "getValorNormalizado() (inline explícito):" << tiempoNorm << "ms";

    // Benchmark getValorNormalizadoOffline (offline)
    timer.restart();
    for (int i = 0; i < N; ++i)
        sumaNormOffline += sensor.getValorNormalizadoOffline();
    qint64 tiempoNormOffline = timer.elapsed();
    qDebug() << "getValorNormalizadoOffline() (offline):" << tiempoNormOffline << "ms";

    // Para evitar optimización del compilador
    qDebug() << "Suma Bruto:" << sumaBruto;
    qDebug() << "Suma Bruto Offline:" << sumaBrutoOffline;
    qDebug() << "Suma Normalizado:" << sumaNorm;
    qDebug() << "Suma Normalizado Offline:" << sumaNormOffline;

    return 0;
}
