#pragma once
#include <memory>
#include <string>
#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Pyramid {
	public:
		Pyramid(std::string texFileName, int width, int height, int nrChannels) : tex_width(width), tex_height(height), tex_nrChannels(nrChannels) {
			texData.reset(stbi_load(texFileName.c_str(), &tex_width, &tex_height, &tex_nrChannels, 0));
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenTextures(1, &tex);
		}

		void initBuffer() {
			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void pointData() {}
	private:
		//triangle and texture coords
		const float vertices[90] = {
			//triangle ODA      //textures
			0.0f, 0.5f, 0.0f,   0.5f, 1.0f,
			-0.5f, 0.0f, 0.5f,  1.0f, 0.0f,
			-0.5f, 0.0f, -0.5f, 0.0f, 0.0f,
			//triangle OCD
			0.0f, 0.5f, 0.0f,   0.5f, 1.0f,
			0.5f, 0.0f, 0.5f,   1.0f, 0.0f,
			-0.5f, 0.0f, 0.5f,  0.0f, 0.0f,
			//triangle OBC
			0.0f, 0.5f, 0.0f,   0.5f, 1.0f,
			0.5f, 0.0f, -0.5f,  1.0f, 0.0f,
			0.5f, 0.0f, 0.5f,   0.0f, 0.0f,
			//triangle OAB
			0.0f, 0.5f, 0.0f,   0.5f, 1.0f,
			-0.5f, 0.0f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.0f, -0.5f,  0.0f, 0.0f,
			//triangle BAC
			0.5f, 0.0f, -0.5f,  0.0f, 0.0f,
			-0.5f, 0.0f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.0f, 0.5f,   0.0f, 0.0f,
			//triangle ADC
			-0.5f, 0.0f, -0.5f, 0.0f, 0.0f,
			-0.5f, 0.0f, 0.5f,  1.0f, 0.0f,
			0.5f, 0.0f, 0.5f,	0.0f, 0.0f
		};
		int tex_width, tex_height, tex_nrChannels;
		std::unique_ptr<uint8_t> texData;
		GLuint VBO, VAO, tex;
};