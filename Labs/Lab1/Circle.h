/*
* Circle.hpp
*
* Description: This class models a circle in the R2 cartesian plane.
*
* Class Invariant: The circle's radius must be greater than 0.0.
*
* Author: Steven Wong
* Creation date: September 12, 2022
*/


using namespace std;

class Circle {
  private:
	int xCoordinate;
	int yCoordinate;
	double radius;

  public:
	constexpr static const double DEFAULT_RADIUS = 10.0;

	// Default constructor
	Circle();

	// Parameterized constructor
	Circle(int x, int y, double radius);

	// Return the circle's centre x-coordinate
	int getX() const;

	// Return the circle's centre y-coordinate
	int getY() const;

	// Return the circle's radius
	double getRadius() const;

	// Move the circle the given horizontal and vertical distances
	void move(int horiz, int vert);

	// Change the circle's radius to r, or to 10.0 if r is invalid
	void setRadius(double r);

	// Compute and returns the circle's area
	double computeArea() const;

	// Display the circle's data members like this: x = 0, y = 11, radius = 0.2
	void displayCircle() const;

	// Returns true if c intersects the calling circle
	bool intersect(Circle c) const;
};

