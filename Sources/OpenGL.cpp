#include "OpenGL.h"

#include "Window.h"


namespace FlappyCube
{
	int OpenGL::Viewport_Width;
	int OpenGL::Viewport_Height;

	OpenGL::OpenGL()
	{
	}

	void OpenGL::Init()
	{
		glewExperimental = GL_TRUE;

		//Check GLEW is initialized correctly
		if (glewInit() != GLEW_OK)
		{
			LOG_CRITICAL("ERROR! GLEW_INIT_FAILED");
		}
		else {
			LOG_DEBUG("GLEW_INIT_SUCCESS");
		}

		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);

		//SetViewport(Window_Width, Window_Height);
	}

	void OpenGL::Set_ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGL::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void OpenGL::SetViewport(int Window_Width, int Window_Height)
	{
		glViewport(0, 0, Window_Width, Window_Height);

		Viewport_Width = Window_Width;
		Viewport_Height = Window_Height;

		//LOG_E_DEBUG("Window resolution changed to : {}x{}", Window_Width, Window_Height);
	}
}