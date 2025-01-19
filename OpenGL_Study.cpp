// OpenGL_Study.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include "CircleApproximation.cpp"


int main()
{
    GLFWwindow* window;

    // Initialize Windowing System
    if (!glfwInit())
    {
        std::cout << "Init error!";
        exit(-1);
    }

    // Create a new window
    window = glfwCreateWindow(800, 600, "Hello", 0, 0);
    // If Window creation fails then terminate the process and return.
    if (!window)
    {
        std::cout << "Window creation failed!";
        glfwTerminate();
        return - 1;
    }

    // Each OpenGL application has its state within it's context. 
    // So we need to associate the current window with the current context.
    glfwMakeContextCurrent(window);

	// Create a new CircleApproximation object.
	CircleApproximation circleApproximation(0, 0, 1, 50);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1, 1, 1, 1);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

		// Draw Circle
		circleApproximation.DrawCircle();

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
