#-------------------------------------------------
#
# Project created by QtCreator 2019-03-30T17:20:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hik_vision
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    wroker.cpp

HEADERS  += mainwindow.h \
    wroker.h

FORMS    += mainwindow.ui

LIBS += `pkg-config --libs opencv`

#LIBS += -L $Hik_vision/include -lMvCameraControl

QMAKE_RPATHDIR += /home/pcspl/Hik_vision/lib/64/

#INCLUDEPATH += include/

LIBS += -L/home/pcspl/Hik_vision/lib/64/ -lMvCameraControl

#DEPENDPATH += Hik_vision/include
