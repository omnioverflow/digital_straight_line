#pragma once

#include <algorithm>
#include <set>

#include "core2d/Polygon.h"

struct interval
{
	float begin;
	float end;
}; // struct interval

enum axis : uint8_t
{
	X_AXIS,
	Y_AXIS
}; // enum axis

using Vector2D = Vertex2D

class ConvexPolygon2D :	public Polygon2D
{
public:
	ConvexPolygon2D(void);
	virtual ~ConvexPolygon2D(void);
	void intersect_with(Line2D& line, std::set<Vertex2D>& intersection);
	void intersect_edge(Line2D& line, Vertex2D& v0, Vertex2D& v1, std::set<Vertex2D>& intersection);
	void recompute_convex_hull();	

	interval* project_onto(axis anAxis) const;
	interval* project_onto(Vertex2D& anAxis) const;
	
	bool collide(const ConvexPolygon2D& poly) const;
	
	friend std::ostream &operator << (std::ostream &output, const ConvexPolygon2D& poly)
	{
		std::cout << "{Poly:\n";
		for(size_t i = 0; i < poly.size(); i++) 
		{
			std::cout << poly.vertex_at(i);
		}
		std::cout << "}\n";
		return output;
	};		
}; // ConvexPolygon2D