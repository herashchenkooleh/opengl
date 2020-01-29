#include "gl_core_4_3.hpp"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include "imgui.h"

int main()
{
	if (!glfwInit())
	{
		printf("Failed initialize GLFW!.");
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, gl::TRUE_);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	glfwMakeContextCurrent(window);

	gl::exts::LoadTest didLoad = gl::sys::LoadFunctions();
	if(!didLoad)
	{
		printf("Failed initialize opengl functions!");
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	return EXIT_SUCCESS;
}