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
    computer.cpp

HEADERS += \
    data.h \
    domain.h \
    presentation.h \
    computerscientist.h \
<<<<<<< HEAD
    computer.h
=======
    computer.h \
>>>>>>> c9c922024d0711b372082c7ce340c08945fec457

