#pragma once

#include "Core/Mesh.h"

#include <gtx/euler_angles.hpp>
#include <gtx/quaternion.hpp>

namespace FlappyCube
{
	class Model
	{
	public:
		Model();

		static void LoadMesh(const Primitive& primitive, glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), Texture& texture = Texture("Game/Textures/Default_Tex.jpg"));

		static void UpdateModelMatrices(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);

		static void Draw();


	private:

	};
}