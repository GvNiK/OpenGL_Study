#include <iostream>
#include <GLFW/glfw3.h>

#pragma once
class GLFWSkeleton
{
	int main()
	{
		GLFWwindow* window;

		// Initialize Windowing System.
		// If initialization fails then print an error.
		if (!glfwInit())
		{
			std::cout << "Init error!";
			exit(-1);
		}

		window = glfwCreateWindow(800, 800, "Solar System", 0, 0);
		// If Window creation fails then terminate the process and return.
		if (!window)
		{
			std::cout << "Window creation failed!";
			glfwTerminate();
			return -1;
		}

		// Each OpenGL application has its state within it's context.
		// So we need to associate the current window with the current context.
		glfwMakeContextCurrent(window);

		// Render loop.
		while (!glfwWindowShouldClose(window))
		{
			glClearColor(1, 1, 1, 1);

			// Clear the screen.
			glClear(GL_COLOR_BUFFER_BIT);

			// Responsible for swapping the front and back buffers of a window.
			// Displays the fully rendered frame by swapping the front and back buffers.
			glfwSwapBuffers(window);

			// Process and respond to events.
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();

		// Executed Successfully.
		return 0;
	}
};

