#-------------------------------------------------
#
# Project created by QtCreator 2013-09-23T23:39:27
#
#-------------------------------------------------

QT       += core gui opengl xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtGL2
TEMPLATE = app


SOURCES += main.cpp \
    multiView.cpp

HEADERS  += \
    multiView.h

unix: INCLUDEPATH += /usr/local/include/opencv\
    /usr/local/include

LIBS += -lGL -lGLU -lglut -lQGLViewer \
    `pkg-config --libs --cflags opencv`

