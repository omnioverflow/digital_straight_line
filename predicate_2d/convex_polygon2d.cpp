#include "convex_polygon2d.h"
#include <algorithm>

ConvexPolygon2d::ConvexPolygon2d(void)
{
}


ConvexPolygon2d::~ConvexPolygon2d(void)
{
}

void ConvexPolygon2d::intersect_edge(Line2d& line, Vertex2d& v0, Vertex2d& v1, std::set<Vertex2d>& intersection)
{	
	// y = cx + d  <-- edge line equation
	float x0 = v0.x();
	float y0 = v0.y();
	float x1 = v1.x();
	float y1 = v1.y();
	float c = 0.0f; // vertical by default
	float d = x0;	// vertical by default
	if(x1 - x0 != 0) // if not vertical () / ();
	{
		c = (y1 - y0) / (x1 - x0);
		d = (x1*y0 - y1*x0) / (x1 - x0);
	}

	// intersect with input y = ax + b
	float a = line.slope();
	float b = line.intersect_y();
	float x_prime = 0.0f, y_prime = 0.0f;
	bool do_intersect = false;
	if(a - c != 0)
	{
		x_prime = (d - b) / (a - c);
		y_prime = a * x_prime + b;
		do_intersect = true;
	}

	// check if intersection point within edge
	if(do_intersect)
	{
		if(x0 > x1)
		{
			std::swap(x0, x1);
		}
		if(y0 > y1)
		{
			std::swap(y0, y1);
		}
		if( (x_prime < x0) || (x_prime > x1) || (y_prime < y0) || (y_prime > y1))
		{
			do_intersect = false;
		}
		else
		{
			Vertex2d v_intersect(x_prime, y_prime);
			intersection.emplace(v_intersect);
		}
	}
}

void ConvexPolygon2d::intersect_with(Line2d& line, std::set<Vertex2d>& intersection)
{
	for(size_t i = 0; i < size(); i++)
	{
		Vertex2d v0 = this->vertex_at(i);
		Vertex2d v1 = this->vertex_at((i + 1) % size());
		intersect_edge(line, v0, v1, intersection);
	}	
}

int orientation(Vertex2d p, Vertex2d q, Vertex2d r)
{
	int val = (q.y() - p.y()) * (r.x() - q.x()) - (q.x() - p.x()) * (r.y() - q.y());

	if (val == 0) return 0;  // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

void ConvexPolygon2d::recompute_convex_hull()
{
	unique_vertices_.clear();

	size_t n = this->size();

	for(size_t i = 0; i < n; i++)
	{
		Vertex2d v = vertex_at(i);
		unique_vertices_.emplace(v);
	}
	n = unique_vertices_.size();

	remove_all_vertices();
	
	// There must be at least 3 points
	if (n < 3) return;

	// Initialize Result
	std::deque<Vertex2d> next;	
	for(std::set<Vertex2d>::iterator it = unique_vertices_.begin(); it != unique_vertices_.end(); ++it)
	{
		Vertex2d v = *it;
		vertices_.push_back(v);
	}
	unique_vertices_.clear();
	
	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++)
		if (vertex_at(i).x() < vertex_at(l).x())
			l = i;

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again
	int p = l, q;


	do
	{
		// Search for a point 'q' such that orientation(p, i, q) is
		// counterclockwise for all points 'i'
		q = (p+1) % n;

		for (int i = 0; i < n; i++)
			if (orientation(vertex_at(p), vertex_at(q), vertex_at(i)) == 2)
			{
				q = i;				
			}

			next.push_back(vertex_at(q));  // Add q to result as a next point of p
			p = q; // Set p as q for next iteration

	} while (p != l);

	vertices_ = next;

	
	// Print Result
	std::cout << "Convex hull\n";
	for (int i = 0; i < n; i++)
	{
		std::cout<< vertex_at(i);
		//std::cout << "(" << vertex_at(i).x() << ", " << vertex_at(i).y << ")\n";
	}
}
