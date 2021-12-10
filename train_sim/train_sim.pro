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
    swtcui.cpp \
    track_layout.cpp \
    trackmodel.cpp \
    train.cpp \
    traincalculate.cpp \
    trainmodel.cpp \
    trainmodelui.cpp \
    trainsimwindow.cpp \
    wayside.cpp \
    waysidecontroller.cpp

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
    swtcui.h \
    track_layout.h \
    trackmodel.h \
    train.h \
    traincalculate.h \
    trainmodel.h \
    trainmodelui.h \
    trainsimwindow.h \
    wayside.h \
    waysidecontroller.h

FORMS += \
    HomepageWindow.ui \
    beacon.ui \
    engineer.ui \
    lineselect.ui \
    mainwindow.ui \
    swtcui.ui \
    trackmodel.ui \
    trainmodel.ui \
    trainmodelui.ui \
    trainsimwindow.ui \
    wayside.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    CtcOffice.pro \
    TrackModel.pro \
    TrackModel.pro \
    sw_track_controller.pro

RESOURCES += \
    resources.qrc \
    resources.qrc \
    track.qrc

DISTFILES += \
    Blue_line_track_layout.csv \
    GreenLine.txt \
    GreenLine_CopyTest.txt \
    GreenLine_Test.csv \
    GreenLine_Test.txt \
    Green_Track_Layout.csv \
    Red_Track_Layout.csv \
    Track Layout & Vehicle Data vF.csv \
    TrackModel.pro.user \
    TrackModel.pro.user.82a18af \
    TrackModel_en_US.ts \
    green_and_red_track_small2.png \
    sw_track_controller.pro.user \
    sw_track_controller.pro.user.9201420 \
    sw_track_controller.pro.user.ce61a0e \
    sw_track_controller.pro.user.e56f879 \
    train_sim.pro.user
