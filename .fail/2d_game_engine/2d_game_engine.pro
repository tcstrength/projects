TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/Renderers/RoundedRectangleShape.cpp \
    src/Utils/Log.cpp \
    src/Context.cpp \
    src/main.cpp \
    src/Info.cpp \
    src/GUI/Widget.cpp \
    src/GUI/Button.cpp \
    src/GUI/Container.cpp \
    src/Application.cpp

HEADERS += \
    src/Renderers/RoundedRectangleShape.h \
    src/Utils/Log.h \
    src/Context.h \
    src/Config.h \
    src/Info.h \
    src/GUI/Widget.h \
    src/GUI/Button.h \
    src/GUI/Container.h \
    src/Application.h

LIBS += -lsfml-system -lsfml-graphics -lsfml-window
