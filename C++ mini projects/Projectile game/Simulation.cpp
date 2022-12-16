// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Simulation.cpp - definitions of Simulation class member functions
//                  and declaration of the single global Simulation object
//
#include "Simulation.h"

///////////////////////////////////////////////////////////////////////////
// Declare the single global Simulation instance.
///////////////////////////////////////////////////////////////////////////
Simulation simulation;

///////////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////////
Simulation::Simulation() 
	: q_key_down(false), a_key_down(false), w_key_down(false), s_key_down(false), e_key_down(false)
{ }

///////////////////////////////////////////////////////////////////////////
// Set entire screen to the specified color
///////////////////////////////////////////////////////////////////////////
void Simulation::clearScreen(Event event, Color color)
{
	float center_x = event.screen_width / 2.0;
	float center_y = event.screen_height / 2.0;
	Rect background(Point(center_x, center_y),
		event.screen_width, event.screen_height);
	background.setFillColor(color);
	background.setOutlineColor(color);
	background.draw();
}

///////////////////////////////////////////////////////////////////////////
// resetSimulation(): Control function called on RESTART events.
//   It resets the state of all objects in the simulated environment.
///////////////////////////////////////////////////////////////////////////
void Simulation::resetSimulation(Event event)
{
	sky = MovingBackground(string("cartoon_clouds.bmp"), 600, 600);
	sky.setSpeed(1.0);

	cannon.initialize(Point(0.0, 500), 0.0157);
	velocity_slider.initialize(Point(0.0, 550), 100.0, 20.0, 100.0, 1.0);
	explosion.deactivate();
	projectile.deactivate();

	q_key_down = false;
	a_key_down = false; 
	w_key_down = false; 
	s_key_down = false;
	e_key_down = false;
}

///////////////////////////////////////////////////////////////////////////
// drawEverything(): Draw all objects in the simulated environment.
///////////////////////////////////////////////////////////////////////////
void Simulation::drawEverything(Event event)
{
	clearScreen(event, lightgray);
	sky.draw();
	explosion.draw();
	cannon.draw();
	velocity_slider.draw();
	projectile.draw();
}

///////////////////////////////////////////////////////////////////////////
// updateSimulation(): Main control function called for all events
//   except RESTART and REPAINT.
///////////////////////////////////////////////////////////////////////////
void Simulation::updateSimulation(Event event)
{
	// Handle user input from keyboard.

	if (event.key_pressed)
	{
		switch (event.key)
		{
		case 'q':
		case 'Q':
			q_key_down = true;
			break;
		case 'a':
		case 'A':
			a_key_down = true;
			break;
		case 'w':
		case 'W':
			w_key_down = true;
			break;
		case 's':
		case 'S':
			s_key_down = true;
			break;
		case 'e':
		case 'E':
			e_key_down = true;
			break;
		}
	}
	if (event.key_released)
	{
		switch (event.key)
		{
		case 'q':
		case 'Q':
			q_key_down = false;
			break;
		case 'a':
		case 'A':
			a_key_down = false;
			break;
		case 'w':
		case 'W':
			w_key_down = false;
			break;
		case 's':
		case 'S':
			s_key_down = false;
			break;
		case 'e':
		case 'E':
			e_key_down = false;
			break;
		}
	}
	if (q_key_down) cannon.raise();
	if (w_key_down) cannon.lower();
	if (a_key_down)	velocity_slider.increase();
	if (s_key_down)	velocity_slider.decrease();
	if (e_key_down) {
		Point p3 = cannon.getBarrelEnd();
		double la = cannon.getAngle();
		double lv = velocity_slider.getValue();
		projectile.launch(p3, la, lv);

	}

	// For timer events, update the state of all objects.
	if (event.elapsed_time_msec > 0.0)
	{
		sky.update(event);
		projectile.isActive();
		projectile.move(event);
		if (explosion.isActive()) explosion.update(event);
	}
}


// if (!explosion.isActive())
// explosion.activate(Point(400, 300))
// explosion ^^^^
///////////////////////////////////////////////////////////////////////////
// Receive Events and respond to them.
///////////////////////////////////////////////////////////////////////////
void Simulation::handleEvent(Event event)
{
	if (event.restart) {
		resetSimulation(event);
	}
	else if (event.repaint) {
		drawEverything(event);
	}
	else {
		updateSimulation(event);
		drawEverything(event);
	}
}

///////////////////////////////////////////////////////////////////////////
//  Interface to the InterAct2D library.
//  Pass all Events to the Simulation object
///////////////////////////////////////////////////////////////////////////
void handleEvent(Event event)
{
	simulation.handleEvent(event);
}
