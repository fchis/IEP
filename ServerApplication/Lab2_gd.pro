QT += core
QT -= gui

CONFIG += c++11

TARGET = Lab2_gd
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    bcm2835_stub.cpp \
    blink.cpp \
    pin.cpp

HEADERS += \
    bcm2835.h \
    pin.h
