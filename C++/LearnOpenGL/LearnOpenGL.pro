TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Graphics/Window.cpp \
    Graphics/Config.cpp \
    Utils/Log.cpp \
    Graphics/Shaders/Shader.cpp \
    Graphics/Shaders/MVPShader.cpp \
    Graphics/Mesh.cpp \
    Graphics/Texture.cpp \
    Graphics/Transform.cpp \
    Entities/Camera.cpp \
    Events/InputEvent.cpp \
    Events/EventSignal.cpp \
    Test/TestEvent.cpp \
    Test/Example.cpp \
    Graphics/Model.cpp \
    Utils/Misc.cpp \

HEADERS += \
    Graphics/Window.h \
    Graphics/Config.h \
    Utils/Log.h \
    Graphics/Shaders/Shader.h \
    Graphics/Shaders/MVPShader.h \
    Graphics/Include.h \
    Graphics/Mesh.h \
    Graphics/Texture.h \
    Graphics/Vertex.h \
    Graphics/Transform.h \
    Entities/Camera.h \
    Events/InputEvent.h \
    Events/EventSignal.h \
    Events/EventData.h \
    Events/EventType.h \
    Test/TestEvent.h \
    Graphics/Model.h \
    Utils/Misc.h \

LIBS += -lglfw -lGL -lGLEW -lSOIL -lassimp
