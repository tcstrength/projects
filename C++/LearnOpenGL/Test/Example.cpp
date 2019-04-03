//#include "Graphics/Include.h"
//#include "Entities/Camera.h"
//#include "Events/InputEvent.h"

//int main()
//{
//    graphics::Config config;
//    graphics::Window window(config);
//    graphics::Transformer transf(config);
//    graphics::MVPShader shader;
//    graphics::Texture texture("textures/example.png");
//    graphics::Mesh mesh(graphics::Mesh::quadVertices(),
//                        graphics::Mesh::quadIndices());
//    entities::Camera camera(glm::vec3(0.f, 0.f, 10.f));

//    while (window.isOpen()) {
//        window.clear();
//        shader.bind();

//        camera.setPosition(camera.getPosition() - glm::vec3(0.f, 0.f, 0.01f));

//        texture.bind();
//        mesh.draw();
//        shader.load(
//            transf.transform(
//                camera.getView(),
//                glm::vec3(0.f, 0.f, -1.f),
//                glm::vec3(1.f, 1.f, 1.f),
//                0.5f
//            ),
//            glm::vec4(1.f)
//        );

//        texture.bind();
//        mesh.draw();
//        shader.load(
//            transf.transform(
//                transf.getDefaultView(),
//                glm::vec2(100.f, 100.f),
//                texture.getSize(),
//                0.0f
//            ),
//            glm::vec4(1.f)
//        );

//        window.display();
//    }

//    return 0;
//}
