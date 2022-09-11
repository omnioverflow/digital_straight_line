#pragma once

#include<iostream>
#include<set>
#include<vector>

#include "core2d/ConvexPolygon.h"

class Pixel 
{
public:
	Pixel() = default;
	Pixel(int x, int y);
	~Pixel() = default;

	int x() const;
	int y() const;
	void set_x(int x);
	void set_y(int y);

	friend std::ostream &operator << (std::ostream &output, const Pixel& p) {
		output << "p(" << p.x() << ", " << p.y() << ")\n";
		return output;
	}	
private:
	int x_;
	int y_;
}; // class Pixel

class DigitalSegment
{
public:	
	DigitalSegment(void);
	~DigitalSegment(void);
	const Pixel& at(size_t index) const;
	size_t length() const;

	friend std::ostream &operator << (std::ostream &output, const DigitalSegment& ds) {
		std::cout << "{\n";
		for(size_t i = 0; i < ds.length(); i++) 
			std::cout << ds.at(i);			
		
		std::cout << "}\n";
		return output;
	}

	friend bool operator || (const DigitalSegment& d0, const DigitalSegment& d1); // <-- parallel
	friend bool operator | (const DigitalSegment& d0, const DigitalSegment& d1);

	void push_back(const Pixel& p);

	size_t size() const {
		return segments_->size();
	}
	
	Line2D& add_pixel_constraint(Line2D& line, const Pixel& p);
	const ConvexPolygon2D& mb_region() const { return mb_region_; };
	void constraint_mb_region();

private:	
	std::vector<Pixel> *segments_;
	ConvexPolygon2D mb_region_;	
}; // class Digital Segment