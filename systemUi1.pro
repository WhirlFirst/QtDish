#-------------------------------------------------
#
# Project created by QtCreator 2017-09-04T21:56:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = systemUi1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    registerdialog.cpp \
    logindialog.cpp \
    showdialog.cpp \
    logic.cpp \
    uidish.cpp \
    uitable.cpp \
    paydialog.cpp \
    waitdialog.cpp \
    uratingdish.cpp \
    superuserdialog.cpp

HEADERS  += mainwindow.h \
    registerdialog.h \
    logindialog.h \
    showdialog.h \
    logic.h \
    uidish.h \
    uitable.h \
    paydialog.h \
    waitdialog.h \
    uratingdish.h \
    superuserdialog.h

FORMS    += mainwindow.ui \
    registerdialog.ui \
    logindialog.ui \
    showdialog.ui \
    uidish.ui \
    uitable.ui \
    paydialog.ui \
    waitdialog.ui \
    uratingdish.ui \
    superuserdialog.ui

RESOURCES += \
    myicon.qrc
