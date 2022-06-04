#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	vec4 theImage = texture(texture1, TexCoord);
	theImage.rgb *= 0.5;
	FragColor = theImage;
}
