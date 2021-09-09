#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T17:07:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 82-1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    MyThread.cpp \
    SyncThread.cpp \
    AsyncThread.cpp

HEADERS += \
    MyThread.h \
    SyncThread.h \
    AsyncThread.h
