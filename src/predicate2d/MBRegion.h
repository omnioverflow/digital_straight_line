#pragma once

#include "Triangle2D.h"
#include "Quad2D.h"

// m*x + b = y
class MBRegion
{
public:
	MBRegion(void);
	~MBRegion(void);	
	Triangle2d* triangle() const;
	Quad2d*		quad() const;
private:
	Triangle2d* triangle_;
	Quad2d*		quad_;
};

