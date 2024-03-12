#pragma once

#include "Scene/Entities/EntityTypes.h"

#include "Scene/Components.h"

#include <entt.hpp>
#include <vector>

namespace Engine
{
	class Scene
	{
	public:
		Scene(const char* Name);
		~Scene();

		void OnUpdate(TimeStep ts);

		entt::entity AddEntity(const std::string& name);

		//entt::registry& GetRegistry() { return *m_Registry; }

		void AddComponent(entt::entity entity, ComponentType componentType);
		void RemoveComponent(const entt::entity entity);
		void GetComponent(entt::entity entity);

		void ClearAllEntity();

		void Draw();

		std::vector<Base_Entity> Entities_Data;

		const char* sceneName = "Scene";

	private:

		entt::registry m_Registry;

		unsigned int sceneID = 0;

	};
}