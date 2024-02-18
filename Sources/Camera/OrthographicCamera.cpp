#include "Camera/OrthographicCamera.h"

namespace FlappyCube
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: left(left), right(right), bottom(bottom), top(top)
	{
		UpdateMatrix();
	}

	void OrthographicCamera::OnUpdate(Window window, TimeStep ts)
	{
		if (window.CheckKeyboardInput(GLFW_KEY_W))
		{
			MoveCamera(UP);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_A))
		{
			MoveCamera(LEFT);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_S))
		{
			MoveCamera(DOWN);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_D))
		{
			MoveCamera(RIGHT);
		}

		if (window.CheckKeyboardInput(GLFW_KEY_Z))
		{
			MoveCamera(FORWARD);
		}
		if (window.CheckKeyboardInput(GLFW_KEY_X))
		{
			MoveCamera(BACKWARD);
		}

	}

	void OrthographicCamera::UpdateMatrix()
	{
		float Aspect = static_cast<float>(OpenGL::m_FrameBuffer_Width) / static_cast<float>(OpenGL::m_FrameBuffer_Height);

		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		projection = glm::ortho(left * Aspect / zoom, right * Aspect / zoom, bottom / zoom,top / zoom, 0.1f, 100.0f);
		
		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void OrthographicCamera::MoveCamera(Direction direction)
	{
		switch (direction)
		{
		case FORWARD:
			zoom += 0.1;
			break;
		case BACKWARD:
			if(zoom >= 0){ zoom -= 0.1; }
			break;
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