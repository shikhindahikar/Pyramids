

#version 330 core

out vec4 FragColor;

in float Height;

void main()
{
    float h = (Height + 16)/32.0f;	// shift and scale the height into a grayscale value
    // Darkest RGB is supposed to be 0.8 0.541 0.262
    FragColor = vec4(h * 0.8, h * 0.541, h * 0.262, 1.0);
}

