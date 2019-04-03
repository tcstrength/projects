#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace graphics {

class Transform
{
public:
    static void updateProjection(const float& width, const float& height);

    static
    const glm::mat4& transform(const glm::mat4& view,
                               const glm::vec2& position,
                               const glm::vec2& size,
                               const float& angleRad);
    static
    const glm::mat4& transform(const glm::mat4& view,
                               const glm::vec3& position,
                               const glm::vec3& size,
                               const float& angleRad);

    static
    const glm::mat4& getDefaultView();
private:
    static glm::mat4 m_2DProjection;
    static glm::mat4 m_3DProjection;
};

}
#endif // TRANSFORM_H
