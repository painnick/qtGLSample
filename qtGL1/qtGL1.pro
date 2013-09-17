#-------------------------------------------------
#
# Project created by QtCreator 2013-09-10T21:23:29
#
#-------------------------------------------------

QT       += core gui opengl xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtGL1
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    myqglviewer.cpp

HEADERS  += mainwindow.h \
    myqglviewer.h

FORMS    += mainwindow.ui

unix: INCLUDEPATH += /usr/local/include/opencv\
    /usr/local/include

LIBS += -lGL -lGLU -lglut -lQGLViewer \
    `pkg-config --libs --cflags opencv`

