#include "Camera/OrthographicCamera.h"

namespace FlappyCube
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: left(left), right(right), bottom(bottom), top(top)
	{
		UpdateMatrix();
	}

	void OrthographicCamera::UpdateMatrix()
	{
		FrameBufferWidth = OpenGL::Viewport_Width;
		FrameBufferHeight = OpenGL::Viewport_Height;

		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		projection = glm::ortho(left, right, bottom, top, 0.1f, 100.0f);
		
		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void OrthographicCamera::MoveCamera(Direction direction)
	{
		//switch (direction)
		//{
		//case Engine::LEFT:
		//	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * MovementSpeed;
		//	break;
		//case Engine::RIGHT:
		//	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * MovementSpeed;
		//	break;
		//case Engine::UP:
		//	cameraPos += cameraUp * MovementSpeed;
		//	break;
		//case Engine::DOWN:
		//	cameraPos -= cameraUp * MovementSpeed;
		//	break;
		//default:
		//	break;
		//}
	}
}