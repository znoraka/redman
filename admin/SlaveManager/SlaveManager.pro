#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T18:10:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SlaveManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    networkmanager.cpp \
    slaveswindow.cpp \
    console.cpp

HEADERS  += mainwindow.h \
    networkmanager.h \
    slaveswindow.h \
    console.h

FORMS    += mainwindow.ui

QT += widgets network

CONFIG += qt
CONFIG+=c++11

QMAKE_CXXFLAGS += -std=c++11
