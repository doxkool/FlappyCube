#pragma once

#include "Camera/OrthographicCamera.h"
#include "Camera/PerspectiveCamera.h"

#include "Model.h"
#include "Shader.h"
#include "Window/Window.h"
#include "Logger.h"

#include "Primitives.h"

#include "Utilities.h"

#include <glm.hpp>

int main(int argc, char* argv[]);

namespace FlappyCube
{
	class Game
	{
	public:
		Game();

		void Create_World();
		void RunGameLoop();

		void CheckForInputs();

	private:
		Window m_window;
	};
}