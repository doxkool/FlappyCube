#pragma once

#include "Camera/Camera.h"

#include "Window/Window.h"

namespace Engine
{
	class OrthographicCamera : public Camera
	{
		public:
			OrthographicCamera(float left, float right, float bottom, float top);

			void OnUpdate(Window window, TimeStep ts);
			
			void UpdateMatrix();

			virtual void MoveCamera(Direction direction);

		private:
			// Variables for orthographic camera
			float left;
			float right;
			float bottom;
			float top;

			float zoom = 1;
	};
}

