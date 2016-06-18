#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T15:51:58
#
#-------------------------------------------------

QT       += core gui
CONFIG+=C++11 console debug
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyEFC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        filepool.cpp\
        zippedbuffer.cpp\
        zippedbufferpool.cpp\
    zipper.cpp \
    epsifilecompressor.cpp \
    writer.cpp \
    ecfwindow.cpp \
    uncompresswindow.cpp

HEADERS  += mainwindow.h\
          filepool.h\
          zippedbuffer.h\
          zippedbufferpool.h\
    zipper.h \
    epsifilecompressor.h \
    writer.h \
    ecfwindow.h \
    uncompresswindow.h

FORMS    += \
    ecfwindow.ui \
    uncompresswindow.ui
