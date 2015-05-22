#pragma once
#include<vector>
#include<iostream>
#include "mb_region.h"

class Pixel 
{
public:
	Pixel(void);
	Pixel(int x, int y);
	~Pixel(void);
	int x() const;
	int y() const;
	void set_x(int x);
	void set_y(int y);
	friend std::ostream &operator << (std::ostream &output, const Pixel& p)
	{
		output << "p(" << p.x() << ", " << p.y() << ")\n";
		return output;
	}	
private:
	int x_;
	int y_;
};

class DigitalSegment
{
public:	
	DigitalSegment(void);
	~DigitalSegment(void);
	const Pixel& at(size_t index) const;
	size_t length() const;
	friend std::ostream &operator << (std::ostream &output, const DigitalSegment& ds)
	{
		std::cout << "{\n";
		for(size_t i = 0; i < ds.length(); i++) 
		{
			std::cout << ds.at(i);			
		}
		std::cout << "}\n";
		return output;
	}
	void push_back(const Pixel& p);
	MBRegion* mb_region();
	Line2d& add_pixel_constraint(Line2d& line, const Pixel& p);
	void intersect(Line2d& line);
private:	
	std::vector<Pixel> *segments_;
	MBRegion* mb_region_;
};