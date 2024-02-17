#pragma once

#include "Logger.h"

#include <GL/glew.h>

#include <glm.hpp>

namespace FlappyCube
{
	class OpenGL
	{
		public:
			OpenGL() {}

			static void Init();

			static void Set_ClearColor(const glm::vec4& color);
			static void Clear();
			static void SetViewport(int FrameBuffer_Width, int FrameBuffer_Height);

		public:
			static int m_FrameBuffer_Width, m_FrameBuffer_Height;

		private:
	};
}