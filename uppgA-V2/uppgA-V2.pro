TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../uppgA/Cellphone.cpp \
    ../uppgA/CellphoneHandler.cpp

HEADERS += \
    ../uppgA/Cellphone.h \
    ../uppgA/CellphoneHandler.h
