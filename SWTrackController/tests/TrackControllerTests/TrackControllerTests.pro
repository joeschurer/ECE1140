QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_trackcontroller.cpp \
    PLC.cpp \
    track_layout.cpp \
    waysidecontroller.cpp

HEADERS += \
    PLC.h \
    models.h \
    track_layout.h \
    waysidecontroller.h

RESOURCES += \
    resources.qrc
