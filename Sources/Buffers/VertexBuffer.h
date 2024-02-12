#pragma once

#include <GL/glew.h>

#include <glm.hpp>
#include <vector>

#include <cstdint>

namespace FlappyCube
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 texCoords;
	};

	class  VertexBuffer
	{
	public:
		VertexBuffer(uint32_t size);
		~VertexBuffer();

		void Bind();
		void Unbind();

		//virtual void SetData(const void* data, uint32_t size) override;

	private:
		uint32_t ID;
	};
}