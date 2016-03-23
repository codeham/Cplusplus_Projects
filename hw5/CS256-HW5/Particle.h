// Cristian Avina Lopez
// Homework 5
// Completed 3/12/1

#include "Point.h"
#include <SDL2/SDL.h>

class Particle
{
private:
	Point gridPosition;
	Point velocity;
	double mass;
	double radius;

public:
	Particle();
	Particle(Point p, double mass);
	double getMass() const;
	double getRadius() const;
	Point getPos()const;
	Point getVelocity()const;
	void setVelocity(double x, double y);
	void positionChange();
	void setX(double);
	void setY(double);
};
