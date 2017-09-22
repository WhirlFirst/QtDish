#-------------------------------------------------
#
# Project created by QtCreator 2017-09-04T21:56:19
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = systemUi1
TEMPLATE = app
RC_ICONS = whirl.ico
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
    superuserdialog.cpp \
    adddishdialog.cpp \
    adduserdialog.cpp \
    dishviewdialog.cpp \
    chiefdialog.cpp \
    chefdialog.cpp \
    waiterdialog.cpp \
    addchefdialog.cpp \
    addwaiterdialog.cpp

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
    superuserdialog.h \
    adddishdialog.h \
    adduserdialog.h \
    dishviewdialog.h \
    chiefdialog.h \
    chefdialog.h \
    waiterdialog.h \
    addchefdialog.h \
    addwaiterdialog.h \
    connection.h

FORMS    += mainwindow.ui \
    registerdialog.ui \
    logindialog.ui \
    showdialog.ui \
    uidish.ui \
    uitable.ui \
    paydialog.ui \
    waitdialog.ui \
    uratingdish.ui \
    superuserdialog.ui \
    adddishdialog.ui \
    adduserdialog.ui \
    dishviewdialog.ui \
    chiefdialog.ui \
    chefdialog.ui \
    waiterdialog.ui \
    addchefdialog.ui \
    addwaiterdialog.ui

RESOURCES += \
    myicon.qrc
