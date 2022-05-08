project "ImGui"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_obj/" .. outputdir .. "/%{prj.name}")

	includedirs
	{
		"../GLFW/include/",
		"../GLAD/include"
	}
	
	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imgui_tables.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp",
		"imgui_impl_opengl3.cpp",
		"imgui_impl_opengl3.h",
		"imgui_impl_glfw.cpp",
		"imgui_impl_glfw.h",
		
		"**.lua",
	}


	filter "system:windows"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "Off"
		defines
		{
		"QS_BUILD_DLL",
		}

    filter "system:linux"
        pic "On"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "Off"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
