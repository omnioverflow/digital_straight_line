#include "core2d/Triangle.h"

Triangle2D::Triangle2D(Vertex2D v0, Vertex2D v1, Vertex2D v2)
	: v_{v0 , v1, v2} {}

const Vertex2D& Triangle2D::vertex_at(size_t index) const {
	return v_[index];
}