#include "Camera/PerspectiveCamera.h"

namespace FlappyCube
{
	PerspectiveCamera::PerspectiveCamera(float FOVdeg, float nearPlane, float farPlane)
		: FOVdeg(FOVdeg), nearPlane(nearPlane), farPlane(farPlane)
	{
		UpdateMatrix();
	}

	void PerspectiveCamera::OnUpdate(TimeStep ts)
	{

	}

	void PerspectiveCamera::UpdateMatrix()
	{
		FrameBufferWidth = OpenGL::m_FrameBuffer_Width;
		FrameBufferHeight = OpenGL::m_FrameBuffer_Height;

		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		// Adds Perspective to the scene
		projection = glm::perspective(glm::radians(FOVdeg), (float)FrameBufferWidth / FrameBufferHeight, nearPlane, farPlane);

		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void PerspectiveCamera::PushMatrixToShader(const char* uniform)
	{
		// Exports camera matrix
		Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE);
	}

	void PerspectiveCamera::MoveCamera(Direction direction)
	{
		switch (direction)
		{
		case FORWARD:
			cameraPos += cameraFront * MovementSpeed;
			break;
		case BACKWARD:
			cameraPos -= cameraFront * MovementSpeed;
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