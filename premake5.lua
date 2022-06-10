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
        "%{prj.name}/src"
    }

    files
    {
        "%{prj.name}/src/main.cpp",
        "%{prj.name}/src/komponenty/**.h",
        "%{prj.name}/src/komponenty/**.cpp",
        "%{prj.name}/src/menu/**.h",
        "%{prj.name}/src/menu/**.cpp",
        "%{prj.name}/src/producenci/**.h",
        "%{prj.name}/src/producenci/**.cpp",
        "%{prj.name}/src/others/**.h",
        "%{prj.name}/src/others/**.cpp"
    }
    
    cppdialect "C++17"

    filter "configurations:Debug"
        optimize "Off"
    filter "configurations:Release"
        optimize "On"