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
		m_window.Init("FlappyCube", 1280, 720, true);
		OpenGL::Init();

		Shader::Init("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

		Create_World();
		RunGameLoop();
	}

	void Create_World()
	{
		//Quad Player;
	}

	void RunGameLoop()
	{
		while (!m_window.Get_WindowShouldClose())
		{
			// Run Game code here

			OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 1.f));
			OpenGL::Clear();

			m_window.Update();
			m_window.SwapBuffer();
		}
	}
}