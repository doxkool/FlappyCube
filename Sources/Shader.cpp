#include "Shader.h"


namespace FlappyCube
{
	GLuint ID;

	std::string Shader::ReadShaderFile(const char* ShaderFile)
	{
		std::string temp = "";
		std::string src = "";

		std::ifstream in_file;

		//Vertex
		in_file.open(ShaderFile);

		if (in_file.is_open())
		{
			while (std::getline(in_file, temp))
				src += temp + "\n";
		}
		else
		{
			LOG_ERROR("ERROR::SHADER::COULD_NOT_OPEN_FILE: {}", ShaderFile);
		}

		in_file.close();

		return src;
	}

	Shader::Shader()
	{
	}

	Shader::~Shader()
	{
	}

	void Shader::Init(const char* vertexShaderFile, const char* fragmentShaderFile)
	{

		std::string str_src;
		const GLchar* src;

		// build and compile our shader program
		// ------------------------------------
		// vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		str_src = ReadShaderFile(vertexShaderFile);
		src = str_src.c_str();
		glShaderSource(vertexShader, 1, &src, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			LOG_DEBUG("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
			LOG_DEBUG(infoLog);
		}
		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		str_src = ReadShaderFile(fragmentShaderFile);
		src = str_src.c_str();
		glShaderSource(fragmentShader, 1, &src, NULL);
		glCompileShader(fragmentShader);
		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			LOG_DEBUG("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
			LOG_DEBUG(infoLog);
		}
		// link shaders
		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);
		// check for linking errors
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			LOG_DEBUG("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
			LOG_DEBUG(infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	// Activates the Shader Program
	void Shader::Activate()
	{
		glUseProgram(ID);
	}

	// Deletes the Shader Program
	void Shader::Delete()
	{
		LOG_TRACE("Deleting shader program...");
		glDeleteProgram(ID);
	}

	void Shader::set1i(GLint value, const GLchar* name)
	{
		glUniform1i(glGetUniformLocation(ID, name), value);
	}

	void Shader::set1f(GLfloat value, const GLchar* name)
	{
		glUniform1f(glGetUniformLocation(ID, name), value);
	}

	void Shader::setVec2f(glm::fvec2 value, const GLchar* name)
	{
		glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
	}

	void Shader::setVec3f(glm::fvec3 value, const GLchar* name)
	{
		glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
	}

	void Shader::setVec4f(glm::fvec4 value, const GLchar* name)
	{
		glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
	}

	void Shader::setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose)
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, transpose, glm::value_ptr(value));
	}

	void Shader::setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, transpose, glm::value_ptr(value));
	}

	int Shader::GetID()
	{
		return ID;
	}
}