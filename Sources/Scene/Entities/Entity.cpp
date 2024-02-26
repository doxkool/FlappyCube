#include "Scene/Entities/Entity.h"

namespace Engine
{
	Entity::Entity(const char* name, glm::vec3 position, Texture& texture, Scene* scene)
		: m_scene(scene)
	{
		ID = scene->Entities_Data.size() + 1;

		Data.ID = ID;
		Data.name = name;

		Data.position = position;
		Data.rotation = glm::vec3(0.f);
		Data.scale = glm::vec3(1.f);

		Data.textureData = texture;

		Data.mesh = quad;
		Data.model.LoadMesh(Data.mesh, Data.position, Data.rotation, Data.scale, Data.textureData);

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

	void Entity::SetTexture(Texture& texture)
	{
		//Data.texturePath = texturePath;

		Data.textureData = texture;

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