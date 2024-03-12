#pragma once

#include "Core/Texture.h"
#include "Core/Model.h"

#include <glm.hpp>

namespace Engine
{
	enum ComponentType
	{
		Transform,
		Sprite2D,
		Collision,
		Camera
	};

	struct IDComponent
	{
		int ID;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
	};

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}
	};

	struct TransformComponent
	{
		glm::mat4 Transform = glm::mat4(1.0f);
		
		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
			: Transform(transform) {}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4&() { return Transform; }
	};

	struct Sprite2DComponent
	{
		glm::vec4 Color = glm::vec4(1.f);

		Sprite2DComponent() = default;
		Sprite2DComponent(const Sprite2DComponent&) = default;
		Sprite2DComponent(glm::vec4 color)
			: Color(color) {}
	};
}