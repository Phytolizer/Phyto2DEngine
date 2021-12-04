cmake_minimum_required(VERSION 3.21)
project("Phyto2DEngine")

add_executable("Phyto2DEngine" "main.cpp")
target_compile_features("Phyto2DEngine" PRIVATE "cxx_std_20")
