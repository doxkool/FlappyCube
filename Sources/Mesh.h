#pragma once

#include "Texture.h"

#include "Camera/Camera.h"
#include "Primitives.h"
#include "VertexArray.h"

#include "Logger.h"

#include <vector>
#include <string>

#include <glm.hpp>

#include <GL/glew.h>

namespace FlappyCube
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

		private:

			glm::vec3 position;
			glm::vec3 origin;
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::mat4 ModelMatrix;
	};
}