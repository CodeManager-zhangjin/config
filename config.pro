#-------------------------------------------------
# Project created by QtCreator 2019-04-18T14:53:09
#-------------------------------------------------
QT  -= gui

TARGET = main
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ./include

HEADERS += \
    config.h

SOURCES += \
    config.cpp \
    main.cpp

unix:!macx: LIBS += -L./lib -lconfig++
unix:!macx: PRE_TARGETDEPS += ./lib/libconfig++.a

DISTFILES += \
    example.cfg
