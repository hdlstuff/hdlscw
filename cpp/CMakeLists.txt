cmake_minimum_required(VERSION 3.15)

project(hdlscw)

add_library(
    hdlscw
    INTERFACE
)

target_include_directories(
    hdlscw
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

configure_file(
   ${CMAKE_CURRENT_SOURCE_DIR}/hdlscw-config.cmake.in
   ${CMAKE_CURRENT_BINARY_DIR}/hdlscw-config.cmake @ONLY
)

install(
    TARGETS hdlscw
    EXPORT hdlscw-targets
    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/hdlscw"
)

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
    DESTINATION "${CMAKE_INSTALL_PREFIX}"
)

install(
    EXPORT hdlscw-targets
    NAMESPACE hdlscw::
    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/hdlscw"
    COMPONENT dev
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/hdlscw-config.cmake
    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/hdlscw"
)

export(PACKAGE hdlscw)
