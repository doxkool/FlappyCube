#pragma once

#include "Window/Window.h"

#include "Core/Texture.h"
#include "Core/Primitives.h"
#include "Core/Model.h"
#include "Core/TimeStep.h"

#include <glm.hpp>

namespace Engine
{
	enum EntityType { Ent_Base = 0, Ent_Player, Ent_Square2D };

	struct Base_Entity
	{
		unsigned int ID = -1;
		EntityType type = Ent_Base;
		const char* name = "Entity";
		glm::vec3 position = glm::vec3(0);
		glm::vec3 rotation = glm::vec3(0);
		glm::vec3 scale = glm::vec3(1);
		bool lockScaleRatio = true;

		const char* texturePath = "Game/Textures/Default_Tex.jpg";
		Texture textureData;

		Primitive mesh;
		Model model;

		float MovementSpeed = 5;
		bool GeneratePhysOverlap = false;
	};

	struct Sprite2D : Base_Entity
	{

	};
}