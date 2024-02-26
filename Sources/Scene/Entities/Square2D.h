#pragma once

#include "Scene/Scene.h"
#include "Scene/Entities/Entity.h"

#include <glm.hpp>

namespace Engine
{
	class Square2D	: public Entity
	{
	public:
		Square2D(const char* name, glm::vec3 position, Texture& texture, Scene* scene = NULL);

		~Square2D() {};

	private:
	};

	Square2D::Square2D(const char* name, glm::vec3 position, Texture& texture, Scene* scene)
		: Entity(name, position, texture, scene)
	{
		Data.type = Ent_Square2D;
	}
}