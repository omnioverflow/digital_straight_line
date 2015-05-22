#include "mb_region.h"


MBRegion::MBRegion(void)
{
	this->triangle_ = NULL;
	Vertex2d v0(0, 0);
	Vertex2d v1(0, 1);
	Vertex2d v2(1, 1);
	Vertex2d v3(0, 1);
	this->quad_ = new Quad2d(v0, v1, v2, v3);
}


MBRegion::~MBRegion(void)
{
	if(triangle_ != NULL)
	{
		delete triangle_;
		triangle_ = NULL;
	}
	if(quad_ != NULL)
	{
		delete quad_;
		quad_ = NULL;
	}
}

Triangle2d* MBRegion::triangle() const
{
	return triangle_;
}

Quad2d* MBRegion::quad() const 
{
	return quad_;
}
