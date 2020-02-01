cmake_minimum_required(VERSION 3.5)
project(sharedlibrary VERSION 0.1.0)
include (GNUInstallDirs)

add_library(sharedlibrary SHARED sharedlibrary.c)

target_include_directories(sharedlibrary PRIVATE include/)
target_compile_definitions(sharedlibrary INTERFACE TEST_SHAREDLIBRARY)
set(CMAKE_BUILD_TYPE Release)

install(TARGETS ${PROJECT_NAME}
        EXPORT sharedlibraryConfig
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(EXPORT sharedlibraryConfig DESTINATION share/sharedlibrary/cmake)
export(TARGETS ${PROJECT_NAME} FILE sharedlibraryConfig.cmake)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h")
