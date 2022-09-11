#pragma once

#include <iostream>

#include "core2d/ConvexPolygon.h"

class Quad2D: public ConvexPolygon2D
{
public:
	Quad2D() = delete;
	Quad2D(Vertex2D& v0, Vertex2D& v1, Vertex2D& v2, Vertex2D& v3);
	virtual ~Quad2D() = default;

private:
	Vertex2D v_[4];
}; // class Quad2D