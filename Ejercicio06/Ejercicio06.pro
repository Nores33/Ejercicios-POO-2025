TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    formulario.cpp \
    login.cpp \
    main.cpp

HEADERS += \
    formulario.h \
    login.h
