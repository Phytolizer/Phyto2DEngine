cmake_minimum_required(VERSION 3.12...3.22)

project(
    "glad"
    LANGUAGES "C"
    DESCRIPTION "Bindings for OpenGL"
    HOMEPAGE_URL "https://glad.dav1d.de"
)

add_library("glad" "src/glad.c")
target_include_directories("glad" PUBLIC "include")
