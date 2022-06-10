workspace "component_storage"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}"

project "component_storage"
    location "component_storage"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" ..outputdir)
    objdir ("bin-int/" ..outputdir)
    includedirs {
        "%{prj.name}"
    }

    files
    {
        "main.cpp",
        "%{prj.name}/komponenty/**.h",
        "%{prj.name}/komponenty/**.cpp",
        "%{prj.name}/menu/**.h",
        "%{prj.name}/menu/**.cpp",
        "%{prj.name}/producenci/**.h",
        "%{prj.name}/producenci/**.cpp",
        "%{prj.name}/others/**.h",
        "%{prj.name}/others/**.cpp"
    }
    
    filter "configurations:Debug"
        optimize "Off"
    filter "configurations:Release"
        optimize "On"