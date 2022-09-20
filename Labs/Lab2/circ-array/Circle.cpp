/* Circle.cpp
 *
 * Description: This class models a circle in the R2 cartesian plane.
 * 
 * Class Invariant: The circle's radius must be greater than 0.0.
 *
 * Author: Steven Wong
 * Creation date: September 12, 2022
 */

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

// Default constructor
Circle::Circle() : xCoordinate(0), yCoordinate(0), radius(10.0) {}

// Parameterized constructor
Circle::Circle(int x, int y, double radius)
{
    // If the radius is less than 0, set it to 0
    if (radius <= 0.0) radius = DEFAULT_RADIUS;

    // Initialize the class members
    this->xCoordinate = x;
    this->yCoordinate = y;
    this->radius = radius;
}

// Return the circle's centre x-coordinate
int Circle::getX() const
{
    return xCoordinate;
}

// 	// Return the circle's centre y-coordinate
int Circle::getY() const
{
    return yCoordinate;
}

// 	Return the circle's radius
double Circle::getRadius() const
{
    return radius;
}

// Move the circle the given horizontal and vertical distances
void Circle::move(int horiz, int vert)
{
    xCoordinate += horiz;
    yCoordinate += vert;
}

// Change the circle's radius to r, or to 10.0 if r is invalid
void Circle::setRadius(double r)
{
    // If the passed radius is invalid, set the circle's radius to the default value
    if (r <= 0.0) r = DEFAULT_RADIUS;
    radius = r;
}

// Compute and returns the circle's area
double Circle::computeArea() const
{
    return M_PI*radius*radius;
}

// Display the circle's data members like this: x = 0, y = 11, radius = 0.2
void Circle::displayCircle() const
{
    cout << "x = " << getX() << ", y = " << getY() << ", radius = " << getRadius() << endl;
}

// Returns true if c intersects the calling circle
bool Circle::intersect(Circle c) const
{
    // Calculate the distance between the two circles centers
    double distance = sqrt(pow(c.getX() - getX(), 2) + pow(c.getY() - getY(), 2));

    // If the distance is 0, and r1 == r2, then the circles are the same 
    if (distance == 0 && getRadius() == c.getRadius())
    {
        return false;
    }
    // If distance is greater than the sum of the two radii, they are separate
    else if (distance > (getRadius() + c.getRadius()))
    {
        return false;
    }
    // If the distance is less than the absolute value of r1-r2, the circles are concentric
    else if (distance < abs(getRadius() - c.getRadius()))
    {
        return false;
    }
    else 
    {
        return true;
    }
}