// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Projectile.h - declaration of the Projectile class
//
#ifndef PROJECTILE_DOT_H
#define PROJECTILE_DOT_H
#include "InterAct2D.h"

// A Projectile is a moving object that is affected by gravity.

class Projectile
{
public:
	// default contructor
	Projectile();

	// launch the Projectile
	//   activate the Projectile to make it visible
	//   move it to Point _p, 
	//   set its initial velocity based on _launch angle and _launch velocity
	void launch(const Point& _p, double _launch_angle, double _launch_velocity);

	// deactivate the Projectile and make it invisible
	void deactivate();

	// tell whether the Projectile is active
	bool isActive();

	// draw the Projectile, if it is active
	void draw();

	// tell the Projectile to move, based on its own physics.
	void move(Event event);

	// get the current position of the projectile
	Point getPosition();

private:

	// initialize the appearance of a Projectile
	void initializeGraphic();

	Oval graphic;   // InterAct2D object that will be drawn to represent the projectile
	bool active;	// flag inidicating whether the projectile is active.
	Point location;	// current location of the Projectile
	double dx, dy;  // x and y components of the Projectile's velocity
};

#endif