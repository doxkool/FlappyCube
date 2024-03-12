#pragma once

#include "Core/VertexArray.h"
#include "Buffers/ElementBuffer.h"

#include "Core/Texture.h"
#include "Core/Shader.h"
#include "Core/Primitives.h"

#include <glm.hpp>

namespace Engine
{
	class Renderer2D
	{
	public:
		static void Init();

		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color);
		static void DrawQuad(const glm::mat4& transform, const Texture& texture);

	private:
		Quad quad;

	};
}
