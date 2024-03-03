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
		Engine::OrthographicCamera  m_Camera(-4.f, 4.f, -4.f, 4.f);

	// Creating the scene where all the game objects will be stored.
		Engine::Scene scene("DevScene");

	// Load the textures
		Engine::Texture BGTex("Game/Textures/background-day.png");
		Engine::Texture playerTex("Game/Textures/flappy-bird.png");
		Engine::Texture pipeTex("Game/Textures/pipe-green.png");

	// Creating the Player object.
		Engine::Player player("Player", glm::vec3(-4.f, -2.f, 0.f), glm::vec3(0.f), glm::vec3(1.f), playerTex, &scene);
		player.SetMovementSpeed(10.f);
	// Creating the Pipes object.
		Engine::Square2D pipe1("Pipe", glm::vec3(0.f, -3.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 4.f, 1.f), pipeTex, &scene);
		Engine::Square2D pipe2("Pipe", glm::vec3(0.f, 3.f, 0.f), glm::vec3(180.f, 0.f, 0.f), glm::vec3(1.f, 4.f, 1.f), pipeTex, &scene);
		Engine::Square2D pipe3("Pipe", glm::vec3(4.f, -2.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 4.f, 1.f), pipeTex, &scene);
		Engine::Square2D pipe4("Pipe", glm::vec3(4.f, 4.f, 0.f), glm::vec3(180.f, 0.f, 0.f), glm::vec3(1.f, 4.f, 1.f), pipeTex, &scene);

	// Creating the background.
		Engine::Square2D BgTile01("BG_Tile", glm::vec3(-8.f, 0, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(4.f, 8.f, 1.f), BGTex, &scene);
		Engine::Square2D BgTile02("BG_Tile", glm::vec3(-4.f, 0, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(4.f, 8.f, 1.f), BGTex, &scene);
		Engine::Square2D BgTile03("BG_Tile", glm::vec3(0.f, 0, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(4.f, 8.f, 1.f), BGTex, &scene);
		Engine::Square2D BgTile04("BG_Tile", glm::vec3(4.f, 0, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(4.f, 8.f, 1.f), BGTex, &scene);
		Engine::Square2D BgTile05("BG_Tile", glm::vec3(8.f, 0, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(4.f, 8.f, 1.f), BGTex, &scene);

		window.EnableVsync(1);

		Engine::ImGuiLayer::b_ShowStatistics = true;
		Engine::ImGuiLayer::b_ShowAdvanceStatistics = true;

		while (!window.Get_WindowShouldClose())
		{
			// Run Game code here

		// Start performance counter.
			Engine::Perf::StartPerfCounter(timestep);

			CheckForInputs();

			player.OnUpdate(window, timestep);

			if (Engine::Input::IsKeyPressed(window.m_Window, GLFW_KEY_Q))
			{
				player.SetTexture(pipeTex);
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

			Engine::ImGuiLayer::Render(scene);

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


// Resources :
//	https://www.programmingcreatively.com/opengl-tutorial-9-qs.php