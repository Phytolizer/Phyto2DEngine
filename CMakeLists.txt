cmake_minimum_required(VERSION 3.12...3.22)
project(
    "Phyto2DEngine"
    LANGUAGES "CXX"
    VERSION "0.1.0"
    DESCRIPTION "A 2-dimensional 'game engine' in C++"
    HOMEPAGE_URL "https://github.com/Phytolizer/Phyto2DEngine"
)

add_subdirectory("3rd/glad")
add_subdirectory("3rd/stb")

add_library("Engine" "src/Engine/Shader.cpp")
target_link_libraries("Engine" PUBLIC "glad" "stb")
target_include_directories("Engine" PUBLIC "inc")

add_executable("TestGame" "src/TestGame/main.cpp")
target_link_libraries("TestGame" PRIVATE "Engine")
target_compile_features("TestGame" PRIVATE "cxx_std_20")
