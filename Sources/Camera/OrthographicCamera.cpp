#include "Camera/OrthographicCamera.h"

#include <functional>

namespace FlappyCube
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: left(left), right(right), bottom(bottom), top(top)
	{
		UpdateMatrix();
	}

	void OrthographicCamera::OnUpdate(TimeStep ts)
	{

	}

	void OrthographicCamera::UpdateMatrix()
	{
		double WidthAR = static_cast<double>(OpenGL::m_FrameBuffer_Width) / static_cast<double>(OpenGL::m_FrameBuffer_Height);
		double HeightAR = static_cast<double>(OpenGL::m_FrameBuffer_Height) / static_cast<double>(OpenGL::m_FrameBuffer_Width);

		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		projection = glm::ortho(float(-WidthAR), float(WidthAR), float(-HeightAR), float(HeightAR), 0.1f, 100.0f);
		
		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void OrthographicCamera::MoveCamera(Direction direction)
	{
		switch (direction)
		{
		case LEFT:
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * MovementSpeed;
			break;
		case RIGHT:
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * MovementSpeed;
			break;
		case UP:
			cameraPos += cameraUp * MovementSpeed;
			break;
		case DOWN:
			cameraPos -= cameraUp * MovementSpeed;
			break;
		default:
			break;
		}
	}
}