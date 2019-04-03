#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

uniform mat4 MVP;

out vec2 texCoord0;

void main()
{
    gl_Position = MVP * vec4(position, 1.0);
    texCoord0 = vec2(texCoord.x, 1.0 - texCoord.y);
}
