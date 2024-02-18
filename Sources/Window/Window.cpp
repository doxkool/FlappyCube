#include "Window/Window.h"

namespace FlappyCube
{
	Window::Window(const std::string Window_Title, const int Window_Width, const int Window_Height, const bool Window_Resizeable)
	{
		WinParams.Window_Title = Window_Title;
		WinParams.Window_Width = Window_Width;
		WinParams.Window_Height = Window_Height;
		WinParams.Window_Resizeable = Window_Resizeable;

		glfwSetErrorCallback(WindowCallback::GLFWErrorCallback);

		//INIT GLFW
		if (!glfwInit())
		{
			LOG_CRITICAL("ERROR::GLFW_INIT_FAILED");
			glfwTerminate();
		}
		else {
			LOG_DEBUG("GLFW initialization completed.");
		}

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_RESIZABLE, true);

		//DetectMonitors();

		m_Window = glfwCreateWindow(WinParams.Window_Width, WinParams.Window_Height, WinParams.Window_Title.c_str(), NULL, NULL);

		glfwSetWindowMonitor(m_Window, NULL, (GetSystemMetrics(SM_CXSCREEN) / 2) - (WinParams.Window_Width / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (WinParams.Window_Height / 2), WinParams.Window_Width, WinParams.Window_Height, GLFW_DONT_CARE);
		LOG_INFO("New window resolution : {}x{}", WinParams.Window_Width, WinParams.Window_Height);

		glfwMakeContextCurrent(m_Window);

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_INFO("OpenGL_API Information :");
		LOG_INFO("	{}", glVendor);
		LOG_INFO("	{}", glRenderer);
		LOG_INFO("	{}", glVersion);

		LOG_INFO("====== Instance '{}' created ======", WinParams.Window_Title);

		OpenGL::m_FrameBuffer_Width = Window_Width;
		OpenGL::m_FrameBuffer_Height = Window_Height;
	}

	void Window::DetectMonitors()
	{
	// TODO : THIS MAKE THE APPLICATION CRASH
		int numOfMonitor;
		GLFWmonitor* PrimaryMonitor = glfwGetPrimaryMonitor();
		GLFWmonitor** monitors = glfwGetMonitors(&numOfMonitor);

		for (int i = 0; i < numOfMonitor; i++)
		{
			MonitorsSpec[i].MonitorID = i;
			MonitorsSpec[i].MonitorName = glfwGetMonitorName(PrimaryMonitor);
		}
	}

	void Window::SetWindowUserPointer(Window* window)
	{
		glfwSetWindowUserPointer(m_Window, window);
	}

	void Window::UpdateWindowTitle(const std::string NewWindowTitle)
	{
		glfwSetWindowTitle(m_Window, NewWindowTitle.c_str());
	}

	void Window::Update()
	{
		glfwPollEvents();
	}

	void Window::SwapBuffer()
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::EnableVsync(int enabled)
	{
		glfwSwapInterval(enabled);
		LOG_DEBUG("vSync set to : {}", enabled);
	}

	int Window::Get_WindowShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Set_WindowShouldClose()
	{
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
	}

	bool Window::CheckKeyboardInput(uint16_t key)
	{
		auto state = glfwGetKey(m_Window, key);
		return state;
	}

	bool Window::CheckMouseButtonInput(uint16_t button)
	{
		auto state = glfwGetMouseButton(m_Window, button);
		return state;
	}

	glm::vec2 Window::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(m_Window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float Window::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Window::GetMouseY()
	{
		return GetMousePosition().y;
	}
}