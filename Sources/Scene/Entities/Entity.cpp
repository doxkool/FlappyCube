#include "Scene/Entities/Entity.h"

namespace Engine
{
	Entity::Entity(const char* name, Scene* scene)
		: m_scene(scene)
	{
		ID = scene->Entities_Data.size() + 1;

		Data.ID = ID;
		Data.name = name;
		Data.position = glm::vec3(0.f);
		Data.rotation = glm::vec3(0.f);
		Data.scale = glm::vec3(1.f);

		scene->Entities_Data.push_back(Data);

		LOG_TRACE("New entity created :\n- ID : {}\n- Name : {}", Data.ID, Data.name);
	}

	void Entity::OnUpdate(Window window, TimeStep ts)
	{

	}

	void Entity::SetName(const char* name)
	{
		Data.name = name;

		PushDataToScene();

		LOG_TRACE("Entity ID {} name updated : {}", ID, Data.name);
	}

	void Entity::SetTexture(const char* texturePath)
	{
		Data.texturePath = texturePath;

		Texture tex(texturePath);

		Data.textureData = tex;

		PushDataToScene();
	}

	void Entity::SetMesh(Quad quad)
	{
		Data.mesh = quad;
		Data.model.LoadMesh(Data.mesh, Data.position, Data.rotation, Data.scale, Data.textureData);

		PushDataToScene();
	}

	void Entity::SetPosition(glm::vec3 position)
	{
		Data.position = position;

		PushDataToScene();
	}

	void Entity::SetRotation(glm::vec3 rotation)
	{
		Data.rotation = rotation;

		PushDataToScene();
	}

	void Entity::SetScale(glm::vec3 scale)
	{
		Data.scale = scale;

		PushDataToScene();
	}

	void Entity::PushDataToScene()
	{
		m_scene->Entities_Data[ID - 1] = Data;
	}
}