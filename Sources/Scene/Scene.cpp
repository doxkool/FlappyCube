#include "Scene/Scene.h"

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

	void Scene::CheckEntityForCollisions()
	{
		
	}

	void Scene::Draw()
	{
		for (size_t i = 0; i < Entities_Data.size(); i++)
			{
				Entities_Data[i].model.Draw();
			}
	}
}