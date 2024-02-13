#pragma once

#include "OpenGL.h"
#include "Logger.h"
//#include "Time.h"

#include "shader.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

namespace FlappyCube
{	
	enum Direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

	class Camera
	{
		public:
			// For creating a perspective camera
			Camera() {}

			// Exports the camera matrix to a shader
			virtual void PushMatrixToShader(const char* uniform) { Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE); }

		public:

			// Stores the camera matrix
			glm::mat4 cameraMatrix = glm::mat4(1.0f);

	};
}