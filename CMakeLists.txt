cmake_minimum_required(VERSION 3.12...3.22)
project(
    "Phyto2DEngine"
    LANGUAGES "CXX"
    VERSION "0.1.0"
    DESCRIPTION "A 2-dimensional 'game engine' in C++"
    HOMEPAGE_URL "https://github.com/Phytolizer/Phyto2DEngine"
)

add_subdirectory("3rd/glad")

add_executable("Phyto2DEngine" "main.cpp")
target_compile_features("Phyto2DEngine" PRIVATE "cxx_std_20")
