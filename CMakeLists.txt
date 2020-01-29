cmake_minimum_required(VERSION 3.15)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(OpenGLParticleSystem)

add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(imgui)

execute_process(COMMAND lua.exe ${CMAKE_CURRENT_SOURCE_DIR}/glLoadGen/LoadGen.lua -style=pointer_cpp -spec=gl -version=4.3 -profile= core core_4_3
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(OpenGLParticleSystem ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp ${CMAKE_CURRENT_BINARY_DIR}/gl_core_4_3.hpp ${CMAKE_CURRENT_BINARY_DIR}/gl_core_4_3.cpp)

target_link_libraries(OpenGLParticleSystem PRIVATE
	glfw
	opengl32
	glm
	imgui
)