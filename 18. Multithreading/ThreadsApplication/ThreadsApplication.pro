#-------------------------------------------------
#
# Project created by QtCreator 2015-01-03T11:54:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadsApplication
TEMPLATE = app

# needed on OS X 10.9
# otherwise compiler can't find 'TargetConditionals.h'
macx {
QMAKE_MAC_SDK = macosx10.9
}

SOURCES += main.cpp\
    thread.cpp \
    threaddialog.cpp

HEADERS  += \
    thread.h \
    threaddialog.h

FORMS    +=
