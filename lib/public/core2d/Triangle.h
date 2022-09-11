#pragma once

#include "core2d/ConvexPolygon.h"

class Triangle2D : public ConvexPolygon2D
{
public:	
	Triangle2D() = delete;
	Triangle2D(Vertex2D v0, Vertex2D v1, Vertex2D v2);
	virtual ~Triangle2D() = default;
	const Vertex2D& vertex_at(size_t index) const;

private:
	Vertex2D v_[3];
}; // class Triangle2D