workspace "GameEngine"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}
IncludeDir["GLFW"] = "Vendors/GLFW/include"
IncludeDir["GLEW"] = "Vendors/GLEW/include"
IncludeDir["glm"] = "Vendors/glm"

project "FlappyCube"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-int/" .. outputdir)

   files 
   {
      "%{prj.name}/Sources/**"
   }

   includedirs
   {
    "Sources",
    "%{IncludeDir.GLFW}",
    "%{IncludeDir.GLEW}",
    "%{IncludeDir.glm}"
   }

   libdirs
   {
      "Vendors/GLFW/lib",
      "Vendors/GLEW/lib"
   }

   links
   {
    "GLFW.lib",
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