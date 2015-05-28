#pragma once
#include "polygon2d.h"
#include <set>
#include <algorithm>

struct interval
{
	float begin;
	float end;
};

enum axis
{
	X_AXIS,
	Y_AXIS
};

#define Vector2d Vertex2d

class ConvexPolygon2d :
	public Polygon2d
{
public:
	ConvexPolygon2d(void);
	virtual ~ConvexPolygon2d(void);
	void intersect_with(Line2d& line, std::set<Vertex2d>& intersection);
	void intersect_edge(Line2d& line, Vertex2d& v0, Vertex2d& v1, std::set<Vertex2d>& intersection);
	void recompute_convex_hull();	

	interval* project_onto(axis anAxis) const;
	interval* project_onto(Vertex2d& anAxis) const;
	
	bool collide(const ConvexPolygon2d& poly) const;
	
	friend std::ostream &operator << (std::ostream &output, const ConvexPolygon2d& poly)
	{
		std::cout << "{Poly:\n";
		for(size_t i = 0; i < poly.size(); i++) 
		{
			std::cout << poly.vertex_at(i);
		}
		std::cout << "}\n";
		return output;
	};		
};

