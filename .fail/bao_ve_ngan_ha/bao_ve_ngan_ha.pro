TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/GUI/Button.cpp \
    src/GUI/Container.cpp \
    src/GUI/Widget.cpp \
    src/Renderers/RoundedRectangleShape.cpp \
    src/Utils/Log.cpp \
    src/Context.cpp \
    src/Info.cpp \
    src/main.cpp \
    src/Objects/Player.cpp \
    src/Objects/GameObject.cpp \
    src/Managers/TextureManager.cpp \
    src/Objects/ObjectGroup.cpp \
    src/GameEngine.cpp

HEADERS += \
    src/GUI/Button.h \
    src/GUI/Container.h \
    src/GUI/Widget.h \
    src/Renderers/RoundedRectangleShape.h \
    src/Utils/Log.h \
    src/Config.h \
    src/Context.h \
    src/Info.h \
    src/Objects/Player.h \
    src/Objects/GameObject.h \
    src/Objects/GameObjectType.h \
    src/Managers/TextureManager.h \
    src/Objects/ObjectGroup.h \
    src/GameEngine.h

LIBS += -lsfml-system -lsfml-window -lsfml-graphics
