QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beacon.cpp \
    beacons.cpp \
    block.cpp \
    layout.cpp \
    line.cpp \
    lineselect.cpp \
    main.cpp \
    station.cpp \
    switch.cpp \
    trackmodel.cpp \
    train.cpp \
    trainmodel.cpp \
    wayside.cpp

HEADERS += \
    beacon.h \
    beacons.h \
    block.h \
    layout.h \
    line.h \
    lineselect.h \
    station.h \
    switch.h \
    trackmodel.h \
    train.h \
    trainmodel.h \
    wayside.h

FORMS += \
    beacon.ui \
    lineselect.ui \
    trackmodel.ui \
    trainmodel.ui \
    wayside.ui

TRANSLATIONS += \
    TrackModel_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
