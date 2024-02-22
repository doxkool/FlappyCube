#include "Core/Input.h"


namespace Engine
{
	void Input::Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		
	}

	void Input::Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
	{

	}

	void Input::Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
	{

	}

	bool Input::IsKeyPressed(GLFWwindow* window, int key)
	{
		auto state = glfwGetKey(window, key);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
}