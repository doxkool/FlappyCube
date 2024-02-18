#pragma once

#include <GL/glew.h>

#include <vector>

namespace Engine
{
	class ElementBuffer
	{
	public:
		// Constructor that generates a Elements Buffer Object and links it to indices
		ElementBuffer(std::vector<GLuint>& indices);

		// Binds the EBO
		void Bind();
		// Unbinds the EBO
		void Unbind();
		// Deletes the EBO
		void Delete();

		// ID reference of Elements Buffer Object
		GLuint ID;

	private:

	};
}