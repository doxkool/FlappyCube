#include "Main.h"

int main(int argc, char* argv[])
{	
	Engine::Logger::Init();

	FlappySquare::Game();

	return 0;
}

namespace FlappySquare
{
	Game::Game()
		 : window("FlappySquare", 1280, 720, true)
	{
		Engine::OpenGL::Init();
		Engine::Shader::Init("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

		// Setup window user pointer
		window.SetWindowUserPointer(&window);
		// Setup window Callback
		Engine::WindowCallback WindowCallback(window);

		SetupScene();
		RunGameLoop();
	}

	void Game::SetupScene()
	{
		Engine::Scene scene;

		Engine::Quad Quad_Player;
		
		Engine::Player player("Player1", &scene);
		player.SetTexture("Game/Textures/flappy-bird.png", &scene);
		player.SetMesh(Quad_Player, &scene);
		
		Engine::Quad Quad_Player2;
		
		Engine::Player player2("Player2", &scene);
		player2.SetPosition({1.f, 1.f, 0.f}, &scene);
		player2.SetMesh(Quad_Player2, &scene);

		scene.LoadScene();
	}

	void Game::RunGameLoop()
	{
		Engine::OrthographicCamera  m_Camera(0.f, 10.f, 0.f, 10.f);

		window.EnableVsync(1);

		while (!window.Get_WindowShouldClose())
		{
			// Run Game code here

		// Declare runtime variables.
			Engine::TimeStep timestep;

			std::string str_FPS;
			std::string str_FrameTime;

		// Start performance counter.
			Engine::Perf::StartPerfCounter(timestep);

			CheckForInputs();

		// Output the FPS and frame time to the window tilte.
			str_FPS = std::to_string(Engine::Perf::Get_FPS());
			str_FrameTime = std::to_string(Engine::Perf::Get_FrameTime());
			std::string newTitle = window.WinParams.Window_Title + " " + str_FPS + "fps / " + str_FrameTime + "ms";

			window.UpdateWindowTitle(newTitle);

		// Update Camera.
			m_Camera.OnUpdate(window, timestep);
			m_Camera.UpdateMatrix();
			m_Camera.PushMatrixToShader("camera");

		// OpenGL clear.
			Engine::OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 1.f));
			Engine::OpenGL::Clear();

		// Draw models.
			Engine::Model::Draw();

		// Update window.
			window.Update();
			window.SwapBuffer();

		// End performance counter.
			Engine::Perf::EndPerfCounter();
		}
	}

	void Game::CheckForInputs()
	{
		if (Engine::Input::IsKeyPressed(window.m_Window, GLFW_KEY_ESCAPE))
		{
			LOG_DEBUG("test1");
		}
	}
}


// Resources :
//	https://www.programmingcreatively.com/opengl-tutorial-9-qs.php