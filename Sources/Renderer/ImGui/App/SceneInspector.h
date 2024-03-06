#pragma once

#include "Scene/Scene.h"
#include "Scene/Entities/EntityTypes.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Engine
{
	class SceneInspector
	{
	public:
		SceneInspector(Scene* scene);

	private:
		void ShowEntityObject(Scene* scene);

		bool b_2DcoordinatesOnly = true;
	};
}