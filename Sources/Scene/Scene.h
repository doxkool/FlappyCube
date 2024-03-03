#pragma once

#include "Scene/Entities/EntityTypes.h"

#include <vector>

namespace Engine
{
	class Scene
	{
	public:
		Scene(const char* Name);
		~Scene();

		bool CheckForOverlap();

		void Draw();

		std::vector<Base_Entity> Entities_Data;

		const char* sceneName = "Scene";

	private:
		unsigned int sceneID = 0;

	};
}