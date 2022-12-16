// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Projectile.cpp - definitions of Projectile class member functions
//
#include "Projectile.h"

const double gravity = 9.8; // gravitional acceleration = 9.8 m/s^2

Projectile::Projectile()
{
	initializeGraphic();
	active = false;
}

// launch() needs to set the Projectile's location and the x and y xomponents of its velocity
// The x component of velocity (dx) is the launch velocity times the cosine of the launch angle.
// The y component of velocity (dy) is -1 times the launch velocity times the sine of the launch angle.
void Projectile::launch(const Point& _p, double _launch_angle, double _launch_velocity)
{
	if (isActive()) return;
	location = _p;
	dx = _launch_velocity * cos(_launch_angle);
	dy = -1 * _launch_velocity * sin(_launch_angle);
	active = true;
	// FUNCTION IS NOT YET IMPLEMENTED
}

// draw() needs to move the graphic object to the projectile's 
// current position and then tell it to draw.
void Projectile::draw()
{
	if (!isActive()) return;
	Point p2 = getPosition();
	graphic.moveTo(p2);
	graphic.draw();

	// FUNCTION IS NOT YET IMPLEMENTED
}

// move() updates the Projectile according to it's own physics.
// The elapsed time in msec (dt) can be found in event.elapsed_time_msec.
// The vertical speed is affected by gravity:
//  dy / dx - delta. dy position as I move affects p.x / p.y
//    dy = dy + gravity * dt
// The position is affected by the veloci```ty components.
//    x = x + dx*dt
//    y = y + dx*dt
void Projectile::move(Event event)
// similar like in lab code, use my parameteres. Use paraameter event 
// elapsed time in ms in event 
{
	if (!isActive()) return;
	double dt = event.elapsed_time_msec;
	dy = dy + gravity * dt;
	location.move(dx * dt, dy * dt);
	// FUNCTION IS NOT YET IMPLEMENTED
}

void Projectile::deactivate()
{
	active = false;
}

bool Projectile::isActive() 
{ 
	return active; 
}

Point Projectile::getPosition() 
{ 
	return location; 
}

void Projectile::initializeGraphic()
{
	graphic = Oval(Point(0, 0), 20.0, 20.0);
	graphic.setFillColor(purple);
	graphic.setOutlineColor(purple);
	graphic.setPenWidth(1);
}

