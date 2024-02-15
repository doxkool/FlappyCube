#pragma once

#include "Logger.h"
#include "OpenGL.h"

#include <GL/glew.h>
#include <glfw3.h>

namespace FlappyCube
{
	struct Window_Spec
	{
		std::string Window_Title = "";
		int Window_Width = 0;
		int Window_Height = 0;
		bool Window_Resizeable = true;
	};

	class Window
	{
		public:
			Window();

			void Init(const std::string Window_Title = "Game", const int Window_Width = 0, const int Window_Height = 0, const bool Window_Resizeable = true);

			void UpdateWindowTitle(const std::string Window_Title = "Game");

			int Get_WindowShouldClose();
			void Set_WindowShouldClose();

			void Update();
			void SwapBuffer();

		public:
			Window_Spec Spec;

		private:
			GLFWwindow* m_Window;
	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);

	static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);
	static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);

}