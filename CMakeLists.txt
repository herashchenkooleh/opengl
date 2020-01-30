cmake_minimum_required(VERSION 3.15)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(OpenGLParticleSystem)

add_subdirectory(glfw)
add_subdirectory(glm)

file( GLOB 3rdPartyImGui
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/imgui_impl_opengl3.h
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/imgui_impl_opengl3.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/imgui_impl_glfw.h
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/imgui_impl_glfw.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h
)
source_group(3rdParty\\ImGui FILES ${3rdPartyImGui})

execute_process(COMMAND lua.exe ${CMAKE_CURRENT_SOURCE_DIR}/glLoadGen/LoadGen.lua -style=pointer_cpp -spec=gl -version=4.3 -profile= core core_4_3
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(OpenGLParticleSystem ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
${CMAKE_CURRENT_BINARY_DIR}/gl_core_4_3.hpp
${CMAKE_CURRENT_BINARY_DIR}/gl_core_4_3.cpp
${3rdPartyImGui})

target_include_directories(OpenGLParticleSystem PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/imgui
	${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples
)

target_link_libraries(OpenGLParticleSystem PRIVATE
	glfw
	opengl32
	glm
)