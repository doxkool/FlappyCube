#include "Core/VertexArray.h"

namespace Engine
{
	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &ID);
	}

	VertexArray::~VertexArray()
	{
	}

	void VertexArray::LinkAttrib(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
	{
		VBO.Bind();
		glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(layout);
		VBO.Unbind();
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(ID);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}
}