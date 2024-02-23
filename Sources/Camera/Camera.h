#pragma once

#include "Window/Window.h"
#include "Core/OpenGL.h"
#include "Core/Logger.h"
#include "Core/TimeStep.h"

#include "Core/Shader.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

namespace Engine
{
	class Camera
	{
		public:
			Camera() {}

			void OnUpdate(Window window, TimeStep ts);

			// Exports the camera matrix to a shader
			virtual void PushMatrixToShader(const char* uniform);

			void SetMovementSpeed(float Speed) { MovementSpeed = Speed; }
			void SetMouseRotationSpeed(float Speed) { MouseRotationSpeed = Speed; }
			void SetMousePanningSpeed(float Speed) { MousePanningSpeed = Speed; }
			void SetMouseScrollSpeed(float Speed) { MouseScrollSpeed = Speed; }

			float GetMovementSpeed() const { return MovementSpeed; }
			float GetMouseRotationSpeed() const { return MouseRotationSpeed; }
			float GetMousePanningSpeed() const { return MousePanningSpeed; }
			float GetMouseScrollSpeed() const { return MouseScrollSpeed; }

		public:

			// Stores the camera matrix
			glm::mat4 cameraMatrix = glm::mat4(1.0f);

			float MovementSpeed = 0.1f;
			float MouseRotationSpeed = 0.1f;
			float MousePanningSpeed = 0.1f;
			float MouseScrollSpeed = 0.1f;

			int FrameBufferWidth = 0;
			int FrameBufferHeight = 0;

			// Stores the main vectors of the camera
			glm::mat4 view = glm::mat4(1.0f);
			glm::mat4 projection = glm::mat4(1.0f);

			glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
			glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
			glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	};
}