#pragma once

#include "Scene/Scene.h"

#include "Core/Logger.h"

#include "Scene/Entities/EntityTypes.h"

namespace Engine
{
	class Entity
	{
		public:
			Entity(const char* name, Scene* scene = NULL);

			void SetName(const char* name);
			void SetTexture(const char* texturePath);
			void SetMesh(Quad quad);
			void SetPosition(glm::vec3 position);
			void SetRotation(glm::vec3 rotation);
			void SetScale(glm::vec3 scale);

			virtual void OnUpdate(Window window, TimeStep ts);

			void PushDataToScene();

			Base_Entity Data;

			unsigned int ID;

			Scene* m_scene;

		private:

	};
}