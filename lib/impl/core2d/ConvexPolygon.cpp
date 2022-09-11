#include <algorithm>

#include "core2d/ConvexPolygon.h"

void ConvexPolygon2D::intersect_edge(Line2D& line,
									 Vertex2D& v0,
									 Vertex2D& v1,
									 std::set<Vertex2D>& intersection) {
	// y = cx + d  <-- edge line equation
	float x0 = v0.x();
	float y0 = v0.y();
	float x1 = v1.x();
	float y1 = v1.y();
	float c = 0.0f; // vertical by default
	float d = x0;	// vertical by default

	if(x1 - x0 != 0) { // if not vertical () / (); 
		c = (y1 - y0) / (x1 - x0);
		d = (x1*y0 - y1*x0) / (x1 - x0);
	}

	// intersect with input y = ax + b
	float a = line.slope();
	float b = line.intersect_y();
	float x_prime = 0.0f, y_prime = 0.0f;
	bool do_intersect = false;
	if(a - c != 0) {
		x_prime = (d - b) / (a - c);
		y_prime = a * x_prime + b;
		do_intersect = true;
	}

	// check if intersection point within edge
	if(do_intersect) {
		if(x0 > x1) {
			std::swap(x0, x1);
		}
		if(y0 > y1) {
			std::swap(y0, y1);
		}
		if( (x_prime < x0) || (x_prime > x1) || (y_prime < y0) || (y_prime > y1)) {
			do_intersect = false;
		}
		else {
			Vertex2D v_intersect(x_prime, y_prime);
			intersection.emplace(v_intersect);
		}
	}
}

void ConvexPolygon2D::intersect_with(Line2D& line, std::set<Vertex2D>& intersection) {
	for(size_t i = 0; i < size(); i++) {
		Vertex2D v0 = this->vertex_at(i);
		Vertex2D v1 = this->vertex_at((i + 1) % size());
		intersect_edge(line, v0, v1, intersection);
	}	
}

int orientation(Vertex2D p, Vertex2D q, Vertex2D r) {
	int val = (q.y() - p.y()) * (r.x() - q.x()) - (q.x() - p.x()) * (r.y() - q.y());

	if (val == 0) return 0;  // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

void ConvexPolygon2D::recompute_convex_hull() {
	unique_vertices_.clear();

	size_t n = this->size();

	for(size_t i = 0; i < n; i++) {
		Vertex2D v = vertex_at(i);
		unique_vertices_.emplace(v);
	}
	n = unique_vertices_.size();

	remove_all_vertices();
	
	// There must be at least 3 points
	if (n < 3) return;

	// Initialize Result
	std::deque<Vertex2D> next;	
	for(std::set<Vertex2D>::iterator it = unique_vertices_.begin(); it != unique_vertices_.end(); ++it) {
		Vertex2D v = *it;
		vertices_.push_back(v);
	}
	unique_vertices_.clear();
	
	// Find the leftmost point
	size_t l = 0;
	for (int i = 1; i < n; i++)
		if (vertex_at(i).x() < vertex_at(l).x())
			l = i;

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again
	int p = l;
	int q = 0;

	do {
		// Search for a point 'q' such that orientation(p, i, q) is
		// counterclockwise for all points 'i'
		q = (static_cast<long long>(p) + 1) % n;

		for (int i = 0; i < n; i++)
			if (orientation(vertex_at(p), vertex_at(q), vertex_at(i)) == 2)
				q = i;				

			next.push_back(vertex_at(q));  // Add q to result as a next point of p
			p = q; // Set p as q for next iteration

	} while (p != l);

	vertices_ = next;

	// Print Result
	std::cout << "Convex hull\n";
	for (int i = 0; i < n; i++) {
		std::cout<< vertex_at(i);
		//std::cout << "(" << vertex_at(i).x() << ", " << vertex_at(i).y << ")\n";
	}
}

// Project a polygon on a given axis in Cartesian coordinates
Interval* ConvexPolygon2D::project_onto(Axis anAxis) const {
	Interval* intervl = new Interval();
	if(anAxis == Axis::X_AXIS) {
		float min_x = std::numeric_limits<float>::max();
		float max_x = std::numeric_limits<float>::min();
		for(size_t i = 0; i < size(); i++) {
			if(vertices_.at(i).x() < min_x)
				min_x = vertices_.at(i).x();
			else if(vertices_.at(i).x() > max_x)
				max_x = vertices_.at(i).x();
		}
		intervl->begin = min_x;
		intervl->end = max_x;
	}
	return intervl;
}

float cross(Vertex2D& v, Vertex2D& u) {
	return v.x() * u.x() + v.y() * u.y();
}

Interval* ConvexPolygon2D::project_onto(Vertex2D& anAxis) const {
	Interval* projection = new Interval();
	// loop over all the vertices performing the dot product with the axis
	// and storing the minimum and maximum
	float min = cross(this->vertex_at(0), anAxis);
	float max = min;
	for(size_t i = 1; i < this->size(); i++) {
		float dot_pro = cross(this->vertex_at(i), anAxis);
		if(dot_pro < min)
			min = dot_pro;
		else if(dot_pro > max)
			max = dot_pro;
	}

	projection->begin = min;
	projection->end = max;

	return projection;
}

bool ConvexPolygon2D::collide(const ConvexPolygon2D& poly) const
{
	bool do_collide = true;
	// iterate over all edges of the input poly
	for(size_t i = 0; i < poly.size(); i++) {
		Vertex2D v0 = poly.vertex_at(i);
		Vertex2D v1 = poly.vertex_at((i == poly.size() - 1) ? 0 : (i + 1));

		float x = v1.x() - v0.x();
		float y = v1.y() - v0.y();
		// compute normal to the edge
		Vector2D n(-x, y);

		// Progect polygon onto the normal
		Interval* interv0 = poly.project_onto(n);

		// Project "this" polygon onto the normal
		Interval* interv1 = this->project_onto(n);

		// Check if projections intersect		
		do_collide = std::max(interv0->begin, interv1->begin) <= std::min(interv0->end, interv1->end);
		if(!do_collide) {
			return false;
		}

		// free memory
		delete interv0;
		delete interv1;
	}

	// iterate overl all vertices of "this" polygon
	for(size_t i = 0; i < poly.size(); i++) {
		Vertex2D v0 = this->vertex_at(i);
		Vertex2D v1 = this->vertex_at((i == this->size() - 1) ? 0 : (i + 1));

		float x = v1.x() - v0.x();
		float y = v1.y() - v0.y();
		// compute normal to the edge
		Vector2D n(-x, y);

		// Progect polygon onto the normal
		Interval* interv0 = poly.project_onto(n);

		// Project "this" polygon onto the normal
		Interval* interv1 = this->project_onto(n);

		// Check if projections intersect	
		do_collide = std::max(interv0->begin, interv1->begin) <= std::min(interv0->end, interv1->end);
		if(!do_collide) {
			return false;
		}

		// free memory
		delete interv0;
		delete interv1;
	}

	return true;
}