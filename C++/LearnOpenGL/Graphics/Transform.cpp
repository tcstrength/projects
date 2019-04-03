#include "Transform.h"

namespace graphics {

glm::mat4 Transform::m_2DProjection;
glm::mat4 Transform::m_3DProjection;

void Transform::updateProjection(const float& width, const float& height)
{
    m_2DProjection = glm::ortho( 0.f, width, height, 0.f, -1.0f, 1.0f);
    m_3DProjection = glm::perspective(30.f, width / height, 0.1f, 1000.f);
}

const glm::mat4& Transform::transform(const glm::mat4& view,
                                      const glm::vec2& position,
                                      const glm::vec2& size,
                                      const float& angleRad)
{
    static glm::mat4 Imatrix(1.f);
    static glm::mat4 model;

    model = glm::translate(Imatrix, glm::vec3(position, 0.0f));
    model = glm::rotate(model, angleRad, glm::vec3(0.f, 0.f, 1.f));
    model = glm::scale(model, glm::vec3(size, 1.f));
    model = m_2DProjection * view * model;

    return model;
}

const glm::mat4& Transform::transform(const glm::mat4& view,
                                      const glm::vec3& position,
                                      const glm::vec3& size,
                                      const float& angleRad)
{
    static glm::mat4 Imatrix(1.f);
    static glm::mat4 model;

    model = glm::translate(Imatrix, position);
    model = glm::rotate(model, glm::radians(180.f), glm::vec3(1.f, 0.f, 0.f));
    model = glm::rotate(model, glm::radians(180.f) + angleRad, glm::vec3(0.f, 1.f, 0.f));
    model = glm::scale(model, size);
    model = m_3DProjection * view * model;

    return model;
}

const glm::mat4& Transform::getDefaultView()
{
    static glm::mat4 view(1.f);
    return view;
}

}
