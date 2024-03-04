#include "Camera/OrthographicCamera.h"

namespace Engine
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: left(left), right(right), bottom(bottom), top(top)
	{
		UpdateMatrix();
	}

	void OrthographicCamera::OnUpdate(Window window, TimeStep ts)
	{

	}

	void OrthographicCamera::UpdateMatrix()
	{
		float Aspect = static_cast<float>(OpenGL::m_FrameBuffer_Width) / static_cast<float>(OpenGL::m_FrameBuffer_Height);

		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		projection = glm::ortho(-(left * Aspect), right * Aspect, -(bottom), top, -1.0f, 100.0f);

		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void OrthographicCamera::MoveCamera()
	{

	}
}