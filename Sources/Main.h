#pragma once

#include "Camera/OrthographicCamera.h"
#include "Camera/PerspectiveCamera.h"

#include "Model.h"

#include "Shader.h"
#include "Window.h"
#include "Logger.h"

#include "Primitives.h"

#include "Utilities.h"

#include <glm.hpp>

int main(int argc, char* argv[]);

namespace FlappyCube
{
	void Init();
	void Create_World();
	void RunGameLoop();

	Window m_window;
	OrthographicCamera  m_OrthoCamera(-2.f, 2.f, -1.5f, 1.5f);
	
}