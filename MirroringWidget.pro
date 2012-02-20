#-------------------------------------------------
#
# Project created by QtCreator 2012-02-20T16:38:21
#
#-------------------------------------------------

QT       += core gui

TARGET = MirroringWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

win32 {
LIBS += -lUser32
}
