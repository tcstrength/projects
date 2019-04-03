cmake_minimum_required(VERSION 2.8)

project(thinmatrix_opengl)

set(SOURCE_FILES
    "src/main.cpp"
    "src/RenderEngine/Display.cpp"
    "src/RenderEngine/RawModel.cpp"
    "src/RenderEngine/Renderer.cpp"
    "src/RenderEngine/Config.cpp"
    "src/Utils/Log.cpp"
    "src/Utils/Misc.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -lglfw -lGL -lGLEW -lassimp -lSOIL)
