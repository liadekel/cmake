cmake_minimum_required(VERSION 3.5)
project(headeronly)
include(GNUInstallDirs)

add_library(headeronly INTERFACE)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
        FILES_MATCHING PATTERN "*.h")


install(TARGETS ${PROJECT_NAME} EXPORT headeronlyConfig)
install(EXPORT headeronlyConfig DESTINATION share/headeronly/cmake)
export(TARGETS ${PROJECT_NAME} FILE headeronlyConfig.cmake)
