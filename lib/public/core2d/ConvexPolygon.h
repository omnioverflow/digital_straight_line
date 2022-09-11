#pragma once

#include <algorithm>
#include <set>

#include "core2d/Polygon.h"

struct Interval
{
	float begin;
	float end;
}; // struct interval

enum class Axis : uint8_t
{
	X_AXIS = 0,
	Y_AXIS = 1
}; // enum axis

using Vector2D = Vertex2D;

class ConvexPolygon2D :	public Polygon2D
{
public:
	ConvexPolygon2D(void) = default;
	virtual ~ConvexPolygon2D() = default;
	void intersect_with(Line2D& line, std::set<Vertex2D>& intersection);
	void intersect_edge(Line2D& line, Vertex2D& v0, Vertex2D& v1, std::set<Vertex2D>& intersection);
	void recompute_convex_hull();	

	Interval* project_onto(Axis anAxis) const;
	Interval* project_onto(Vertex2D& anAxis) const;
	
	bool collide(const ConvexPolygon2D& poly) const;
	
	friend std::ostream &operator << (std::ostream &output, const ConvexPolygon2D& poly) {
		std::cout << "{Poly:\n";
		for(size_t i = 0; i < poly.size(); i++) {
			std::cout << poly.vertex_at(i);
		}
		std::cout << "}\n";
		return output;
	};		
}; // class ConvexPolygon2D