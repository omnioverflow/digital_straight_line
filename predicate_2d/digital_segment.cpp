#include "digital_segment.h"
#include <boost\numeric\ublas\blas.hpp>
#include <boost/numeric/ublas/matrix.hpp>

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

	// init possible set of (m, b) of the digital straight line m*x+b
	Vertex2d v0(0, 0);
	Vertex2d v1(0, 1);
	Vertex2d v2(1, 1);
	Vertex2d v3(1, 0);
	mb_region_.push_counterclockwise(v0);
	mb_region_.push_counterclockwise(v1);
	mb_region_.push_counterclockwise(v2);
	mb_region_.push_counterclockwise(v3);	
}


DigitalSegment::~DigitalSegment(void)
{
	this->segments_->clear();
	delete this->segments_;

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
	line.set_slope((-1.0f) * (float)p.x());
	line.set_intersect((float)p.y());
	return line;
}


void DigitalSegment::constraint_mb_region() 
{
	// constrain (m, b) with respect to all pixels in the digital segment
	for(size_t i = 0; i < this->size(); i++)
	{
		// process next pixel
		Line2d line;
		this->add_pixel_constraint(line, this->at(i));

		std::set<Vertex2d> intersection;
		mb_region_.intersect_with(line, intersection);
		// check lower bound
		if(intersection.size() > 1)
		{
			size_t removed_count = 0;
			size_t n = mb_region_.size();
			for(size_t j = 0; j < n; j++)
			{
				Vertex2d v = mb_region_.vertex_at(j - removed_count);
				if( v.y() < (line.slope() * v.x() + line.intersect_y()) )
				{
					// remove		
					mb_region_.remove_vertex_at(j - removed_count);	
					removed_count++;
				}		
			}

			for(std::set<Vertex2d>::iterator it = intersection.begin(); it != intersection.end(); it++)
			{
				Vertex2d next_v = *it;
				mb_region_.push_back(next_v);				
			}
			intersection.clear();

			mb_region_.recompute_convex_hull();
		}		
	}
}