#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T15:50:28
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = VDSL
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        vdsl.cpp \
    input.cpp \
    output.cpp \
    transceiver.cpp \
    port.cpp \
    connector.cpp \
    vdslframe.cpp \
    stringoutput.cpp \
    stringinput.cpp

HEADERS += \
        vdsl.h \
    input.h \
    output.h \
    transceiver.h \
    port.h \
    connector.h \
    vdslframe.h \
    stringoutput.h \
    stringinput.h

FORMS += \
        vdsl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
