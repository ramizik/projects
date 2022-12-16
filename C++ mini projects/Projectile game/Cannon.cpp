// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Cannon.cpp - definitions of Cannon class member functions
//
#include "Cannon.h"

const double MAX_ANGLE = 3.1416 / 2.0;  // (PI/2)

Cannon::Cannon()
	: barrel_width(20), barrel(Point(0, 0), Point(0, 0)),
	angle(0.0)
{
	barrel.setFillColor(teal);
	barrel.setPenWidth(barrel_width);
	barrel_end = Oval(Point(0, 0), barrel_width - 5, barrel_width - 5),
	barrel_end.setFillColor(teal);
	barrel_end.setOutlineColor(teal);
}

void Cannon::initialize(const Point& p, double _increments)
{
	barrel.setP1(p);
	increments = _increments;
}

void Cannon::draw()
{
	double dy = 80.0 * sin(angle);
	double dx = 80.0 * cos(angle);
	barrel_end_location = Point(barrel.getP1().getX() + dx, barrel.getP1().getY() - dy);
	barrel.setP2(barrel_end_location);
	barrel_end.moveTo(barrel_end_location);

	barrel.draw();
	barrel_end.draw();
}

void Cannon::raise()
{
	angle += increments;
	if (angle > MAX_ANGLE) angle = MAX_ANGLE;
}

void Cannon::lower()
{
	angle -= increments;
	if (angle < 0.0) angle = 0.0;
}

double Cannon::getAngle() 
{ 
	return angle; 
}

Point Cannon::getBarrelEnd() 
{ 
	return barrel_end_location; 
}
