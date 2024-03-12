#include "Scene/Scene.h"

#include "Core/Model.h"

namespace Engine
{
	Scene::Scene(const char* Name)
	{
		sceneName = Name;
		sceneID = sceneID + 1;
		LOG_TRACE("Scene created :\n- ID : {}\n- Name : {}", sceneID, sceneName);
	}

	Scene::~Scene()
	{
	}

	void Scene::OnUpdate(TimeStep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<Sprite2DComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, Sprite2DComponent>(entity);

			auto& model = m_Registry.get<Sprite2DComponent>(entity).model;
			auto& mesh = m_Registry.get<Sprite2DComponent>(entity).mesh;

			model.LoadMesh(mesh, { 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 1.f, 1.f, 1.f }, m_Registry.get<Sprite2DComponent>(entity).texture);
		}
	}

	entt::entity Scene::AddEntity(const std::string& name)
	{
		entt::entity entity = m_Registry.create();

		m_Registry.emplace<IDComponent>(entity);
		m_Registry.emplace<TransformComponent>(entity);

		if (name.empty())
		{
			auto& tag = m_Registry.emplace<TagComponent>(entity, "Entity");

			LOG_DEBUG("New entity created: {}", tag.Tag);
		}
		else {
			auto& tag = m_Registry.emplace<TagComponent>(entity, name);

			LOG_DEBUG("New entity created: {}", tag.Tag);
		}

		return entity;
	}

	void Scene::AddComponent(entt::entity entity, ComponentType componentType)
	{
		switch (componentType)
		{
		case Engine::Transform:
			
			if (m_Registry.any_of<TransformComponent>(entity))
			{
				LOG_ERROR("The entity '{}' already have a Transform component!", m_Registry.get<TagComponent>(entity).Tag);
				break;
			}
			
			m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
			LOG_DEBUG("Transform component added to '{}'", m_Registry.get<TagComponent>(entity).Tag);

			break;
		case Engine::Sprite2D:
			m_Registry.emplace<Sprite2DComponent>(entity, glm::vec4(0.f, 1.0f, 0.f, 1.0f));

			LOG_DEBUG("Sprite2D component added to : '{}'", m_Registry.get<TagComponent>(entity).Tag);
			break;
		case Engine::Collision:
			break;
		case Engine::Camera:
			break;
		default:
			LOG_ERROR("The component type ({}) was not added to {}..", componentType, m_Registry.get<TagComponent>(entity).Tag);
			break;
		}
	}

	void Scene::RemoveComponent(entt::entity entity)
	{
		m_Registry.remove<TransformComponent>(entity);
	}

	void Scene::GetComponent(entt::entity entity)
	{
		m_Registry.get<TransformComponent>(entity);
	}

	void Scene::ClearAllEntity()
	{
		m_Registry.clear();
	}

	void Scene::Draw()
	{
		for (size_t i = 0; i < Entities_Data.size(); i++)
			{
				Entities_Data[i].model.Draw();
			}
	}
}