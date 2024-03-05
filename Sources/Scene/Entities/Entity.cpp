#include "Scene/Entities/Entity.h"

namespace Engine
{
	Entity::Entity(const char* name, glm::vec3 position, float rotation, glm::vec3 scale, Texture& texture, Scene* scene)
		: m_scene(scene)
	{
		ID = scene->Entities_Data.size();

		Data.ID = ID;
		Data.name = name;

		Data.position = position;
		Data.rotation = glm::vec3(0, 0, rotation);
		Data.scale = scale;

		Data.textureData = texture;
		Data.texturePath = texture.texturePath;

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
		Data.textureData = texture;
		Data.texturePath = texture.texturePath;

		Data.model.UpdateMeshTexture(Data.textureData);

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

		Data.model.UpdateMeshTransform(Data.position, Data.rotation, Data.scale);

		PushDataToScene();
	}

	void Entity::SetRotation(float rotation)
	{
		Data.rotation =  glm::vec3(0, 0, rotation);

		Data.model.UpdateMeshTransform(Data.position, Data.rotation, Data.scale);

		PushDataToScene();
	}

	void Entity::SetScale(glm::vec3 scale)
	{
		Data.scale = scale;

		Data.model.UpdateMeshTransform(Data.position, Data.rotation, Data.scale);

		PushDataToScene();
	}

	void Entity::SetMovementSpeed(float speed)
	{
		Data.MovementSpeed = speed;

		PushDataToScene();
	}

	void Entity::PushDataToScene()
	{
		m_scene->Entities_Data[ID] = Data;
	}
}