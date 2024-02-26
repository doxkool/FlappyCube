#include "Core/Mesh.h"

namespace Engine
{
	Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Texture& texture)
	{
		Mesh::vertices = vertices;
		Mesh::indices = indices;
		Mesh::texture = texture;

		VAO.Bind();
		// Generates Vertex Buffer Object and links it to vertices
		VertexBuffer VBO(vertices);
		// Generates Element Buffer Object and links it to indices
		ElementBuffer EBO(indices);

		// Links VBO Position attributes to VAO
		VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		// Links VBO Color attributes to VAO
		VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		// Links VBO Texcoord attributes to VAO
		VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
		// Links VBO Normal attributes to VAO
		VAO.LinkAttrib(VBO, 3, 3, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

		// Unbind all to prevent accidentally modifying them
		VAO.Unbind();
		VBO.Unbind();
		EBO.Unbind();
	}

	void Mesh::Draw
	(
		glm::mat4 modelMatrix,
		glm::vec3 translation,
		glm::quat rotation,
		glm::vec3 scale,
		Texture texture
		)
	{
		// Bind shader to be able to access uniforms
		Shader::Activate();
		VAO.Bind();

		//for (unsigned int i = 0; i < textures.size(); i++)
		//{
		//	textures[i].BindTexture();
		//}

		texture.BindTexture();

		// Initialize matrices
		glm::mat4 worldMatrix;

		// Transform the matrices to their correct form
		worldMatrix = glm::translate(worldMatrix, translation);
		worldMatrix = glm::mat4_cast(rotation);
		worldMatrix = glm::scale(worldMatrix, scale);

		// Push the matrices to the vertex shader
		Shader::setMat4fv(worldMatrix, "world");
		Shader::setMat4fv(modelMatrix, "model");

		// Draw the actual mesh
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	}
}