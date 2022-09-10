#pragma once

#include "ConvexPolygon2D.h"
class Triangle2D : public ConvexPolygon2D
{
public:	
	Triangle2D(Vertex2D v0, Vertex2D v1, Vertex2D v2);
	virtual ~Triangle2D(void);
	const Vertex2D vertex_at(size_t index) const;
private:
	Triangle2D(void);
	Vertex2D v[3];
};