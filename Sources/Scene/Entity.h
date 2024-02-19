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

			//Base_Entity Data;

		private:

	};

	struct Base_Entity
	{
		const char* name;

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};

	struct Player_Entity : Base_Entity
	{
		Texture texture;
		Quad mesh;
	};
}