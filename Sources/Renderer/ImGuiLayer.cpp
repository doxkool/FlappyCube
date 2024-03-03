#include "Renderer/ImGuiLayer.h"

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

	void ImGuiLayer::Render(Scene& scene)
	{
		if (b_ShowMenuBar)ShowMenuBar();
		if (b_ShowStatistics)ShowStatistics();
		if (b_ShowAdvanceStatistics)ShowAdvanceStatistics();
		if (b_ShowSceneInspector)ShowSceneInspector(scene);

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
					if (ImGui::MenuItem("Show FPS Overlay", "F1", &b_ShowStatistics));
					if (ImGui::MenuItem("Show Advance Statistics", "F2", &b_ShowAdvanceStatistics));

					ImGui::EndMenu();
				}

				ImGui::Separator();
				if (ImGui::MenuItem("Scene Inspector", NULL, &b_ShowSceneInspector));
				if (ImGui::MenuItem("ImGui Demo Window", NULL, &b_ShowDemoWindow));

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

		ImGui::Begin("Perfomance", &b_ShowStatistics, window_flags);
		ImGui::Text("(%.1f FPS)", Engine::Perf::Get_FPS());
		ImGui::Text("(%.3f MS)", Engine::Perf::Get_FrameTime());
		
		ImGui::End();
			
	}

	void ImGuiLayer::ShowAdvanceStatistics()
	{
		//ImGui::SetNextWindowSize(ImVec2(800.f, 600.f));

		ImGui::Begin("Advance Perfomance Statistics", &b_ShowAdvanceStatistics);
		
		static bool update = true;
		ImGui::Checkbox("Update", &update);

		float f_FrameTime = Engine::Perf::Get_FrameTime();
		float f_FPS = Engine::Perf::Get_FPS();

		if (update)
		{
			if (FPS.size() > 100)
			{
				for (size_t i = 1; i < FPS.size(); i++)
				{
					FPS[i - 1] = FPS[i];
				}
				FPS[FPS.size() - 1] = f_FPS;

				for (size_t i = 1; i < FrameTime.size(); i++)
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

	void ImGuiLayer::ShowSceneInspector(Scene& scene)
	{
		//ImGui::SetNextWindowSize(ImVec2(550, 650));

		if (!ImGui::Begin("Scene Inspector"))
		{
			ImGui::End();
			return;
		}

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
		if (ImGui::BeginTable("##split", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Entities");
			ImGui::TableSetupColumn("Contents");
			ImGui::TableHeadersRow();

			ShowEntityObject(scene);
		}

		ImGui::EndTable();

		ImGui::PopStyleVar();
		ImGui::End();
	}

	void ImGuiLayer::ShowEntityObject(Scene& scene)
	{
		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0);
		ImGui::AlignTextToFramePadding();

		bool scene_node_open = ImGui::TreeNode("Entities", "%s", scene.sceneName, ImGuiTreeNodeFlags_DefaultOpen);

		if(scene_node_open)
		{
			for (size_t i = 0; i < scene.Entities_Data.size(); i++)
			{
				int uid = scene.Entities_Data[i].ID;
				const char* prefix = scene.Entities_Data[i].name;

				// Use object uid as identifier. Most commonly you could also use the object pointer as a base ID.
				ImGui::PushID(uid);

				// Text and Tree nodes are less high than framed widgets, using AlignTextToFramePadding() we add vertical spacing to make the tree lines equal high.
				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0);
				ImGui::AlignTextToFramePadding();

				if (ImGui::TreeNodeEx(scene.sceneName, NULL, "%s_%u", prefix, uid))
				{
					ImGui::TableSetColumnIndex(1);

					ImGui::Separator();
					ImGui::Spacing();
					ImGui::Text("Informations");
					ImGui::Spacing();
					ImGui::Separator();

					ImGui::Text("Name: %s", scene.Entities_Data[i].name);
					ImGui::Text("Entity ID: %u", scene.Entities_Data[i].ID);

					ImGui::Separator();
					ImGui::Spacing();
					ImGui::Text("Transform");
					ImGui::Spacing();
					ImGui::Separator();

					if (ImGui::TreeNodeEx("Position", NULL, "Position"))
					{
						ImGui::Text("X: ");
						ImGui::SameLine();
						ImGui::DragFloat("##xPos", &scene.Entities_Data[i].position.x, 0.005f, -100.0f, 100.0f, "%.3f");
						ImGui::Text("Y: ");
						ImGui::SameLine();
						ImGui::DragFloat("##yPos", &scene.Entities_Data[i].position.y, 0.005f, -100.0f, 100.0f, "%.3f");
						ImGui::Text("Z: ");
						ImGui::SameLine();
						ImGui::DragFloat("##zPos", &scene.Entities_Data[i].position.z, 0.005f, -100.0f, 100.0f, "%.3f");

						ImGui::TreePop();
						ImGui::Spacing();
						ImGui::Separator();
					}
					else
					{
						ImGui::SameLine();
						ImGui::Text("X: %.2f | ", scene.Entities_Data[i].position.x);
						ImGui::SameLine();
						ImGui::Text("Y: %.2f | ", scene.Entities_Data[i].position.y);
						ImGui::SameLine();
						ImGui::Text("Z: %.2f", scene.Entities_Data[i].position.z);
					}

					if (ImGui::TreeNodeEx("Rotation", NULL, "Rotation"))
					{
						ImGui::Text("X: ");
						ImGui::SameLine();
						ImGui::DragFloat("##xRot", &scene.Entities_Data[i].rotation.x, 0.005f, -100.0f, 100.0f, "%.3f");
						ImGui::Text("Y: ");
						ImGui::SameLine();
						ImGui::DragFloat("##yRot", &scene.Entities_Data[i].rotation.y, 0.005f, -100.0f, 100.0f, "%.3f");
						ImGui::Text("Z: ");
						ImGui::SameLine();
						ImGui::DragFloat("##zRot", &scene.Entities_Data[i].rotation.z, 0.005f, -100.0f, 100.0f, "%.3f");

						ImGui::TreePop();
						ImGui::Spacing();
						ImGui::Separator();
					}
					else
					{
						ImGui::SameLine();
						ImGui::Text("X: %.2f | ", scene.Entities_Data[i].rotation.x);
						ImGui::SameLine();
						ImGui::Text("Y: %.2f | ", scene.Entities_Data[i].rotation.y);
						ImGui::SameLine();
						ImGui::Text("Z: %.2f", scene.Entities_Data[i].rotation.z);
					}

					if (ImGui::TreeNodeEx("Scale", NULL, "Scale"))
					{
						ImGui::Text("X: ");
						ImGui::SameLine();
						ImGui::DragFloat("##xSca", &scene.Entities_Data[i].scale.x, 0.005f, -100.0f, 100.0f, "%.3f");
						ImGui::Text("Y: ");
						ImGui::SameLine();
						ImGui::DragFloat("##ySca", &scene.Entities_Data[i].scale.y, 0.005f, -100.0f, 100.0f, "%.3f");
						ImGui::Text("Z: ");
						ImGui::SameLine();
						ImGui::DragFloat("##zSca", &scene.Entities_Data[i].scale.z, 0.005f, -100.0f, 100.0f, "%.3f");

						ImGui::TreePop();
						ImGui::Spacing();
						ImGui::Separator();
					}
					else
					{
						ImGui::SameLine();
						ImGui::Text("X: %.2f | ", scene.Entities_Data[i].scale.x);
						ImGui::SameLine();
						ImGui::Text("Y: %.2f | ", scene.Entities_Data[i].scale.y);
						ImGui::SameLine();
						ImGui::Text("Z: %.2f", scene.Entities_Data[i].scale.z);
					}

					ImGui::Separator();
					ImGui::Spacing();
					ImGui::Text("Other Options");
					ImGui::Spacing();
					ImGui::Separator();

					if (ImGui::TreeNodeEx("Texture", NULL, "Texture"))
					{
						if (ImGui::SmallButton("Browse")) {}
						ImGui::SameLine();
						ImGui::Text("%s", scene.Entities_Data[i].texturePath);

						ImGui::TreePop();
						ImGui::Separator();
					}

					ImGui::Spacing();
					if (ImGui::TreeNodeEx("Other", NULL, "Other"))
					{
						ImGui::Text("Movement Speed: ");
						ImGui::SameLine();
						ImGui::DragFloat("##movSpeed", &scene.Entities_Data[i].MovementSpeed, 0.005f, -100.0f, 100.0f, "%.2f");
						ImGui::Text("Generate Overlap: ");
						ImGui::SameLine();
						ImGui::Checkbox("##GenOverlap", &scene.Entities_Data[i].GeneratePhysOverlap);

						ImGui::TreePop();
						ImGui::Separator();
					}
					ImGui::Spacing();
					ImGui::Separator();

					ImGui::TreePop();
				}

				ImGui::PopID();
			}

			ImGui::TreePop();
		}
	}
}