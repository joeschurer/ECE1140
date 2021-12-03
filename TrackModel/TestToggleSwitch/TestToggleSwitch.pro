QT += testlib
QT -= gui
QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testtoggleswitch.cpp

DISTFILES += \
    ../GreenLine_CopyTest.txt
