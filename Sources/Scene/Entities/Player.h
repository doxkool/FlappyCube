#pragma once

#include "Scene/Entities/Entity.h"

#include <glm.hpp>

namespace Engine
{
	enum Direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

	class Player : public Entity
	{
		public:
			Player(const char* name, Scene* scene = NULL);

			void OnUpdate(Window window, TimeStep ts);

			void Move(Direction direction);

		private:
	};

	Player::Player(const char* name, Scene* scene)
		: Entity(name, scene)
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
		switch (direction)
		{
		case FORWARD:

			break;
		case BACKWARD:

			break;
		case LEFT:
			Data.position.x -= Data.MovementSpeed;
			break;
		case RIGHT:
			Data.position.x += Data.MovementSpeed;
			break;
		case UP:
			Data.position.y += Data.MovementSpeed;
			break;
		case DOWN:
			Data.position.y -= Data.MovementSpeed;
			break;
		default:
			break;
		}

		Data.model.UpdateMeshPosition(Data.position);

		PushDataToScene();
	}
}