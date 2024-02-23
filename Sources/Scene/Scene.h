#pragma once

#include "Core/Model.h"

#include "Scene/Entity.h"

#include <vector>

namespace Engine
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		void LoadScene();

		void Draw();

		std::vector<Player_Entity> Player_Entities_Data;

	private:

	};
}