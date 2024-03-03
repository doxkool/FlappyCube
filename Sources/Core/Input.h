#pragma once

#include "Core/Events.h"

#include "Window/Window.h"

#include "Renderer/ImGuiLayer.h"

namespace Engine
{
	class Input
	{
	public:
		Input() {}

		static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);
		static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);

		static bool IsKeyPressed(GLFWwindow* window, int key);

	private:

	};
}