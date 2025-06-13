TEMPLATE = app

QT = core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    ventana.cpp

HEADERS += \
    ventana.h
