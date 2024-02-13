#pragma once

#include "Camera/Camera.h"

namespace FlappyCube
{
	class OrthographicCamera : public Camera
	{
		public:
			OrthographicCamera() = default;
			OrthographicCamera(float left, float right, float bottom, float top);

			//void OnUpdate(TimeStep ts);
			
			void UpdateMatrix();

			void MoveCamera(Direction direction);

			void SetMovementSpeed(float Speed) { MovementSpeed = Speed; }
			void SetMouseRotationSpeed(float Speed) { MouseRotationSpeed = Speed; }
			void SetMousePanningSpeed(float Speed) { MousePanningSpeed = Speed; }
			void SetMouseScrollSpeed(float Speed) { MouseScrollSpeed = Speed; }

			float GetMovementSpeed() { return MovementSpeed; }
			float GetMouseRotationSpeed() { return MouseRotationSpeed; }
			float GetMousePanningSpeed() { return MousePanningSpeed; }
			float GetMouseScrollSpeed() { return MouseScrollSpeed; }

		private:

			// Variables for orthographic camera
			float left;
			float right;
			float bottom;
			float top;

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

