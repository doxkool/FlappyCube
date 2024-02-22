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
		Data.texture = "Game/Textures/Default_Tex.jpg";

		scene->Player_Entities_Data.push_back(Data);
	}

	void Player::SetPosition(glm::vec3 position, Scene* scene)
	{
		Data.position = position;

		PushDataToScene(scene);
	}

	void Player::SetRotation(glm::vec3 rotation, Scene* scene)
	{
		Data.rotation = rotation;

		PushDataToScene(scene);
	}

	void Player::SetScale(glm::vec3 scale, Scene* scene)
	{
		Data.scale = scale;

		PushDataToScene(scene);
	}

	void Player::SetName(const char* name, Scene* scene)
	{
		Data.name = name;

		PushDataToScene(scene);

		LOG_TRACE("Entity ID {} name updated : {}", ID, Data.name);
	}

	void Player::SetTexture(const char* texture, Scene* scene)
	{
		Texture tex(texture);
		Data.texture = tex;

		PushDataToScene(scene);
	}

	void Player::SetMesh(Quad quad, Scene* scene)
	{
		Data.mesh = quad;

		PushDataToScene(scene);
	}

	void Player::Move(glm::vec3 translation, glm::vec3 oriantation)
	{

	}

	void Player::PushDataToScene(Scene* scene)
	{
		scene->Player_Entities_Data[ID - 1] = Data;
	}
}