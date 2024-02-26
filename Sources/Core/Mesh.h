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
			Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Texture& texture);

			// mesh data
			std::vector <Vertex> vertices;
			std::vector <GLuint> indices;
			Texture texture;

			void Draw
			(
				glm::mat4 modelMatrix,
				glm::vec3 translation,
				glm::quat rotation,
				glm::vec3 scale,
				Texture texture
			);

			VertexArray VAO;

		private:

			glm::vec3 m_position;
			glm::vec3 m_origin;
			glm::vec3 m_rotation;
			glm::vec3 m_scale;
	};
}