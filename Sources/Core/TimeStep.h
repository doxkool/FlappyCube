#pragma once

#include <glfw3.h>

namespace Engine
{
	class TimeStep
	{
	public:

		TimeStep(double time = 0.0)
			: m_Time(time)
		{}

		double GetTime() { return glfwGetTime(); }

		operator double() const { return m_Time; }

		double Get_Seconds() const { return m_Time; }
		double Get_Milliseconds() const { return m_Time * 1000; }

	private:
		double m_Time;
	};
}