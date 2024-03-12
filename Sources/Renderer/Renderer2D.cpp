#include "Renderer/Renderer2D.h"

namespace Engine
{
	struct Renderer2DData
	{
		std::shared_ptr<VertexArray> QuadVertexArray;
		std::shared_ptr<VertexBuffer> QuadVertexBuffer;
		std::shared_ptr<Shader> QuadShader;
		std::shared_ptr<Texture> QuadTexture;
	};

	static Renderer2DData s_Data;

	void Renderer2D::Init()
	{

	}

	void Renderer2D::DrawQuad(const glm::mat4& transform, const glm::vec4& color)
	{
		
	}

	void Renderer2D::DrawQuad(const glm::mat4& transform, const Texture& texture)
	{

	}
}