# -------------------------------------------------
# Project created by QtCreator 2010-06-05T21:06:22
# -------------------------------------------------
TARGET = xcap
TEMPLATE = app

QXT = gui core
include(xcap.pri)
LIBS += -lQxtCore -lQxtGui 

macx {
    LIBS -= -lQxtCore -lQxtGui
    LIBS += -framework QxtCore -framework QxtGui
}

SOURCES += main.cpp \
    XCap.cpp
HEADERS += XCap.h
CONFIG +=  debug_and_release
RESOURCES += xcap.qrc 
