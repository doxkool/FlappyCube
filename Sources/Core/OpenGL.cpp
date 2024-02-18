#include "Core/OpenGL.h"


namespace FlappyCube
{
	int OpenGL::m_FrameBuffer_Width;
	int OpenGL::m_FrameBuffer_Height;

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

	void OpenGL::SetViewport(int FrameBuffer_Width, int FrameBuffer_Height)
	{
		glViewport(0, 0, FrameBuffer_Width, FrameBuffer_Height);

		m_FrameBuffer_Width = FrameBuffer_Width;
		m_FrameBuffer_Height = FrameBuffer_Height;
	}
}