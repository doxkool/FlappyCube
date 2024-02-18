#include "Camera/Camera.h"

namespace FlappyCube
{
	void Camera::PushMatrixToShader(const char* uniform)
	{
		Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE);
	}

	void Camera::OnUpdate(Window window, TimeStep ts)
	{
		//Window* state = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (window.CheckKeyboardInput(GLFW_KEY_Q))
		{
			LOG_DEBUG("test1");
		}
	}

	void Camera::MoveCamera(Direction direction)
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