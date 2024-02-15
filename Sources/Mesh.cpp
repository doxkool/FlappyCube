#include "Mesh.h"

namespace FlappyCube
{
	Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures)
		: position(0.f), origin(0.f), rotation(0.f), scale(0.f), ModelMatrix(0.f)
	{
		Mesh::vertices = vertices;
		Mesh::indices = indices;
		Mesh::textures = textures;

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
		glm::mat4 matrix,
		glm::vec3 translation,
		glm::quat rotation,
		glm::vec3 scale
		)
	{
		// Bind shader to be able to access uniforms
		Shader::Activate();
		VAO.Bind();

		for (unsigned int i = 0; i < textures.size(); i++)
		{
			textures[i].BindTexture();
		}

		//// Take care of the camera Matrix
		//camera.UpdateMatrix();
		//camera.PushMatrixToShader("camera");
		

		// Initialize matrices
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		glm::mat4 sca = glm::mat4(1.0f);

		// Transform the matrices to their correct form
		trans = glm::translate(trans, translation);
		rot = glm::mat4_cast(rotation);
		sca = glm::scale(sca, scale);

		// Push the matrices to the vertex shader
		Shader::setMat4fv(trans, "translation");
		Shader::setMat4fv(rot, "rotation");
		Shader::setMat4fv(sca, "scale");
		Shader::setMat4fv(matrix, "model");

		// Draw the actual mesh
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	}
}