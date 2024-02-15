#include "Window.h"


namespace FlappyCube
{
	static void GLFWErrorCallback(int error, const char* message)
	{
		LOG_ERROR("GLFW Error ({}): {}", error, message);
	}

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height)
	{
		OpenGL::SetViewport(Window_Width, Window_Height);

		LOG_DEBUG("Window resolution changed to : {}x{}", Window_Width, Window_Height);
	};

	Window::Window()
	{
	}

	void Window::Init(const std::string Window_Title, const int Window_Width, const int Window_Height, const bool Window_Resizeable)
	{
		Spec.Window_Title = Window_Title;
		Spec.Window_Width = Window_Width;
		Spec.Window_Height = Window_Height;
		Spec.Window_Resizeable = Window_Resizeable;

		glfwSetErrorCallback(GLFWErrorCallback);

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

		glfwSetFramebufferSizeCallback(m_Window, framebuffer_resize_callback);

		glfwMakeContextCurrent(m_Window);

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_INFO("OpenGL_API Information :");
		LOG_INFO("	{}", glVendor);
		LOG_INFO("	{}", glRenderer);
		LOG_INFO("	{}", glVersion);

		LOG_INFO("====== Instance '{}' created ======", Spec.Window_Title);

		//OpenGL::SetViewport(Window_Width, Window_Height);
		OpenGL::Viewport_Width = Window_Width;
		OpenGL::Viewport_Height = Window_Height;

		// Setting up GLFW callback for keyboard and mouse events
		glfwSetKeyCallback(m_Window, Key_Callback);
		glfwSetScrollCallback(m_Window, Mouse_Scroll_Callback);
		glfwSetMouseButtonCallback(m_Window, Mouse_Button_Callback);
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

	int Window::Get_WindowShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Set_WindowShouldClose()
	{
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
	}

	void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		
	}

	void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		
	}

	void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
	{
		
	}
}