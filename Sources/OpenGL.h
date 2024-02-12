#pragma once

#include "Logger.h"

#include <GL/glew.h>

#include <glm.hpp>

namespace FlappyCube
{
	class OpenGL
	{
		public:
			OpenGL();

			static void Init();

			static void Set_ClearColor(const glm::vec4& color);
			static void Clear();
			static void SetViewport(int Window_Width, int Window_Height);

		public:
			static int Viewport_Width, Viewport_Height;

		private:
	};
}