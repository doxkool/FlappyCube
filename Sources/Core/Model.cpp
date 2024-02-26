#include "Core/Model.h"


namespace Engine
{
	Primitive I_primitive;

	//std::vector<Mesh> meshes;
	//std::vector<glm::vec3> translationsMeshes;
	//std::vector<glm::quat> rotationsMeshes;
	//std::vector<glm::vec3> scalesMeshes;
	//std::vector<glm::mat4> matricesMeshes;

	std::vector<Mesh> meshes;
	glm::vec3 translationsMesh;
	glm::quat rotationsMesh;
	glm::vec3 scalesMesh;
	//glm::mat4 matricesMesh;

	void Model::LoadMesh(const Primitive& primitive, glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, Texture& texture)
	{
		I_primitive = primitive;

		std::vector<Vertex> vertexArray;
		std::vector <GLuint> indexArray;

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

		m_texture = texture;

		UpdateModelMatrices(translation, rotation, scale);

		//Mesh m_mesh(vertexArray, indexArray, m_texture);

		//mesh = &m_mesh;

		meshes.push_back(Mesh(vertexArray, indexArray, m_texture));
	}

	void Model::UpdateMeshPosition(glm::vec3 position)
	{
		m_position = position;

		UpdateModelMatrices(m_position, m_rotation, m_scale);
	}

	void Model::UpdateModelMatrices(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
	{
		// first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

		//m_modelMatrix = glm::translate(m_modelMatrix, translation);
		//m_modelMatrix = glm::mat4_cast(Vec3ToQuat(rotation));
		//m_modelMatrix = glm::scale(m_modelMatrix, scale);
		//
		//Shader::setMat4fv(m_modelMatrix, "model");

		glm::quat finalOrientation = Vec3ToQuat(rotation);

		// Initialize matrices
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		glm::mat4 sca = glm::mat4(1.0f);

		// Use translation, rotation, and scale to change the initialized matrices
		trans = glm::translate(trans, translation);
		rot = glm::mat4_cast(finalOrientation);
		sca = glm::scale(sca, scale);

		// Multiply all matrices together
		m_modelMatrix = trans * rot * sca;

		//Shader::setMat4fv(m_modelMatrix, "model");
	}

	glm::quat Model::Vec3ToQuat(glm::vec3 vec3)
	{
		glm::quat QuatAroundX = glm::rotate(glm::radians(vec3.x), glm::vec3(1.0, 0.0, 0.0));
		glm::quat QuatAroundY = glm::rotate(glm::radians(vec3.y), glm::vec3(0.0, 1.0, 0.0));
		glm::quat QuatAroundZ = glm::rotate(glm::radians(vec3.z), glm::vec3(0.0, 0.0, 1.0));
		
		glm::quat output = QuatAroundX * QuatAroundY * QuatAroundZ;

		return output;
	}

	void Model::Draw()
	{
		// Go over all meshes and draw each one
		for (unsigned int i = 0; i < meshes.size(); i++)
		{
			meshes[0].Mesh::Draw(m_modelMatrix, m_position, Vec3ToQuat(m_rotation), m_scale, m_texture);
		}

		//mesh->Draw(matricesMesh, m_position, Vec3ToQuat(m_rotation), m_scale);
	}
}