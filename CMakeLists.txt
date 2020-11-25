cmake_minimum_required(VERSION 3.1)

project(pipeman)
set(TARGET pipeman)

set(PROJECT_INCLUDE_DIR ${PROJECT_OUTPUT_DIR}/include)
set(PROJECT_OUTPUT_DIR  ${PROJECT_BINARY_DIR}/${CMAKE_SYSTEM_PROCESSOR})

find_package(PkgConfig REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED
    gstreamer-1.0>=1.6 
    gstreamer-video-1.0>=1.6
    gstreamer-app-1.0>=1.4 
    gstreamer-controller-1.0
    )

include_directories(${GSTREAMER_INCLUDE_DIRS}
    ${GSTREAMER_VIDEO_INCLUDE_DIRS}
    ${PROJECT_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    )

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${TARGET}
  ${SOURCES}
  )

target_link_libraries(${TARGET} 
    ${GST_INCLUDE_DIRS} 
    ${GSTREAMER_LIBRARIES}
    )