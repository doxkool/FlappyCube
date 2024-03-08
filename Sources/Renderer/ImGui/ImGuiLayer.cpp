#include "Renderer/ImGui/ImGuiLayer.h"

namespace Engine
{
	std::vector<float> ImGuiLayer::FrameTime;
	std::vector<float> ImGuiLayer::FPS;
	
	bool ImGuiLayer::b_ShowDemoWindow = false;
	
	bool ImGuiLayer::b_ShowStatistics = false;
	bool ImGuiLayer::b_ShowAdvanceStatistics = false;
	bool ImGuiLayer::b_ShowMenuBar = false;
	bool ImGuiLayer::b_ShowSceneInspector = false;

	void ImGuiLayer::Init(GLFWwindow* window)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true);

		const char* glsl_version = "#version 450";

		ImGui_ImplOpenGL3_Init(glsl_version);
	}

	void ImGuiLayer::NewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::Render(Scene* scene)
	{
		if (b_ShowMenuBar)ShowMenuBar();
		if (b_ShowStatistics)ShowStatistics();
		if (b_ShowAdvanceStatistics)ShowAdvanceStatistics();
		if (b_ShowSceneInspector)SceneInspector SceneInspectorApp(scene);

		if (b_ShowDemoWindow)ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui::EndFrame();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		ImGuiIO& io = ImGui::GetIO();

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImGuiLayer::ShowMenuBar()
	{
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New", "Ctrl+N"))
				{

				}

				if (ImGui::MenuItem("Open...", "Ctrl+O"))
				{

				}

				if (ImGui::MenuItem("Save", "Ctrl+S"))
				{
				
				}

				if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S"))
				{

				}

				ImGui::Separator();
				if (ImGui::MenuItem("Exit", "Atl+F4"))
				{

				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Edit"))
			{
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("View"))
			{
				if (ImGui::BeginMenu("Statistics"))
				{
					if (ImGui::MenuItem("Show FPS Overlay", "F1", &b_ShowStatistics)) {}
					if (ImGui::MenuItem("Show Advance Statistics", "F2", &b_ShowAdvanceStatistics)) {}

					ImGui::EndMenu();
				}

				ImGui::Separator();
				if (ImGui::MenuItem("Scene Inspector", NULL, &b_ShowSceneInspector)) {}
				if (ImGui::MenuItem("ImGui Demo Window", NULL, &b_ShowDemoWindow)) {}

				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}
	}

	void ImGuiLayer::ShowStatistics()
	{
		ImGuiIO& io = ImGui::GetIO();
		
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(ImVec2(200.f, 400.f));

		ImGuiWindowFlags  window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoInputs;

		ImGui::Begin("Performance", &b_ShowStatistics, window_flags);
		ImGui::Text("(%.1f FPS)", Engine::Perf::Get_FPS());
		ImGui::Text("(%.3f MS)", Engine::Perf::Get_FrameTime());
		
		ImGui::End();
			
	}

	void ImGuiLayer::ShowAdvanceStatistics()
	{
		//ImGui::SetNextWindowSize(ImVec2(800.f, 600.f));

		ImGui::Begin("Advance Performance Statistics", &b_ShowAdvanceStatistics);
		
		static bool update = true;
		ImGui::Checkbox("Update", &update);

		double f_FrameTime = Engine::Perf::Get_FrameTime();
		double f_FPS = Engine::Perf::Get_FPS();

		if (update)
		{
			if (FPS.size() > 100)
			{
				for (double i = 1; i < FPS.size(); i++)
				{
					FPS[i - 1] = FPS[i];
				}
				FPS[FPS.size() - 1] = f_FPS;

				for (double i = 1; i < FrameTime.size(); i++)
				{
					FrameTime[i - 1] = FrameTime[i];
				}
				FrameTime[FrameTime.size() - 1] = f_FrameTime;
			}
			else
			{
				FPS.push_back(f_FPS);
				FrameTime.push_back(f_FrameTime);
			}
		}

		char FpsOverlay[32];
		sprintf(FpsOverlay, "%.2f FPS", f_FPS);
		ImGui::PlotHistogram("FPS", &FPS[0], FPS.size(), 0, FpsOverlay, 0.0f, 100.0f, ImVec2(700, 100));

		char FrameTimeOverlay[32];
		sprintf(FrameTimeOverlay, "%.3f ms", f_FrameTime);
		ImGui::PlotHistogram("FrameTime", &FrameTime[0], FrameTime.size(), 0, FrameTimeOverlay, 0.0f, 100.0f, ImVec2(700, 100));
		

		ImGui::End();
	}
}