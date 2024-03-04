#include "Core/Model.h"


namespace Engine
{
	Primitive I_primitive;

	std::vector<Mesh> meshes;
	glm::vec3 translationsMesh;
	glm::quat rotationsMesh;
	glm::vec3 scalesMesh;

	void Model::LoadMesh(const Primitive& primitive, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Texture& texture)
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
		m_position = position;
		m_rotation = rotation;
		m_scale = scale;

		UpdateModelMatrices(position, rotation, scale);

		meshes.push_back(Mesh(vertexArray, indexArray, m_texture));
	}

	void Model::UpdateMeshTransform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{
		m_position = position;
		m_rotation = rotation;
		m_scale = scale;

		UpdateModelMatrices(m_position, m_rotation, m_scale);
	}

	void Model::UpdateMeshTexture(Texture& texture)
	{
		m_texture = texture;
	}

	void Model::UpdateModelMatrices(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
	{
		glm::quat finalOrientation = Vec3ToQuat(rotation);
	
		// Initialize matrices
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		glm::mat4 sca = glm::mat4(1.0f);
	
		// Use translation, rotation, and scale to change the initialized matrices
		trans = glm::translate(trans, translation);
		//trans = glm::translate(trans, glm::vec3(1.5f * scale.x, 1.5f * scale.y, 1.5f * scale.z));
		rot = glm::mat4_cast(finalOrientation);
		//trans = glm::translate(trans, glm::vec3(-1.5f * scale.x, -1.5f * scale.y, -1.5f * scale.z));
		sca = glm::scale(sca, scale);
	
		// Multiply all matrices together
		m_modelMatrix = trans * rot * sca;
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
	}
}