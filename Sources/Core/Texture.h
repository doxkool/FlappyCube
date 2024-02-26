#pragma once

#include "Core/Logger.h"
#include "Core/Primitives.h"
#include "Core/Shader.h"

#include <GL/glew.h>
#include <stb_image.h>

#include <filesystem>
#include <string>

namespace Engine
{
	class Texture
	{
	public:
		Texture(const char* texturePath = NULL);
		~Texture();

		void texUnit(const char* uniform, GLuint unit);

		void BindTexture();

		GLuint ID;

	private:
		
	};
}