#pragma once

#include "Scene/Scene.h"
#include "Scene/Entity.h"

#include <glm.hpp>

namespace Engine
{
	enum Direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

	class Player : public Entity
	{
		public:
			Player(const char* name, Scene* scene = NULL);

			void OnUpdate(Window window, TimeStep ts);

			void SetPosition(glm::vec3 position);
			void SetRotation(glm::vec3 rotation);
			void SetScale(glm::vec3 scale);

			void Move(Direction direction);

			void SetName(const char* name);

			void SetTexture(const char* texture);

			void SetMesh(Quad quad);


			Player_Entity Data;

			unsigned int ID;

		private:

			void PushDataToScene();

			Scene* m_scene;
	};
}