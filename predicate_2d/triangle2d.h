#pragma once
#include "convex_polygon2d.h"
class Triangle2d :
	public ConvexPolygon2d
{
public:	
	Triangle2d(Vertex2d v0, Vertex2d v1, Vertex2d v2);
	virtual ~Triangle2d(void);
	const Vertex2d vertex_at(size_t index) const;
private:
	Triangle2d(void);
	Vertex2d v[3];
};

