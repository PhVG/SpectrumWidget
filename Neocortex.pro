#-------------------------------------------------
#
# Project created by QtCreator 2017-07-15T11:22:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Neocortex
TEMPLATE = app


SOURCES += \
    main.cpp\
    spectrumwidget.cpp \
    mainwidget.cpp \
    controlwidget.cpp

HEADERS  += \
    spectrumwidget.h \
    mainwidget.h \
    controlwidget.h

FORMS    += \
    spectrumwidget.ui \
    mainwidget.ui \
    controlwidget.ui

CONFIG += c++11
