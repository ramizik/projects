// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Cannon.h - declaration of the Cannon class
//
#ifndef CANNON_DOT_H
#define CANNON_DOT_H
#include "InterAct2D.h"

// A Cannon is a long straight object whose angle from the
//   ground can be adjusted. The left end of the object is
//   fixed and the right end is adjusted based on the current angle
//   of the Cannon. The Cannon's angle and the location of the barrel's
//   exit can be extracted.

class Cannon
{
public:
	// default contructor
	Cannon();

	// reset the configuration of the Cannon
	// p is the screen coordinates of the left end of the Cannon.
	// _increments defines the amount of change in the angle for each call to raise() or lower().
	void initialize(const Point& p, double _increments);

	// draw the Cannon
	void draw();

	// raise the Cannon by the preset increment
	void raise();
	
	// lower the Cannon by the preset increment
	void lower();

	// get the current Cannon angle
	double getAngle();

	// get the position of the end of the Cannon's barrel
	Point getBarrelEnd();

private:
	Line barrel;
	Oval barrel_end;
	Point barrel_end_location;
	float barrel_width;

	double angle;
	double increments;
};

#endif