#include "Model.h"


namespace FlappyCube
{
	Primitive I_primitive;

	std::vector<Mesh> meshes;
	std::vector<glm::vec3> translationsMeshes;
	std::vector<glm::quat> rotationsMeshes;
	std::vector<glm::vec3> scalesMeshes;
	std::vector<glm::mat4> matricesMeshes;

	Model::Model()
	{
	}

	void Model::LoadMesh(const Primitive& primitive, glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, Texture& texture)
	{
		I_primitive = primitive;

		std::vector<Vertex> vertexArray;
		std::vector <GLuint> indexArray;
		std::vector <Texture> textureArray;

		unsigned nrOfVertices;
		unsigned nrOfIndices;

		LOG_TRACE("Loading model from primitive...");

		nrOfVertices = I_primitive.getNrOfVertices();
		nrOfIndices = I_primitive.getNrOfIndices();

		for (size_t i = 0; i < nrOfVertices; i++)
		{
			vertexArray.push_back(I_primitive.getVertices()[i]);
		}

		for (size_t i = 0; i < nrOfIndices; i++)
		{
			indexArray.push_back(I_primitive.getIndices()[i]);
		}

		textureArray.push_back(texture);

		UpdateModelMatrices(translation, rotation, scale);

		meshes.push_back(Mesh(vertexArray, indexArray, textureArray));

	}

	void Model::UpdateModelMatrices(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
	{
		// Convert VEC3 rotation to Quaternions
		glm::quat QuatAroundX = glm::rotate(glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
		glm::quat QuatAroundY = glm::rotate(glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
		glm::quat QuatAroundZ = glm::rotate(glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));
		glm::quat finalOrientation = QuatAroundX * QuatAroundY * QuatAroundZ;

		// Initialize matrices
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		glm::mat4 sca = glm::mat4(1.0f);

		// Use translation, rotation, and scale to change the initialized matrices
		trans = glm::translate(trans, translation);
		rot = glm::mat4_cast(finalOrientation);
		sca = glm::scale(sca, scale);

		// Multiply all matrices together
		glm::mat4 Matrices = trans * rot * sca;

		translationsMeshes.push_back(translation);
		rotationsMeshes.push_back(rotation);
		scalesMeshes.push_back(scale);

		matricesMeshes.push_back(Matrices);
	}

	void Model::Draw()
	{
		// Go over all meshes and draw each one
		for (unsigned int i = 0; i < meshes.size(); i++)
		{
			meshes[i].Mesh::Draw(matricesMeshes[i]);
		}
	}
}