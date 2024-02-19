#include "Scene/Scene.h"

namespace Engine
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::LoadScene()
	{
		Model::LoadMesh(Player_Entities_Data[0].mesh, glm::vec3(0.0f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f), Player_Entities_Data[0].texture);
	}
}