#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T19:37:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myMusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    track.cpp \
    tracklist.cpp

HEADERS  += mainwindow.h \
    track.h \
    tracklist.h

FORMS    += mainwindow.ui
