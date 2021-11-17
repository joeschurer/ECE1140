QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CtcOffice.cpp \
    PLC.cpp \
    beacon.cpp \
    beacons.cpp \
    block.cpp \
    engineer.cpp \
    homepagewindow.cpp \
    layout.cpp \
    line.cpp \
    lineselect.cpp \
    main.cpp \
    mainwindow.cpp \
    station.cpp \
    switch.cpp \
    swtraincontrollerui.cpp \
    topwindow.cpp \
    track_layout.cpp \
    trackmodel.cpp \
    train.cpp \
    trainmodel.cpp \
    wayside.cpp

HEADERS += \
    CtcOffice.h \
    PLC.h \
    beacon.h \
    beacons.h \
    block.h \
    engineer.h \
    homepagewindow.h \
    layout.h \
    line.h \
    lineselect.h \
    mainwindow.h \
    models.h \
    station.h \
    switch.h \
    swtraincontrollerui.h \
    topwindow.h \
    track_layout.h \
    trackmodel.h \
    train.h \
    trainmodel.h \
    wayside.h

FORMS += \
    HomepageWindow.ui \
    beacon.ui \
    engineer.ui \
    lineselect.ui \
    mainwindow.ui \
    swtraincontrollerui.ui \
    topwindow.ui \
    trackmodel.ui \
    trainmodel.ui \
    wayside.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
