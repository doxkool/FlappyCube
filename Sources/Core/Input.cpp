#include "Core/Input.h"


namespace Engine
{
	bool b_ToggleMainMenuBarEnabled = false;
	bool b_ToggleStatsEnabled = false;
	bool b_ToggleAdvanceStatsEnabled = false;
	bool b_ToggleSceneInspector = false;

	void Input::Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto state = glfwGetKey(window, key);

		if (state == GLFW_PRESS || state == GLFW_REPEAT)
		{
			if (key == GLFW_KEY_ESCAPE)
			{
				if (!b_ToggleMainMenuBarEnabled)ImGuiLayer::b_ShowMenuBar = true, b_ToggleMainMenuBarEnabled = true; else ImGuiLayer::b_ShowMenuBar = false, b_ToggleMainMenuBarEnabled = false;
			}

			if (key == GLFW_KEY_F1)
			{
				if (!b_ToggleStatsEnabled)ImGuiLayer::b_ShowStatistics = true, b_ToggleStatsEnabled = true; else ImGuiLayer::b_ShowStatistics = false, b_ToggleStatsEnabled = false;
			}

			if (key == GLFW_KEY_F2)
			{
				if (!b_ToggleAdvanceStatsEnabled)ImGuiLayer::b_ShowAdvanceStatistics = true, b_ToggleAdvanceStatsEnabled = true; else ImGuiLayer::b_ShowAdvanceStatistics = false, b_ToggleAdvanceStatsEnabled = false;
			}
			
			if (key == GLFW_KEY_F10)
			{
				Window::EnableVsync(1);
			}

			if (key == GLFW_KEY_F11)
			{
				if (!b_ToggleSceneInspector)ImGuiLayer::b_ShowSceneInspector = true, b_ToggleSceneInspector = true; else ImGuiLayer::b_ShowSceneInspector = false, b_ToggleSceneInspector = false;
			}
		}
		
		ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
	}

	void Input::Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
	}

	void Input::Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
	{
		ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
	}

	bool Input::IsKeyPressed(GLFWwindow* window, int key)
	{
		auto state = glfwGetKey(window, key);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
}