cmake_minimum_required(VERSION 3.5)
project(libso VERSION 0.1.0)
include (GNUInstallDirs)

add_library(libso SHARED libso.c)

target_include_directories(libso PRIVATE include/)
target_compile_definitions(libso INTERFACE TEST_LIBSO)
set(CMAKE_BUILD_TYPE Release)

install(TARGETS ${PROJECT_NAME}
        EXPORT libsoConfig
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(EXPORT libsoConfig DESTINATION share/libso/cmake)
export(TARGETS ${PROJECT_NAME} FILE libsoConfig.cmake)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h")
