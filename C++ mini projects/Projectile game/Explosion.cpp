// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Explosion.cpp - definitions of Explosion class member functions
//
#include "Explosion.h"

Explosion::Explosion()
	: location(0, 0), active(false)
{ }

void Explosion::activate(const Point& p)
{
	location.moveTo(p);
	timer = 1.0;        // set count down timer to 1 second
	active = true;
}

void Explosion::deactivate()
{
	active = false;
}

bool Explosion::isActive() { return active; }

void Explosion::draw()
{
	if (isActive()) {
		float r1size = 30.0;
		float r2size = 10.0 + (1.0 - timer) * 20.0;
		float r3size = 0.0 + (1.0 - timer) * 30.0;
		Oval ring1(location, r1size, r1size);
		Oval ring2(location, r2size, r2size);
		Oval ring3(location, r3size, r3size);
		ring1.setOutlineColor(orange);
		ring1.setFillColor(orange);
		ring2.setOutlineColor(black);
		ring2.setFillColor(black);
		ring3.setOutlineColor(red);
		ring3.setFillColor(red);
		ring1.draw();
		ring2.draw();
		ring3.draw();
	}
}

void Explosion::update(Event event)
{
	timer = timer - event.elapsed_time_msec / 1000.0;
	if (timer <= 0) deactivate();
}

