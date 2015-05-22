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
	this->segments_ = new std::vector<Pixel>;
	this->mb_region_ = NULL;
}


DigitalSegment::~DigitalSegment(void)
{
	this->segments_->clear();
	delete this->segments_;
	delete this->mb_region_;
}

const Pixel& DigitalSegment::at(size_t index) const
{
	return this->segments_->at(index);
}

size_t DigitalSegment::length() const
{
	return this->segments_->size();
}

void DigitalSegment::push_back(const Pixel& p)
{
	this->segments_->push_back(p);
}

Line2d& DigitalSegment::add_pixel_constraint(Line2d& line, const Pixel& p)
{
	return line;
}

void DigitalSegment::intersect(Line2d& line)
{
	if(mb_region_->triangle() != NULL)
	{
		// code to intersect a triangle with a line
	} 
	else
	{
		// code to intersect a convex quad with a line
	}
}

MBRegion* DigitalSegment::mb_region() 
{
	if(this->mb_region_ == NULL)
	{
		this->mb_region_ = new MBRegion(); // initialized to square with a diagonal [(0, 0); (1, 1)]

		for(size_t i = 0; i < this->length(); i++)
		{
			// process next pixel's constraint
			Line2d line;
			line = add_pixel_constraint(line, segments_->at(i));
			intersect(line);
		}

		return this->mb_region_;
	}
	else
	{
		return this->mb_region_;
	}
}