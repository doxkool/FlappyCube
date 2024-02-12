#include "Main.h"

int main(int argc, char* argv[])
{
	FlappyCube::Logger::Init();
	FlappyCube::Init_OpenGL();
	FlappyCube::Init_GLFW();
	FlappyCube::RunGameLoop();

	return 0;
}

namespace FlappyCube
{

	int Init_OpenGL()
	{
		//Check GLEW is initialized correctly
		if (glewInit() != GLEW_OK)
		{
			//LOG_CRITICAL("ERROR! GLEW_INIT_FAILED");
		}
		else {
			//LOG_DEBUG("GLEW_INIT_SUCCESS");
		}

#ifdef ENGINE_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		glDebugMessageCallback(OpenGL_DebugMsgCallback, nullptr);
#endif

		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);

		return 0;
	}

	int Init_GLFW()
	{
		return 0;
	}

	void RunGameLoop()
	{
		while (true)
		{
			// Run Game code here
		}
	}
}