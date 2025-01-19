#include <iostream>
#include <GLFW/glfw3.h>

class SolarSystem
{
public:
	// Attributes (variables)
	int steps = 50;

	// Constructor to initialize the attributes
	SolarSystem(int steps)
	{
		this->steps = steps;
	}

	// Method (function) to display car details
	void DrawPlanet(float red, float green, float blue)
	{
		float radius = 1;
		const float angle = 3.14 * 2 / steps;
		float oldX = 0;
		float oldY = 1;

		for (int i = 0; i <= steps; i++)
		{
			float newX = radius * sin(angle * i);
			float newY = -radius * cos(angle * i);

			glColor3f(red, green, blue);
			glBegin(GL_TRIANGLES);
			glVertex3f(0, 0, 0);	
			glVertex3f(oldX, oldY, 0);
			glVertex3f(newX, newY, 0);
			glEnd();

			oldX = newX;
			oldY = newY;
		}
	}
};