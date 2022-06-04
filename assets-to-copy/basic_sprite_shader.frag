#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

void main()
{
	vec4 image = texture(texture1, TexCoord);
	FragColor = image;
}
