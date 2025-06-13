#include "logindesigner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDesigner w;
    w.show();
    return a.exec();
}
