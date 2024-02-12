#pragma once

#include "Logger.h"

#include <GL/glew.h>
//#include <glfw3.h>
//#include <glm.hpp>

//#include <vector>

int main(int argc, char* argv[]);

struct Window_Specs
{
	int Window_Width = 800;
	int Window_Height = 600;
	bool Window_Resizeable = true;
};

namespace FlappyCube
{
	int Init_OpenGL();
	int Init_GLFW();
	void RunGameLoop();
}