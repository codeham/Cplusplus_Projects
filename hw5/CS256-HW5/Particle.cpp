// Cristian Avina Lopez
// Homework 5
// Completed 3/12/1

#include "Particle.h"
#include <stdlib.h> 
#include <cmath>

Particle::Particle(Point p, double mass)
{
	radius = mass/pow(10,13);
	gridPosition = p;
	this->mass = mass;
}

double Particle::getMass()const
{
	return mass;
}

double Particle::getRadius()const
{
	//Randomize the Radius x > 0
	return radius;
}

Point Particle::getPos()const
{
	return gridPosition;
}

Point Particle::getVelocity()const
{
	return velocity;
}

void Particle::setVelocity(double x, double y)
{
	velocity.setX(x);
	velocity.setY(y);
}

void Particle::positionChange(){
	gridPosition.setX(gridPosition.getX() + velocity.getX());
	gridPosition.setY(gridPosition.getY() + velocity.getY());
}

void Particle::setX(double x)
{
	gridPosition.setX(x);
}
void Particle::setY(double y)
{
	gridPosition.setY(y);
}

