#-------------------------------------------------
#
# Name：  Qt Creator Project Demo
# Author：DT
# Date：  2015-08-24
#
#-------------------------------------------------

QT += core gui

# 若当前QT主版本大于4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Windows平台生成 HelloWorld.exe , linux平台生成 HelloWorld.out
TARGET = HelloWorld

# 当前项目需要编译出来的是可执行文件, 而不是库文件
TEMPLATE = app

# 头文件搜索路径
INCLUDEPATH += E:/BCC/include \
               E:/VC/include

SOURCES += Main.cpp \
           HelloWorld.cpp

HEADERS += HelloWorld.h

# 当前QT工程会使用界面描述文件
FORMS   += HelloWorld.ui

# .rc后缀是图片
RC_FILE += MyIco.rc

# 使用外部库
LIBS    += -LE:/vlc-1.11/sdk/lib

CONFIG  += warn_on debug

# CONFIG的一个典型用法
# if 'debug' option is set for CONFIG
CONFIG(debug) {
    DEFINES += DEBUG_LOG
    SOURCES += DebugLog.cpp
    HEADERS += DebugLog.h
}