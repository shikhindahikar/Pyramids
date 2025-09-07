#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
uniform sampler2D bricks;

void main ()
{
	FragColor = texture(bricks, TexCoords);	// Temporarily sandish yellow color
}