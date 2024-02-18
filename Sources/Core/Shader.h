#pragma once

#include "Core/Logger.h"

#include <GL/glew.h>

#include <glm.hpp>
#include <gtc/type_ptr.hpp>

namespace Engine
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		static void Init(const char* vertexShaderFile, const char* fragmentShaderFile);

		static std::string ReadShaderFile(const char* ShaderFile);

		static void Activate();
		static void Delete();

		static void set1i(GLint value, const GLchar* name);
		static void set1f(GLfloat value, const GLchar* name);
		static void setVec2f(glm::fvec2 value, const GLchar* name);
		static void setVec3f(glm::fvec3 value, const GLchar* name);
		static void setVec4f(glm::fvec4 value, const GLchar* name);
		static void setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE);
		static void setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE);

		static int GetID();

	private:
		//static GLuint ID;
	};
}