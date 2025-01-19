#include <iostream>
#include <GLFW/glfw3.h>

class CircleApproximation
{
	public:	
	// Attributes (variables)
	float xPos, yPos, radius;
	int steps;

	// Constructor to initialize the attributes
	CircleApproximation(float xPos, float yPos, float radius, int steps)
	{
		this->xPos = xPos;
		this->yPos = yPos;
		this->radius = radius;
		this->steps = steps;
	}

	// Method (function) to display car details
	void DrawCircle()
	{
		// Area of a Circle / Number of Steps.
		// 360 (in Degrees) / 10.
		const float angle = 2 * 3.14 / steps;

		float prevX = xPos;
		float prevY = yPos;// -radius;

		for (int i = 0; i <= steps; i++)
		{
			float newX = radius * sin(angle * i);
			float newY = radius * cos(angle * i);
			glBegin(GL_TRIANGLES);
			glColor3f(0, 1, 0);
			glVertex2f(prevX, prevY);
			glVertex2f(newX, newY);
			glVertex2f(xPos, yPos);
			glEnd();
			prevX = newX;
			prevY = newY;
		}
	}
};
