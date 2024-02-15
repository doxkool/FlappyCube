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
		Quad Player;

		Texture tex1("Game/Textures/Default_Tex.jpg");

		Model::LoadMesh(Player, glm::vec3(0.0f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f), tex1);
	}

	void RunGameLoop()
	{
		PerspectiveCamera m_pCamera(45.f, 0.1f, 100.f);

		while (!m_window.Get_WindowShouldClose())
		{
			// Run Game code here

		// Declare runtime variables.
			TimeStep timestep;

			std::string str_FPS;
			std::string str_FrameTime;

		// Start performance counter.
			Perf::StartPerfCounter(timestep);

		// Output the FPS and frame time to the window tilte.
			str_FPS = std::to_string(Perf::Get_FPS());
			str_FrameTime = std::to_string(Perf::Get_FrameTime());
			std::string newTitle = m_window.Spec.Window_Title + " " + str_FPS + "fps / " + str_FrameTime + "ms";

			m_window.UpdateWindowTitle(newTitle);

		// Update Camera.
			m_pCamera.OnUpdate(timestep);

			m_pCamera.UpdateMatrix();
			m_pCamera.PushMatrixToShader("camera");

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
}