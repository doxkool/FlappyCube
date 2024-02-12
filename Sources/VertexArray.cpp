#include "VertexArray.h"

namespace FlappyCube
{
	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &ID);
	}

	VertexArray::~VertexArray()
	{
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