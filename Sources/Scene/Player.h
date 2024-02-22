#pragma once

#include "Scene/Scene.h"
#include "Scene/Entity.h"

#include <glm.hpp>

namespace Engine
{
	class Player : public Entity
	{
		public:
			Player(const char* name, Scene* scene = NULL);

			void SetPosition(glm::vec3 position, Scene* scene);
			void SetRotation(glm::vec3 rotation, Scene* scene);
			void SetScale(glm::vec3 scale, Scene* scene);

			void Move(glm::vec3 translation, glm::vec3 oriantation);

			void SetName(const char* name, Scene* scene);

			void SetTexture(const char* texture, Scene* scene);

			void SetMesh(Quad quad, Scene* scene);

			void UpdateEntity(Player_Entity data, Scene& scene);

			Player_Entity Data;

			unsigned int ID;

		private:

			void PushDataToScene(Scene* scene);

			Scene* m_scene;
	};
}