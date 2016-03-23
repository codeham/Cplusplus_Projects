// Cristian Avina Lopez
// Homework 5
// Completed 3/12/1

#include <SDL2/SDL.h>

class Point
{
	friend class Particle;
private:
	double x;
	double y;

public:
	Point();
	Point(double, double);
	//Getters
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;

	
};