#include "digital_segment.h"

Pixel::Pixel(void)
{
}

Pixel::Pixel(int x, int y)
	: x_(x)
	, y_(y)
{
}

Pixel::~Pixel(void)
{
}

int Pixel::x() const
{
	return this->x_;
}

int Pixel::y() const
{
	return this->y_;
}

void Pixel::set_x(int x)
{
	this->x_ = x;
}

void Pixel::set_y(int y)
{
	this->y_ = y;
}

DigitalSegment::DigitalSegment(void)
{
}


DigitalSegment::~DigitalSegment(void)
{
}