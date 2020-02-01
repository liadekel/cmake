cmake_minimum_required(VERSION 3.5)
project(sharedlibrary VERSION 0.1.0)
# import install variables package
include (GNUInstallDirs)

add_library(sharedlibrary SHARED sharedlibrary.c)

target_include_directories(sharedlibrary PRIVATE include/)
target_compile_definitions(sharedlibrary INTERFACE TEST_SHAREDLIBRARY)
# we can select the build type. currently the default is non, here we config
# it to be release (can be also debug for example.)
set(CMAKE_BUILD_TYPE Release)

# when we creating a CMake project that will be used by together
# external CMake project, we will need to create config file.
# The config file contains details about the project, defenitions that will
# pass on dependent, and it will be searched when calling `find_package`.
install(TARGETS ${PROJECT_NAME}
        EXPORT sharedlibraryConfig
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(EXPORT sharedlibraryConfig DESTINATION share/sharedlibrary/cmake)
export(TARGETS ${PROJECT_NAME} FILE sharedlibraryConfig.cmake)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h")
