cmake_minimum_required(VERSION 3.5)
project(executable VERSION 0.1.0)

find_package(sharedlibrary)
find_package(headeronly)

add_executable(executable executable.c)

target_link_libraries(executable PRIVATE sharedlibrary)

target_include_directories(executable PRIVATE include/)
target_compile_definitions(executable PRIVATE TEST)
target_compile_options(executable PRIVATE -Werror)
install(TARGETS executable RUNTIME DESTINATION bin)
