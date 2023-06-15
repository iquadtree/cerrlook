cmake_minimum_required (VERSION 3.8)

project ("cerrlook" VERSION 0.1.0)

set (CMAKE_C_STANDARD 99)

if (NOT WIN32)
	message(FATAL_ERROR "Only Windows supported as target platform")
endif(NOT WIN32)

add_executable (cerrlook cerrlook.c)

target_compile_definitions(cerrlook PUBLIC WIN32_LEAN_AND_MEAN)
