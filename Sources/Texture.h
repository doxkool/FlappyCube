#pragma once

#include "Logger.h"
#include "Primitives.h"
#include "Shader.h"

#include <GL/glew.h>
#include <stb_image.h>

#include <filesystem>
#include <string>

namespace FlappyCube
{
	class Texture
	{
	public:
		Texture(const char* texturePath);
		~Texture();

		void LoadTexture();

		void texUnit(const char* uniform, GLuint unit);

		void BindTexture();

		GLuint ID;

	private:
		
	};
}