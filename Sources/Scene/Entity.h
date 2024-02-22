#pragma once

#include "Core/Texture.h"
#include "Core/Primitives.h"

#include <glm.hpp>

namespace Engine
{
	class Entity
	{
		public:
			Entity() = default;

		private:

	};

	struct Base_Entity
	{
		unsigned int ID = -1;
		const char* name = "Entity";
		glm::vec3 position = glm::vec3(0.f);
		glm::vec3 rotation = glm::vec3(0.f);
		glm::vec3 scale = glm::vec3(1.f);
	};

	struct Player_Entity : Base_Entity
	{
		Texture texture;
		Quad mesh;
	};
}