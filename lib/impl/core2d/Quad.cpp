#include "core2d/Quad.h"

Quad2D::Quad2D(Vertex2D& v0, Vertex2D& v1, Vertex2D& v2, Vertex2D& v3)
	: v_{v0, v1, v2, v3} {}