// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Explosion.h - declaration of the Explosion class
//
#ifndef EXPLOSION_DOT_H
#define EXPLOSION_DOT_H
#include "InterAct2D.h"

// An Explosion is an animation that last one second.
// Once an Explosion is placed on the screen and activated,
//   it will use expanding rings of color to give a visual effect.
// An Explosion deactivates itself after one second.
class Explosion
{
public:
	// default constructor
	Explosion();

	// moves the explosion to Point p and makes it active so that it will be visible
	void activate(const Point& p);

	// deactivate the explosion.
	void deactivate();

	// tell whether explostion is currently active
	bool isActive();

	// draw the explosion, if it is currently active
	void draw();

	// decrements time and deactivates explosion once timer elapses
	void update(Event event);
	
private:
	Point location;
	double timer;   // count down timer
	bool active;    // flag to determine if explosion is currently active
};

#endif
