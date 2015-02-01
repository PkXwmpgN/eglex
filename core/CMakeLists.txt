# core library entry point

# configure egl

set(EGL_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/eglex)
set(EGL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source/eglex)
set(EGL_OPTIONS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/options/eglex)

option(USE_EGL_ERROR_CHECK "Using EGL error checking" ON)
configure_file(${EGL_OPTIONS_DIR}/options.h.in
               ${EGL_HEADER_DIR}/options.h)

set(EGL_HEADER_FILES 
    ${EGL_HEADER_DIR}/egl.h
    ${EGL_HEADER_DIR}/eglex.h
    ${EGL_HEADER_DIR}/options.h
    ${EGL_HEADER_DIR}/handle.h
    ${EGL_HEADER_DIR}/traits.h
    ${EGL_HEADER_DIR}/display.h
    ${EGL_HEADER_DIR}/configs.h
    ${EGL_HEADER_DIR}/specification.h
    ${EGL_HEADER_DIR}/specification_io.h
    ${EGL_HEADER_DIR}/specification_enum.h
    ${EGL_HEADER_DIR}/specification_type.h
    ${EGL_HEADER_DIR}/surface.h
    ${EGL_HEADER_DIR}/context.h
    ${EGL_HEADER_DIR}/error.h
    ${EGL_HEADER_DIR}/error_enum.h)

set(EGL_SOURCE_FILES
    ${EGL_SOURCE_DIR}/error.cpp
    ${EGL_SOURCE_DIR}/details.cpp)

set(EGL_FILES ${EGL_HEADER_FILES} ${EGL_SOURCE_FILES})

# configure core library

set(CORE_LIBRARY_FILES ${EGL_FILES})

source_group("core\\headers\\eglex" FILES ${EGL_HEADER_FILES})
source_group("core\\sources\\eglex" FILES ${EGL_SOURCE_FILES})

add_library(core STATIC ${CORE_LIBRARY_FILES})

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(core PUBLIC $ENV{GLES_EMULATOR_DIR}/include)
