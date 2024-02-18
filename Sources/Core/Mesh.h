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
				glm::mat4 matrix = glm::mat4(1.0f),
				glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
				glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
				glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
			);

			VertexArray VAO;

		private:

			glm::vec3 position;
			glm::vec3 origin;
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::mat4 ModelMatrix;
	};
}