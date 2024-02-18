#pragma once

#include "Camera/Camera.h"

#include "Window/Window.h"

namespace FlappyCube
{
	class OrthographicCamera : public Camera
	{
		public:
			OrthographicCamera(float left, float right, float bottom, float top);
			
			void UpdateMatrix();

		private:
			// Variables for orthographic camera
			float left;
			float right;
			float bottom;
			float top;
	};
}

