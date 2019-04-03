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
    src/Application.cpp \
    src/Context.cpp \
    src/Info.cpp \
    src/main.cpp \
    src/Engines/GameObjects/GameObject.cpp \
    src/Engines/TextureManager.cpp \
    src/Engines/GameEngine.cpp \
    src/Engines/GameHandler.cpp \
    src/Engines/GameObjects/BasicEnemy.cpp \
    src/Utils/Indexer.cpp \
    src/Engines/Effects/FadeIn.cpp \
    src/Engines/Effects/FadeOut.cpp \
    src/Engines/GameObjects/Rifleman.cpp \
    src/Engines/GameObjects/Bullet.cpp

HEADERS += \
    src/GUI/Button.h \
    src/GUI/Container.h \
    src/GUI/Widget.h \
    src/Renderers/RoundedRectangleShape.h \
    src/Utils/Log.h \
    src/Application.h \
    src/Config.h \
    src/Context.h \
    src/Info.h \
    src/Engines/GameObjects/GameObject.h \
    src/Engines/TextureManager.h \
    src/Engines/GameEngine.h \
    src/Engines/GameHandler.h \
    src/Engines/GameObjects/BasicEnemy.h \
    src/Utils/Indexer.h \
    src/Engines/GameObjects/DamageType.h \
    src/Engines/Effects/FadeIn.h \
    src/Engines/Effects/FadeOut.h \
    src/Engines/Effects/EffectObject.h \
    src/Engines/Effects/EffectTick.h \
    src/Engines/GameObjects/Rifleman.h \
    src/Engines/GameObjects/Bullet.h

LIBS += -lsfml-system -lsfml-graphics -lsfml-window
