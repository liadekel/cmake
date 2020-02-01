cmake_minimum_required(VERSION 3.5)
project(headeronly)
include(GNUInstallDirs)

# INTERFACE is from the group of (PRIVATE, PUBLIC, INTERFACE).
# when indicating an option as INTERFACE, it means that it will be relevant
# only on dependent, but not for the current project.
# This is useful for headonly libraries which are obviously not using
# their definitions.
add_library(headeronly INTERFACE)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h")


install(TARGETS ${PROJECT_NAME} EXPORT headeronlyConfig)
install(EXPORT headeronlyConfig DESTINATION share/headeronly/cmake)
export(TARGETS ${PROJECT_NAME} FILE headeronlyConfig.cmake)
