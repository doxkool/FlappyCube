#include "Camera/Camera.h"

namespace Engine
{
	void Camera::PushMatrixToShader(const char* uniform)
	{
		Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE);
	}

	void Camera::OnUpdate(Window window, TimeStep ts)
	{

	}
}