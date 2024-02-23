#pragma once

#include "Camera/Camera.h"

#include "Window/Window.h"

namespace Engine
{
	class PerspectiveCamera : public Camera
	{
		public:
			PerspectiveCamera() = default;
			PerspectiveCamera(float FOVdeg, float nearPlane, float farPlane);

			void OnUpdate(TimeStep ts);

			// Exports the camera matrix to a shader
			virtual void PushMatrixToShader(const char* uniform) override;
			
			void UpdateMatrix();

			void CheckForInput(Window window);

			void MoveCamera();

			void SetMovementSpeed(float Speed) { MovementSpeed = Speed; }
			void SetMouseRotationSpeed(float Speed) { MouseRotationSpeed = Speed; }
			void SetMousePanningSpeed(float Speed) { MousePanningSpeed = Speed; }
			void SetMouseScrollSpeed(float Speed) { MouseScrollSpeed = Speed; }

			float GetMovementSpeed() { return MovementSpeed; }
			float GetMouseRotationSpeed() { return MouseRotationSpeed; }
			float GetMousePanningSpeed() { return MousePanningSpeed; }
			float GetMouseScrollSpeed() { return MouseScrollSpeed; }

		private:

			// Variables for Perspective camera
			float FOVdeg;
			float nearPlane;
			float farPlane;

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

