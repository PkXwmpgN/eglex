# surface example desktop entry point

set(EXAMPLE_SOURCE_FILES 
   source/main.cpp
   source/native.cpp
   source/gles2.cpp)
source_group(source FILES ${EXAMPLE_SOURCE_FILES} ${EXAMPLE_HEADER_FILES})

add_executable(surface ${EXAMPLE_SOURCE_FILES} ${EXAMPLE_HEADER_FILES})

target_link_libraries(surface core)

set(GLES_LIBRARIES
	$ENV{GLES_EMULATOR_DIR}/lib/libEGL.lib
	$ENV{GLES_EMULATOR_DIR}/lib/libGLESv2.lib)
target_link_libraries(surface ${GLES_LIBRARIES})

