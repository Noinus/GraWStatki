TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ui.cpp \
    ai.cpp \
    core.cpp \
    list.cpp

HEADERS += \
    ai.h \
    ui.h \
    core.h \
    ship.h \
    list.h \
    debug.h
