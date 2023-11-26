cmake_minimum_required(VERSION 3.12)

project(OpenGL)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE HEADER_FILES
	${PROJECT_SOURCE_DIR}/src/*.h
)

file(GLOB_RECURSE SOURCE_FILES
	${PROJECT_SOURCE_DIR}/src/*.cpp
	${PROJECT_SOURCE_DIR}/src/*.c
)

file(GLOB_RECURSE SHADER_FILES
	${PROJECT_SOURCE_DIR}/res/shaders/*.vert
	${PROJECT_SOURCE_DIR}/res/shaders/*.frag
)

set(AllFile ${HEADER_FILES} ${SOURCE_FILES} ${SHADER_FILES})

foreach(fileItem ${AllFile})
	get_filename_component(PARENT_DIR "${fileItem}" DIRECTORY)

	string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

	string(REPLACE "/" "\\" GROUP "${GROUP}")

	set(GROUP "${GROUP}")

	source_group("${GROUP}" FILES "${fileItem}")
endforeach()

add_executable(${PROJECT_NAME} ${AllFile})

target_include_directories(${PROJECT_NAME} PUBLIC
	src
	includes
)

target_link_directories(${PROJECT_NAME} PUBLIC
	libs
)

target_link_libraries(${PROJECT_NAME} PUBLIC
	glfw3.lib
	opengl32.lib
)