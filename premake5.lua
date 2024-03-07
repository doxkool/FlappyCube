workspace "FlappySquare"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}
IncludeDir["GLFW"] = "Vendors/GLFW/include"
IncludeDir["GLEW"] = "Vendors/GLEW/include"
IncludeDir["glm"] = "Vendors/glm"
IncludeDir["spdlog"] = "Vendors/spdlog"
IncludeDir["stb_image"] = "Vendors/stb_image"
IncludeDir["imgui"] = "Vendors/imgui"

project "FlappySquare"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-int/" .. outputdir)

   files 
   {
      "Sources/**",
	  "Vendors/imgui/*"
   }

   defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
	}

   includedirs
   {
    "Sources",
    "%{IncludeDir.GLFW}",
    "%{IncludeDir.GLEW}",
    "%{IncludeDir.glm}",
	"%{IncludeDir.spdlog}",
	"%{IncludeDir.stb_image}",
	"%{IncludeDir.imgui}"
   }

   libdirs
   {
      "Vendors/GLFW/lib",
      "Vendors/GLEW/lib"
   }

   links
   {
    "glfw3_mt.lib",
    "glew32.lib",
    "opengl32.lib"
   }

   filter "system.windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "on"