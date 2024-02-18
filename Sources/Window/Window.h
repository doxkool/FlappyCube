#pragma once

#include "Core/Logger.h"
#include "Core/OpenGL.h"

#include <GL/glew.h>
#include <glfw3.h>

namespace Engine
{
	struct Window_Params
	{
		std::string Window_Title = "";
		int Window_Width = 0;
		int Window_Height = 0;
		bool Window_Resizeable = true;
		bool FullScreen_mode = false;
	};

	struct Monitor_Spec
	{
		int MonitorID = 0;
		const char* MonitorName = "";
		bool PrimaryMonitor = true;
	};

	class Window
	{
		public:
			Window(const std::string Window_Title = "Game", const int Window_Width = 0, const int Window_Height = 0, const bool Window_Resizeable = true);

			void DetectMonitors();

			void SetWindowUserPointer(Window* window);

			void UpdateWindowTitle(const std::string Window_Title = "Game");

			int Get_WindowShouldClose();
			void Set_WindowShouldClose();

			static void Update();
			void SwapBuffer();
			static void EnableVsync(int enabled);

			bool CheckKeyboardInput(uint16_t key);
			bool CheckMouseButtonInput(uint16_t button);

			glm::vec2 GetMousePosition();
			float GetMouseX();
			float GetMouseY();

		public:
			Window_Params WinParams;
			std::vector<Monitor_Spec> MonitorsSpec;

			GLFWwindow* m_Window;

		private:
	};

	class WindowCallback
	{
		public:
			WindowCallback(Window& window);

			static void GLFWErrorCallback(int error, const char* message);
			static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);
			static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);

			static void MonitorCallback(GLFWmonitor* monitor, int event);
			static void WindowResizeCallback(GLFWwindow* Window, int Window_Width, int Window_Height);
			static void FramebufferResizeCallback(GLFWwindow* Window, int Window_Width, int Window_Height);
			static void WindowPositionCallback(GLFWwindow* Window, int xPos, int yPos);
			static void WindowMaximizeCallback(GLFWwindow* Window, int maximized);

	};
}