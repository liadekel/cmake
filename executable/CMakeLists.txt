cmake_minimum_required(VERSION 3.5)
project(executable VERSION 0.1.0)
include (GNUInstallDirs)


# Search for sharedlibrary and headeronly packages.
# In case there are options passing on dependent in one of these
# it will pass only after using 'find_package'.
find_package(sharedlibrary)
find_package(headeronly)

# Create target of type executable and set it's sources list
add_executable(executable executable.c)

# link together with sharedlibrary (will add the famous -lsharedlibrary).
target_link_libraries(executable PRIVATE sharedlibrary)

# add include directory (will add the famous -Iinclude/)
target_include_directories(executable PRIVATE include/)
# equivaled to add -DTEST flag
target_compile_definitions(executable PRIVATE TEST)
target_compile_options(executable PRIVATE -Werror)

# install the final binary. CMAKE_INSTALL_BINDIR is the path
# to defined binary dir. It's value is the concatention of "CMAKE_INSTALL_PREFIX"
# and the suffix of binary dir.
install(TARGETS executable RUNTIME DESTINATION {CMAKE_INSTALL_BINDIR})
