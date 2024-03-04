#pragma once

#include "Scene/Scene.h"
#include "Core/Utilities.h"
#include "Core/Logger.h"
#include "Core/Primitives.h"

#include "Scene/Entities/EntityTypes.h"

namespace Engine
{
	class Entity
	{
		public:
			Entity(const char* name, glm::vec3 position, float rotation, glm::vec3 scale, Texture& texture, Scene* scene = NULL);

			void SetName(const char* name);
			void SetTexture(Texture& texture);
			void SetMesh(Quad quad);
			void SetPosition(glm::vec3 position);
			void SetRotation(float rotation);
			void SetScale(glm::vec3 scale);
			void SetMovementSpeed(float speed);

			virtual void OnUpdate(Window window, TimeStep ts);

			void PushDataToScene();

			Base_Entity Data;

			unsigned int ID;

			Quad quad;

			Scene* m_scene;

		private:

	};
}