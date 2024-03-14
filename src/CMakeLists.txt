add_executable(StringSlicing
	"main.cpp" "StringSlicing.h")

if(MSVC)
	target_compile_options(StringSlicing PRIVATE /W4 /WX)
else()
	target_compile_options(StringSlicing PRIVATE -Wall -Wextra -Werror)
endif()