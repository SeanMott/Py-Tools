workspace "PygameGen"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Gens a Pygame app
project "PygameGen"
    location "PygameGen"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.hpp"
    }
    
    --pchheader "CLpch.h"
    --pchsource "%{prj.location}/src/CLpch.cpp"

    includedirs
    {
        "%{prj.name}/src",
    }
    
    links
    {
    }
    
    defines
    {
        "_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
    filter "configurations:Debug"
        defines "PG_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "PG_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "PG_DIST"
        optimize "On"