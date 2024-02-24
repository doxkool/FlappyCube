#pragma once

#include "Core/Model.h"

#include "Scene/Entities/EntityTypes.h"

#include <vector>

namespace Engine
{
	class Scene
	{
	public:
		Scene(const char* Name);
		~Scene();

		void LoadScene();

		void Draw();

		std::vector<Base_Entity> Entities_Data;

	private:
		const char* sceneName = "Scene";
		unsigned int sceneID;

	};
}