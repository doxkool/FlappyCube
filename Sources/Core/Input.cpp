#include "Core/Input.h"


namespace Engine
{
	void Input::Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto state = glfwGetKey(window, key);

		if (state == GLFW_PRESS || state == GLFW_REPEAT)
		{
			if (key == GLFW_KEY_F1)
			{
				Window::EnableVsync(1);
			}
			if (key == GLFW_KEY_F2)
			{
				Window::EnableVsync(0);
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