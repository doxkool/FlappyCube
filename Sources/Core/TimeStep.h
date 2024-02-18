#pragma once

#include <glfw3.h>

namespace Engine
{
	class TimeStep
	{
	public:

		TimeStep(float time = 0.0f)
			: m_Time(time)
		{}

		float GetTime() { return glfwGetTime(); }

		operator float() const { return m_Time; }

		float Get_Seconds() const { return m_Time; }
		float Get_Milliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};
}