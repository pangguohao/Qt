TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui
CONFIG += c++11


SOURCES += \
        main.cpp \
        singleton.cpp

HEADERS += \
    singleton.h
