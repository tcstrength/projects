TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Runtime.cpp

LIBS += -lpthread -lSDL2

HEADERS += \
    Runtime.h
