#version 330

in vec2 texCoord0;

uniform vec4 objColor;
uniform sampler2D sampler0;

out vec4 fragColor;

void main()
{
    vec4 texColor = objColor * texture(sampler0, texCoord0);
    fragColor = texColor;
}
