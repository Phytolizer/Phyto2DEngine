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

add_library("IO" "inc/IO/IO.hpp" "src/IO/IO.cpp")
target_compile_features("IO" PUBLIC "cxx_std_20")
target_include_directories("IO" PUBLIC "inc")

add_library(
	"CGLSL"
	"inc/CGLSL/Internal/PCRE.hpp"
	"inc/CGLSL/Parser.hpp"
	"inc/CGLSL/ShaderSource.hpp"
	"src/CGLSL/Parser.cpp"
)
target_link_libraries("CGLSL" PUBLIC "IO" "pcre2-8")
target_compile_features("CGLSL" PUBLIC "cxx_std_20")
target_include_directories("CGLSL" PUBLIC "inc")

add_library(
	"Engine"
	"inc/Engine/IndexBuffer.hpp"
	"inc/Engine/Internal/Graphics.hpp"
	"inc/Engine/Primitives/ColoredPoint.hpp"
	"inc/Engine/Primitives/Grid.hpp"
	"inc/Engine/Primitives/Quad.hpp"
	"inc/Engine/Primitives/Triangle.hpp"
	"inc/Engine/Shader.hpp"
	"inc/Engine/Texture.hpp"
	"inc/Engine/VertexArray.hpp"
	"inc/Engine/VertexBuffer.hpp"
	"inc/Engine/Window.hpp"
	"src/Engine/IndexBuffer.cpp"
	"src/Engine/Primitives/Grid.cpp"
	"src/Engine/Primitives/Quad.cpp"
	"src/Engine/Primitives/Triangle.cpp"
	"src/Engine/Shader.cpp"
	"src/Engine/Texture.cpp"
	"src/Engine/VertexArray.cpp"
	"src/Engine/VertexBuffer.cpp"
	"src/Engine/Window.cpp"
)
target_link_libraries(
	"Engine"
	PUBLIC "CGLSL"
		   "glad"
		   "glfw"
		   "stb"
)
target_include_directories("Engine" PUBLIC "inc")
target_compile_features("Engine" PUBLIC "cxx_std_20")

add_custom_target(
	"copy_assets"
	DEPENDS "${PROJECT_SOURCE_DIR}/res"
	COMMAND "${CMAKE_COMMAND}" -E copy_directory "${PROJECT_SOURCE_DIR}/res"
			"${CMAKE_CURRENT_BINARY_DIR}/res"
)

add_executable(
	"TestGame"
	"src/TestGame/Game.cpp"
	"src/TestGame/Game.hpp"
	"src/TestGame/main.cpp"
	"src/TestGame/SpriteRenderer.cpp"
	"src/TestGame/SpriteRenderer.hpp"
)
target_link_libraries("TestGame" PRIVATE "Engine")
target_compile_features("TestGame" PRIVATE "cxx_std_20")
add_dependencies("TestGame" "copy_assets")
