#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T23:20:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalProcessingWidget
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
        widget.cpp \
    BarChart/BarChart.cpp \
    BarChart/BarItem.cpp \
    Spectrogram/Spectrogram.cpp \
    Spectrogram/XAxisItem.cpp \
    Spectrogram/YAxisItem.cpp \
    Spectrogram/CurveItem.cpp \
    Spectrogram/SpectrogramModel.cpp \
    Spectrogram/SpectrogramController.cpp \
    Spectrogram/BackgroundItem.cpp

HEADERS += \
        widget.h \
    BarChart/BarChart.h \
    BarChart/BarItem.h \
    Spectrogram/Spectrogram.h \
    Spectrogram/XAxisItem.h \
    Spectrogram/YAxisItem.h \
    Spectrogram/CurveItem.h \
    Spectrogram/SpectrogramModel.h \
    Spectrogram/SpectrogramController.h \
    Spectrogram/BackgroundItem.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
