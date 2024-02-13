#define STB_IMAGE_IMPLEMENTATION

#include "Texture.h"

namespace FlappyCube
{
	Texture::Texture(const char* texturePath)
	{
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, this->ID);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;

		unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			LOG_TRACE("Texture loaded : {}", texturePath);
		}
		else
		{
			LOG_ERROR("Failed to load texture");
		}
		stbi_image_free(data);
	}

	Texture::~Texture()
	{
	}

	void Texture::LoadTexture()
	{
		
	}

	void Texture::texUnit(const char* uniform, GLuint unit)
	{
		// Gets the location of the uniform
		GLuint texUni = glGetUniformLocation(Shader::GetID(), uniform);
		// Shader needs to be activated before changing the value of a uniform
		Shader::Activate(); 
		// Sets the value of the uniform
		glUniform1i(texUni, unit);
	}

	void Texture::BindTexture()
	{
		glBindTexture(GL_TEXTURE_2D, this->ID);
	}
}