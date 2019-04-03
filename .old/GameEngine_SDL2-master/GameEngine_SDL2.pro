TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/GUI/Widgets/Widget.cpp \
    src/Interfaces/NonCopyable.cpp \
    src/Interfaces/Drawable.cpp \
    src/main.cpp \
    src/Utils/Log.cpp \
    src/GUI/Widgets/Window.cpp \
    src/GUI/Widgets/Text.cpp \
    src/Managers/FontManager.cpp \
    src/GUI/Widgets/Button.cpp \
    src/Managers/TextureManager.cpp \
    src/GUI/Widgets/LineEdit.cpp \
    src/Renderers/ElasticImage.cpp \
    src/Renderers/RenderObject.cpp \
    src/Renderers/Sprite.cpp

HEADERS += \
    src/GUI/Widgets/Widget.h \
    src/Interfaces/NonCopyable.h \
    src/Interfaces/Drawable.h \
    src/GUI/Widgets/Window.h \
    src/GUI/Widgets/Text.h \
    src/Managers/FontManager.h \
    src/GUI/Widgets/Button.h \
    src/Managers/TextureManager.h \
    src/GUI/Widgets/LineEdit.h \
    src/Renderers/ElasticImage.h \
    src/Renderers/RenderObject.h \
    src/Renderers/Sprite.h

LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image
