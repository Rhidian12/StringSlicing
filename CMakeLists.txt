#root cmake
cmake_minimum_required(VERSION 3.22)

Project(StringSlicingProposal VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
	add_compile_definitions(/W4 /WX)
else()
	add_compile_definitions(-Wall -Wextra -Werror)
endif()

add_subdirectory(src)