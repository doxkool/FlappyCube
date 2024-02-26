#pragma once

#include "Core/Texture.h"
#include "Core/VertexArray.h"

#include <glm.hpp>

#include <GL/glew.h>

namespace Engine
{
	struct RenderStack
	{
		
	};

	class Renderer2D
	{
		Renderer2D();

		static void RenderSprite(Texture& texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	};
}