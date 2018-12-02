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
    vdslframe.cpp \
    Ports/stringinput.cpp \
    Ports/stringoutput.cpp \
    Ports/port.cpp \
    Ports/connector.cpp \
    Ports/input.cpp \
    Ports/output.cpp \
    Modules/module.cpp \
    Ports/integerinput.cpp \
    Ports/integeroutput.cpp \
    Ports/floatinput.cpp \
    Ports/floatoutput.cpp \
    Modules/Math/Float/addfloat.cpp \
    Modules/String/concatenate.cpp \
    Modules/String/stringinputfield.cpp \
    Modules/String/stringprinter.cpp \
    Modules/Convert/stringtofloat.cpp \
    Modules/Convert/floattostring.cpp \
    Modules/Math/Float/wavegenerator.cpp \
    Modules/Visualization/Graph/linegraph.cpp \
    Modules/Visualization/Graph/linegraphdisplay.cpp \
    Modules/moduletreewidgetitem.cpp \
    vdslframeoverlay.cpp \
    Modules/Math/Float/multiplyfloat.cpp \
    Modules/Math/Float/roundfloat.cpp

HEADERS += \
        vdsl.h \
    vdslframe.h \
    Ports/port.h \
    Ports/stringinput.h \
    Ports/stringoutput.h \
    Ports/connector.h \
    Ports/input.h \
    Ports/output.h \
    Modules/module.h \
    Ports/integerinput.h \
    Ports/integeroutput.h \
    Ports/floatinput.h \
    Ports/floatoutput.h \
    Modules/Math/Float/addfloat.h \
    Modules/String/concatenate.h \
    Modules/String/stringinputfield.h \
    Modules/String/stringprinter.h \
    Modules/Convert/stringtofloat.h \
    Modules/Convert/floattostring.h \
    Modules/Math/Float/wavegenerator.h \
    Modules/Visualization/Graph/linegraph.h \
    Modules/Visualization/Graph/linegraphdisplay.h \
    Modules/moduletreewidgetitem.h \
    vdslframeoverlay.h \
    Modules/Math/Float/multiplyfloat.h \
    Modules/Math/Float/roundfloat.h

FORMS += \
        vdsl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
