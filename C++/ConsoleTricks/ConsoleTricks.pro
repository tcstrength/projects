TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    src/Screen.cpp \
    src/Clock.cpp \
    src/Sprite.cpp \
    src/Renderer.cpp

HEADERS += \
    src/Screen.h \
    src/Clock.h \
    src/Sprite.h \
    src/Renderer.h
