#pragma once

#include "Core/Input.h"
#include "Core/Model.h"
#include "Core/Shader.h"
#include "Core/Logger.h"
#include "Core/Primitives.h"
#include "Core/Utilities.h"

#include "Scene/Scene.h"
#include "Scene/Entities/Player.h"
#include "Scene/Entities/Square2D.h"

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

		void RunGameLoop();

		void CheckForInputs();

	private:
		Engine::Window window;
	};
}