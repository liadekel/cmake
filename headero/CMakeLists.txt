cmake_minimum_required(VERSION 3.5)
project(headero)

add_library(headero INTERFACE)

install(TARGETS ${PROJECT_NAME} EXPORT headeroConfig)
install(EXPORT headeroConfig DESTINATION share/headero/cmake)
export(TARGETS ${PROJECT_NAME} FILE headeroConfig.cmake)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h")
