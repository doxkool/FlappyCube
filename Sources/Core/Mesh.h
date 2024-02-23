#pragma once

#include "Core/Texture.h"
#include "Core/Primitives.h"
#include "Core/VertexArray.h"
#include "Core/Logger.h"

#include "Camera/Camera.h"

#include <vector>
#include <string>

#include <glm.hpp>

#include <GL/glew.h>

namespace Engine
{

	class Mesh
	{
		public:
			Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);

			// mesh data
			std::vector <Vertex> vertices;
			std::vector <GLuint> indices;
			std::vector <Texture> textures;

			void Draw
			(
				glm::mat4 matrix,
				glm::vec3 translation,
				glm::quat rotation,
				glm::vec3 scale
			);

			VertexArray VAO;

		private:

			glm::vec3 m_position;
			glm::vec3 m_origin;
			glm::vec3 m_rotation;
			glm::vec3 m_scale;

			glm::mat4 ModelMatrix;
	};
}