cmake_minimum_required(VERSION 3.5)
project(exec VERSION 0.1.0)

find_package(libso)
find_package(headero)

add_executable(exec exec.c)

target_link_libraries(exec PRIVATE libso)

target_include_directories(exec PRIVATE include/)
target_compile_definitions(exec PRIVATE TEST)
target_compile_options(exec PRIVATE -Werror)
install(TARGETS exec RUNTIME DESTINATION bin)
