// OpenGL_Study.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include "CircleApproximation.cpp"
#include "SolarSystem.cpp"


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
    window = glfwCreateWindow(800, 800, "Hello", 0, 0);
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
	//CircleApproximation circleApproximation(0, 0, 1, 50);

    // Create a new SolarSystem object.
	SolarSystem solarSystem(50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glScalef(0.1f, 0.1f, 0.1f); // [-1, 1] --> [-10, 10] screen coordinates span.

    float earthAngle = 0;
    float moonAngle = 0;

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // The speed of rotation.
        earthAngle += 1;

        glClearColor(0, 0, 0, 0);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

		// Draw Circle
		//circleApproximation.DrawCircle();

        // Draw Solar System.
        // Draw Sun
		solarSystem.DrawPlanet(1, 1, 0);
        {
			// Draw Earth
            // We are constatnly updating our Y position, so it goes out of the screen.
			// In order to fix that we stack the matrix and then pop it.
			glPushMatrix(); // Use the Sun's matrix. Taking Sun as the center point of the matrix.

			// Rotate around the Sun.
			// We first rotate and then translate because we need to rotate first and then translate around the origin, i.e., the Sun.
            glRotatef(earthAngle, 0, 0, 1); // Rotate around Z axis.

			// Translate the Earth.
            glTranslatef(0, 5, 0); // Move 5 units on Y axis.
			glScalef(0.6, 0.6, 1); // Scale the Earth.

			solarSystem.DrawPlanet(0, 0.3, 1);

			// Draw Moon.
            {
				glPushMatrix(); //Push matrix one level down below.
                glRotatef(moonAngle, 0, 0, 1);
                glTranslatef(0, 3, 0);
				glScalef(0.5, 0.5, 1);
				solarSystem.DrawPlanet(0.5, 0.5, 0.5);
				glPopMatrix(); // Now return to the one level up, that is the previous matrix.
                moonAngle += 3;
            }

			glPopMatrix(); // Now return to the Original matrix, that is the ModelView Matrix.
        }

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
