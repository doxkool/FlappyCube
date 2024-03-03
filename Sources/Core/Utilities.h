#pragma once
#include "Core/TimeStep.h"

namespace Engine
{
	class Perf
	{
	public:
		// Run this at the START of what you want to monitor.
		static void StartPerfCounter(TimeStep ts) { m_Frames++; m_Start_Time = ts.GetTime(); }
		// Run this at the END of what you want to monitor.
		static void EndPerfCounter() { m_End_Time = m_Start_Time; m_Frames = 0; }
		// Return the frames per seconds.
		static double Get_FPS() { return (m_Frames / (m_Start_Time - m_End_Time)); }
		// Return the last frame time in mililseconds.
		static double Get_FrameTime() { return ((m_Start_Time - m_End_Time) * 1000); }

		static double Get_DeltaTime() { return (m_Start_Time - m_End_Time); }

	public:
		static float m_Start_Time;
		static float m_End_Time;
		static int m_Frames;
	};
}