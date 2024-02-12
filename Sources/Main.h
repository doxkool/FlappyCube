#pragma once

#include "Spec.h"
#include "Window.h"
#include "Logger.h"

#include <glm.hpp>

int main(int argc, char* argv[]);

namespace FlappyCube
{
	Window window;
	void Init();
	void RunGameLoop();
}