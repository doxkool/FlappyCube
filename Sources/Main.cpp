#include "Main.h"

int main(int argc, char* argv[])
{	
	FlappyCube::Init();

	return 0;
}

namespace FlappyCube
{
	void Init()
	{
		Logger::Init();
		window.Init("FlappyCube", 1280, 720, true);
		OpenGL::Init();

		RunGameLoop();
	}

	void RunGameLoop()
	{
		while (!window.Get_WindowShouldClose())
		{
			// Run Game code here

			OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 1.f));
			OpenGL::Clear();

			window.Update();
			window.SwapBuffer();
		}
	}
}