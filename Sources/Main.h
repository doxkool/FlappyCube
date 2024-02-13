#pragma once

#include "Shader.h"
#include "Window.h"
#include "Logger.h"

#include "Primitives.h"

#include <glm.hpp>

int main(int argc, char* argv[]);

namespace FlappyCube
{
	void Init();
	void Create_World();
	void RunGameLoop();

	Window m_window;
	//Camera  m_camera;
}