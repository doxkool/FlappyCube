#pragma once

#include "Scene/Entities/Entity.h"

#include <glm.hpp>

namespace Engine
{
	enum Direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

	class Player : public Entity
	{
		public:
			Player(const char* name, glm::vec3 position, float rotation, glm::vec3 scale, Texture& texture, Scene* scene = NULL);

			void OnUpdate(Window window, TimeStep ts);

			void Move(Direction direction);

		private:
	};

	Player::Player(const char* name, glm::vec3 position, float rotation,  glm::vec3 scale, Texture& texture, Scene* scene)
		: Entity(name, position, rotation, scale, texture, scene)
	{
		Data.type = Ent_Player;
	}

	void Player::OnUpdate(Window window, TimeStep ts)
	{
		if (window.CheckKeyboardInput(GLFW_KEY_W))
		{
			Move(UP);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_A))
		{
			Move(LEFT);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_S))
		{
			Move(DOWN);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_D))
		{
			Move(RIGHT);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_Z))
		{
			Move(FORWARD);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_X))
		{
			Move(BACKWARD);
		}
	}

	void Player::Move(Direction direction)
	{
		Data = m_scene->Entities_Data[ID];

		double DeltaTime = Perf::Get_DeltaTime();

		switch (direction)
		{
		case FORWARD:

			break;
		case BACKWARD:

			break;
		case LEFT:
			Data.position.x -= Data.MovementSpeed * DeltaTime;
			break;
		case RIGHT:
			Data.position.x += Data.MovementSpeed * DeltaTime;
			break;
		case UP:
			Data.position.y += Data.MovementSpeed * DeltaTime;
			break;
		case DOWN:
			Data.position.y -= Data.MovementSpeed * DeltaTime;
			break;
		default:
			break;
		}

		Data.model.UpdateMeshTransform(Data.position, Data.rotation, Data.scale);

		PushDataToScene();
	}
}