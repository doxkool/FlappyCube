#pragma once

#include "Buffers/VertexBuffer.h"
#include "Buffers/ElementBuffer.h"

#include <GL/glew.h>

namespace FlappyCube
{
	class VertexArray
	{
	public:
		VertexArray();
		virtual ~VertexArray();

		// Links a VBO Attribute such as a position or color to the VAO
		void LinkAttrib(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

		void Bind();
		void Unbind();

	private:
		// ID reference for the Vertex Array Object
		GLuint ID;
	};
}