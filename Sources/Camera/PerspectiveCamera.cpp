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
		FrameBufferWidth = OpenGL::Viewport_Width;
		FrameBufferHeight = OpenGL::Viewport_Height;

		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		// Adds perspective to the scene
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
		//switch (direction)
		//{
		//case Engine::FORWARD:
		//	cameraPos += cameraFront * MovementSpeed;
		//	break;
		//case Engine::BACKWARD:
		//	cameraPos -= cameraFront * MovementSpeed;
		//	break;
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