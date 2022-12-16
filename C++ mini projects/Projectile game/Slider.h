// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Slider.h - declaration of the Slider class
//
#ifndef SLIDER_DOT_H
#define SLIDER_SOT_H
#include "InterAct2D.h"

// A Slider maintains a single value that is displayed graphically as a partially filled bar.
// A Slider's value can be increased or decreased by a preset increment, 
//   within a range from 0 to a preset maximum value.

class Slider
{
public:
	// default constructor
	Slider();

	// reset the configuration of the Slider
	// _position is the screen coordinates of the left end of the Slider.
	// _width and _height are the size of the Slider in pixels.
	// _max_value defines the upper limit of the Slider's value.
	// _increments defines the amount of change in value for each call to increase() or decrease().
	void initialize(Point _position, double _width, double _height, double _max_value, double _increments);

	// draw the slider
	void draw();

	// reduce the slider value by the preset increment
	void decrease();

	// increase the slider value by the preset increment
	void increase();

	// return the current slider value
	double getValue();

private:

	Rect border;
	Rect filler;
	Point position;
	double width;
	double height;
	double max_value;
	double value;
	double increments;
};

#endif