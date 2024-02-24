
// TODO :
// - Fix movement based on frame time.
// - All screen objects move when player move, seem to be an issue with the model matrix.
// - 
// - 

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

		RunGameLoop();
	}

	void Game::RunGameLoop()
	{
		Engine::OrthographicCamera  m_Camera(-2.f, 2.f, -2.f, 2.f);

		window.EnableVsync(1);

		Engine::Scene scene("Scene1");

		Engine::Quad Quad;

		Engine::Player player("Player1", &scene);
		player.SetTexture("Game/Textures/flappy-bird.png");
		player.SetMesh(Quad);

		
		Engine::Square2D wall("Wall01", &scene);
		wall.SetTexture("Game/Textures/window.png");
		wall.SetPosition({ 1.f, 0.f, 0.f });
		wall.SetMesh(Quad);

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

			player.OnUpdate(window, timestep);

		// Output the FPS and frame time to the window tilte.
			str_FPS = std::to_string(Engine::Perf::Get_FPS());
			str_FrameTime = std::to_string(Engine::Perf::Get_FrameTime());
			std::string newTitle = window.WinParams.Window_Title + " " + str_FPS + "fps / " + str_FrameTime + "ms";

			window.UpdateWindowTitle(newTitle);

		// Update Camera.
			m_Camera.UpdateMatrix();
			m_Camera.PushMatrixToShader("camera");

		// OpenGL clear.
			Engine::OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 0.f));
			Engine::OpenGL::Clear();

		// Draw models.
			scene.Draw();

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
			window.Set_WindowShouldClose();
		}
	}
}


// Resources :
//	https://www.programmingcreatively.com/opengl-tutorial-9-qs.php