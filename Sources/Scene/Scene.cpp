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

	bool Scene::CheckForOverlap()
	{
		std::vector<glm::vec3> EntitiesPosition;
		std::vector<int> EntitiesID;

		for (size_t e = 0; e < Entities_Data.size(); e++)
		{
			EntitiesID.push_back(Entities_Data[e].ID);
			EntitiesPosition.push_back(Entities_Data[e].position);

			for (size_t i = 0; i < Entities_Data.size(); i++)
			{
				if (!EntitiesID[i] == Entities_Data[i].ID)
				{
					EntitiesPosition[i];
				}
			}
		}


		return false;
	}

	void Scene::Draw()
	{
		for (size_t i = 0; i < Entities_Data.size(); i++)
			{
				Entities_Data[i].model.Draw();
			}
	}
}