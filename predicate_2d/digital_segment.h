#pragma once
#include<vector>
#include<iostream>
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
		output << "(" << p.x() << ", " << p.y() << ")\n";
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
private:
	size_t length_;
	std::vector<Pixel> segment_;
};

