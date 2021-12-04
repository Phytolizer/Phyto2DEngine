cmake_minimum_required(VERSION 3.12...3.22)

project(
	"stb"
	LANGUAGES "C"
	DESCRIPTION "Single-file header-only libraries for C"
	HOMEPAGE_URL "https://github.com/nothings/stb"
)

add_library("stb" "stb_image.c" "stb_vorbis.c")
target_include_directories("stb" PUBLIC "${PROJECT_SOURCE_DIR}")
