#pragma once

#include "Scene/Scene.h"

#include "Core/Utilities.h"

#include <glfw3.h>
#include <vector>
#include <math.h>
#include <stdio.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Engine
{
	class ImGuiLayer
	{
		public:
			ImGuiLayer() {}

			static void Init(GLFWwindow* window);
			static void NewFrame();
			static void Render(Scene& scene);

			static void ShowMenuBar();
			static void ShowStatistics();
			static void ShowAdvanceStatistics();
			static void ShowEntityObject(Scene& scene);

			static void ShowSceneInspector(Scene& scene);

			static bool b_ShowDemoWindow;

			static bool b_ShowStatistics;
			static bool b_ShowAdvanceStatistics;
			static bool b_ShowMenuBar;
			static bool b_ShowSceneInspector;

		private:

			static std::vector<float> FrameTime;
			static std::vector<float> FPS;
	};
}