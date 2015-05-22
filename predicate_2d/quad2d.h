#pragma once
#include "convex_polygon2d.h"
#include <iostream>
class Quad2d :
	public ConvexPolygon2d
{
public:		
	Quad2d(Vertex2d& v0, Vertex2d& v1, Vertex2d& v2, Vertex2d& v3);
	virtual ~Quad2d(void);	
private:		
	Quad2d(void);
	Vertex2d v[4];
};