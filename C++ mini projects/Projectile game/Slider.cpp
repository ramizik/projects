// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Slider.cpp - definitions of Slider class member functions
//
#include "Slider.h"

Slider::Slider()
	: border(Point(0.0, 0.0), 0.0, 0.0), filler(Point(0.0, 0.0), 0.0, 0.0)
{
	width = 0.0;
	height = 0.0;
	max_value = 0.0;
	increments = 0.01;
	value = 0.0;
}

void Slider::initialize(Point _position, double _width, double _height, double _max_value, double _increments)
{
	position = _position;
	width = _width;
	height = _height;
	max_value = _max_value;
	increments = _increments;
}

void Slider::draw() 
{ 
	Point border_center = Point(position.getX() + width / 2.0, position.getY() + height / 2.0);
	border = Rect(border_center, width, height);
	double filler_width = width * (value / max_value);
	Point filler_center = Point(position.getX() + filler_width / 2.0, position.getY() + height / 2.0);
	filler = Rect(filler_center, filler_width, height);
	border.setOutlineColor(darkgray);
	border.setFillColor(darkgray);
	filler.setOutlineColor(green);
	filler.setFillColor(green);
	border.draw(); 
	filler.draw(); 
}

void Slider::decrease()
{
	value -= increments;
	if (value < 0.0) value = 0.0;
}

void Slider::increase()
{
	value += increments;
	if (value > max_value) value = max_value;
}

double Slider::getValue()
{
	return value;
}

