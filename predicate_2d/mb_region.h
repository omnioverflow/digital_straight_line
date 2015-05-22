#pragma once
#include "stddef.h"
#include "triangle2d.h"
#include "quad2d.h"
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

