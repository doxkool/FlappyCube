#include "Main.h"

int main(int argc, char* argv[])
{	
	FlappyCube::Logger::Init();

	FlappyCube::Game();

	return 0;
}

namespace FlappyCube
{
	Game::Game()
		 : m_window("FlappyCube", 1280, 720, true)
	{
		OpenGL::Init();
		Shader::Init("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

		// Setup window user pointer
		m_window.SetWindowUserPointer(&m_window);
		// Setup window Callback
		WindowCallback WindowCallback(m_window);

		Create_World();
		RunGameLoop();
	}

	void Game::Create_World()
	{
		Quad Player;

		Texture tex1("Game/Textures/Default_Tex.jpg");

		Model::LoadMesh(Player, glm::vec3(0.0f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f), tex1);
	}

	void Game::RunGameLoop()
	{
		OrthographicCamera  m_Camera(-1.f, 1.f, -1.f, 1.f);

		m_window.EnableVsync(1);

		while (!m_window.Get_WindowShouldClose())
		{
			// Run Game code here

		// Declare runtime variables.
			TimeStep timestep;

			std::string str_FPS;
			std::string str_FrameTime;

		// Start performance counter.
			Perf::StartPerfCounter(timestep);

			CheckForInputs();

		// Output the FPS and frame time to the window tilte.
			str_FPS = std::to_string(Perf::Get_FPS());
			str_FrameTime = std::to_string(Perf::Get_FrameTime());
			std::string newTitle = m_window.WinParams.Window_Title + " " + str_FPS + "fps / " + str_FrameTime + "ms";

			m_window.UpdateWindowTitle(newTitle);

		// Update Camera.
			m_Camera.OnUpdate(m_window, timestep);
			m_Camera.UpdateMatrix();
			m_Camera.PushMatrixToShader("camera");

		// OpenGL clear.
			OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 1.f));
			OpenGL::Clear();

		// Draw models.
			Model::Draw();

		// Update window.
			m_window.Update();
			m_window.SwapBuffer();

		// End performance counter.
			Perf::EndPerfCounter();
		}
	}

	void Game::CheckForInputs()
	{
		if (m_window.CheckKeyboardInput(GLFW_KEY_ESCAPE))
		{
			LOG_DEBUG("test1");
		}
	}
}


// Resources :
//	https://www.programmingcreatively.com/opengl-tutorial-9-qs.php