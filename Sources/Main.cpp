// Flappybird assets by Samuel Cust : https://github.com/samuelcust/flappy-bird-assets/tree/master

// TODO :
// - 
// - 
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

		Engine::ImGuiLayer::Init(window.m_Window);

		// Setup window user pointer
		window.SetWindowUserPointer(&window);
		// Setup window Callback
		Engine::WindowCallback WindowCallback(window);

		Run();
	}

	void Game::Run()
	{
	// ---- Declare all runtime variables. ----

		Engine::TimeStep timestep;

	// Creating the camera object.
		Engine::OrthographicCamera  m_Camera(0, 1000, 0, 1000);

		Engine::Scene scene("DevScene");

		auto Player = scene.AddEntity("Player");

		scene.AddComponent(Player, Engine::Transform);
		scene.AddComponent(Player, Engine::Sprite2D);

		//scene.GetRegistry().emplace<Engine::TransformComponent>(Player);
		//scene.GetRegistry().emplace<Engine::Sprite2DComponent>(Player, glm::vec4(0.f, 1.0f, 0.f, 1.0f));

		window.EnableVsync(1);

		Engine::ImGuiLayer::b_ShowStatistics = true;
		Engine::ImGuiLayer::b_ShowAdvanceStatistics = false;
		Engine::ImGuiLayer::b_ShowSceneInspector = true;

		while (!window.Get_WindowShouldClose())
		{
			// Run Game code here

		// Start performance counter.
			Engine::Perf::StartPerfCounter(timestep);

			CheckForInputs();

			scene.OnUpdate(timestep);

			if (Engine::Input::IsKeyPressed(window.m_Window, GLFW_KEY_Q))
			{
				
			}

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

		// ImGui New Frame
			Engine::ImGuiLayer::NewFrame();

			Engine::ImGuiLayer::Render(&scene);

		// Swap the Buffer
			window.SwapBuffer();

		// End performance counter.
			Engine::Perf::EndPerfCounter();
		}
	}
	
	void Game::CheckForInputs()
	{

	}
}