#include "Scene/Player.h"

namespace Engine
{
	Player::Player(const char* name, Scene* scene)
		: m_scene(scene)
	{
		ID = scene->Player_Entities_Data.size() + 1;

		Data.ID = ID;
		Data.name = name;
		Data.position = glm::vec3(0.f);
		Data.rotation = glm::vec3(0.f);
		Data.scale = glm::vec3(1.f);

		scene->Player_Entities_Data.push_back(Data);
	}

	void Player::SetPosition(glm::vec3 position)
	{
		Data.position = position;

		PushDataToScene();
	}

	void Player::SetRotation(glm::vec3 rotation)
	{
		Data.rotation = rotation;

		PushDataToScene();
	}

	void Player::SetScale(glm::vec3 scale)
	{
		Data.scale = scale;

		PushDataToScene();
	}

	void Player::SetName(const char* name)
	{
		Data.name = name;

		PushDataToScene();

		LOG_TRACE("Entity ID {} name updated : {}", ID, Data.name);
	}

	void Player::SetTexture(const char* texturePath)
	{		
		Data.texturePath = texturePath;

		Texture tex(texturePath);

		Data.textureData = tex;

		PushDataToScene();
	}

	void Player::SetMesh(Quad quad)
	{
		Data.mesh = quad;
		Data.model.LoadMesh(Data.mesh, Data.position, Data.rotation, Data.scale, Data.textureData);

		PushDataToScene();
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

	void Player::PushDataToScene()
	{
		m_scene->Player_Entities_Data[ID - 1] = Data;
	}
}