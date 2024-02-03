workspace "FishingGame"
	architecture "x64"
	startproject "game"
	location "game"
	
	configurations
	{
		"Debug",
		"Release",
	}

-- output directory name	
outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
		
-------------------------------------------------------------------------------------
------------------------ Game project -----------------------------------------------		
-------------------------------------------------------------------------------------
		
project "game"
	kind "ConsoleApp"	
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("%{prj.name}/bin/" .. outputDir)
	objdir ("%{prj.name}/obj/" .. outputDir)

	files
	{
		"header/**.h",
		"code/**.cpp"	
	}
	
	includedirs
	{
		"header"
	}
		
	filter "system:windows"
		systemversion "latest"
				
-- filter configuration of VS
	filter "configurations:Debug"
		defines "GAME_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "GAME_RELEASE"
		runtime "Release"
		optimize "on"