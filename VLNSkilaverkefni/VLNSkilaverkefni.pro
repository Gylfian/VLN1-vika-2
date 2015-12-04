QT += core
QT -= gui
QT += sql

TARGET = VLNSkilaverkefni
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    domain.cpp \
    presentation.cpp \
    computerscientist.cpp \
    computer.cpp \
    database.cpp

HEADERS += \
    data.h \
    domain.h \
    presentation.h \
    computerscientist.h \
    computer.h \
    database.h

