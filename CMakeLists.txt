cmake_minimum_required(VERSION 3.12...3.22)
project(
	"Phyto2DEngine"
	LANGUAGES "CXX"
	VERSION "0.1.0"
	DESCRIPTION "A 2-dimensional 'game engine' in C++"
	HOMEPAGE_URL "https://github.com/Phytolizer/Phyto2DEngine"
)

include(FetchContent)
FetchContent_Declare(
	"glfw"
	GIT_REPOSITORY "https://github.com/glfw/glfw"
	GIT_TAG "3.3.5"
)
FetchContent_MakeAvailable("glfw")

add_subdirectory("3rd/glad")
add_subdirectory("3rd/stb")

add_library("IO" "src/IO/IO.cpp")
target_compile_features("IO" PUBLIC "cxx_std_20")
target_include_directories("IO" PUBLIC "inc")

add_library("CGLSL" "src/CGLSL/Parser.cpp")
target_link_libraries("CGLSL" PUBLIC "IO" "pcre2-8")
target_compile_features("CGLSL" PUBLIC "cxx_std_20")
target_include_directories("CGLSL" PUBLIC "inc")

add_library("Engine" "src/Engine/Shader.cpp" inc/Engine/Shader.hpp)
target_link_libraries(
	"Engine"
	PUBLIC "CGLSL"
		   "glad"
		   "glfw"
		   "stb"
)
target_include_directories("Engine" PUBLIC "inc")
target_compile_features("Engine" PUBLIC "cxx_std_20")

add_executable("TestGame" "src/TestGame/main.cpp")
target_link_libraries("TestGame" PRIVATE "Engine")
target_compile_features("TestGame" PRIVATE "cxx_std_20")
