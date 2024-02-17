#include "Window/Window.h"


namespace FlappyCube
{
	Window::Window(const std::string Window_Title, const int Window_Width, const int Window_Height, const bool Window_Resizeable)
	{
		Spec.Window_Title = Window_Title;
		Spec.Window_Width = Window_Width;
		Spec.Window_Height = Window_Height;
		Spec.Window_Resizeable = Window_Resizeable;

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


		m_Window = glfwCreateWindow(Spec.Window_Width, Spec.Window_Height, Spec.Window_Title.c_str(), NULL, NULL);

		glfwSetWindowMonitor(m_Window, NULL, (GetSystemMetrics(SM_CXSCREEN) / 2) - (Spec.Window_Width / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (Spec.Window_Height / 2), Spec.Window_Width, Spec.Window_Height, GLFW_DONT_CARE);
		LOG_INFO("New window resolution : {}x{}", Spec.Window_Width, Spec.Window_Height);

		glfwMakeContextCurrent(m_Window);

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_INFO("OpenGL_API Information :");
		LOG_INFO("	{}", glVendor);
		LOG_INFO("	{}", glRenderer);
		LOG_INFO("	{}", glVersion);

		LOG_INFO("====== Instance '{}' created ======", Spec.Window_Title);

		OpenGL::m_FrameBuffer_Width = Window_Width;
		OpenGL::m_FrameBuffer_Height = Window_Height;
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
}