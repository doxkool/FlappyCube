#include "Scene/Player.h"

namespace Engine
{
	Player::Player(const char* name, Scene* scene)
	{
		ID = scene->Player_Entities_Data.size() + 1;
		Data.name = name;

		scene->Player_Entities_Data.push_back(Data);
	}

	void Player::SetName(const char* name, Scene* scene)
	{
		Data.name = name;

		scene->Player_Entities_Data[0] = Data;

		LOG_TRACE("Entity ID {} name updated : {}", ID, Data.name);
	}

	void Player::SetTexture(const char* texture, Scene* scene)
	{
		Texture tex(texture);
		Data.texture = tex;

		scene->Player_Entities_Data[0] = Data;
	}

	void Player::SetMesh(Quad quad, Scene* scene)
	{
		Data.mesh = quad;

		scene->Player_Entities_Data[0] = Data;
	}

	void Player::Move(glm::vec3 translation, glm::vec3 oriantation)
	{

	}
}