#pragma once

#include <GL/glew.h>

namespace FlappyCube
{
	class VertexArray
	{
	public:
		VertexArray();
		virtual ~VertexArray();

		void Bind();
		void Unbind();

	private:
		// ID reference for the Vertex Array Object
		GLuint ID;
	};
}