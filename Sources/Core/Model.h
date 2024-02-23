#pragma once

#include "Core/Mesh.h"

#include <gtx/euler_angles.hpp>
#include <gtx/quaternion.hpp>

namespace Engine
{
	class Model
	{
	public:
		Model() = default;

		void LoadMesh(const Primitive& primitive, glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), Texture& texture = Texture("Game/Textures/Default_Tex.jpg"));

		void UpdateMeshPosition(glm::vec3 position);

		void UpdateModelMatrices(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);

		void Draw();

	private:

		glm::quat Vec3ToQuat(glm::vec3 vec3);

		glm::vec3 m_position = glm::vec3(0.f);
		glm::vec3 m_origin = glm::vec3(0.f);
		glm::vec3 m_rotation = glm::vec3(0.f);
		glm::vec3 m_scale = glm::vec3(1.f);

	};
}