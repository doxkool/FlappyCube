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
		//for (size_t i = 0; i < Player_Entities_Data.size(); i++)
		//{
		//	Model::LoadMesh(Player_Entities_Data[i].mesh, Player_Entities_Data[i].position, Player_Entities_Data[i].rotation, Player_Entities_Data[i].scale, Player_Entities_Data[i].textureData);
		//}
	}

	void Scene::Draw()
	{
		for (size_t i = 0; i < Player_Entities_Data.size(); i++)
			{
				Player_Entities_Data[i].model.Draw();
			}
	}
}