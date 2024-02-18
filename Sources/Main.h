#pragma once

#include "Core/Model.h"
#include "Core/Shader.h"
#include "Core/Logger.h"
#include "Core/Primitives.h"
#include "Core/Utilities.h"

#include "Scene/Player.h"

#include "Window/Window.h"

#include "Camera/OrthographicCamera.h"
#include "Camera/PerspectiveCamera.h"

#include <glm.hpp>

int main(int argc, char* argv[]);

namespace FlappySquare
{
	class Game
	{
	public:
		Game();

		void Create_World();
		void RunGameLoop();

		void CheckForInputs();

	private:
		Engine::Window m_window;
	};
}