cmake_minimum_required(VERSION 3.29)

project(asm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)


add_compile_options(-g -m32 -fasm-blocks -fms-extensions -masm=intel)
add_link_options(-m32)

file(GLOB SUBDIRS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/src" CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

foreach(SUBDIR ${SUBDIRS})
    set(DIR_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/${SUBDIR}")

    if(IS_DIRECTORY ${DIR_PATH})
        file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${DIR_PATH}/*.cpp")

        if(SOURCES)
            add_executable(${SUBDIR} ${SOURCES})
        endif()
    endif()
endforeach()
