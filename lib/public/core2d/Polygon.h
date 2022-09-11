#pragma once

#include <deque>
#include <iostream>
#include <limits>
#include <math.h>
#include <set>

class Vertex2D
{
public:
	Vertex2D(void) 
	{ 
		x_ = 0; y_ = 0; 
	}
	Vertex2D(float x, float y) { x_ = x; y_ = y; }
	Vertex2D(const Vertex2D& v)
	{
		x_ = v.x();
		y_ = v.y();
	}

	Vertex2D& operator = (const Vertex2D& v)
	{
		x_ = v.x();
		y_ = v.y();
		return *this;
	}

	friend bool operator < (const Vertex2D& v0, const Vertex2D v1)
	{
		if((v0.x() > v1.x()) || ( (v0.x() == v1.x()) && (v0.y() > v1.y()) ) )
		{
			return true;
		} else
		{
			return false;
		}
		/*
		if( sqrt(pow(v0.x(), 2) + pow(v0.y(),2)) < sqrt(pow(v1.x(), 2) + pow(v1.y(), 2)) )
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
	}

	bool operator ==(const Vertex2D& v0)
	{
		if( (v0.x() == x_) && (v0.y() == y_) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator ==(const Vertex2D& v0, const Vertex2D& v1)
	{
		if( (v0.x() == v1.x()) && (v0.y() == v1.y()) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend std::ostream &operator << (std::ostream &output, const Vertex2D& v)
	{
		std::cout << "{Vertex:" << v.x() << ", " << v.y() << "}\n";		
		return output;
	};

	float x() const
	{
		return x_;
	}
	float y() const
	{
		return y_;
	}

	void set_x(float new_x)
	{
		x_ = new_x;
	}

	void set_y(float new_y)
	{
		y_ = new_y;
	}

	float x_;
	float y_;
};

class Line2D
{
public:
	float slope() { return this->slope_; }
	float intersect_y() { return this->intersect_y_; }
	void set_slope(float new_slope) { this->slope_ = new_slope; }
	void set_intersect(float new_intersect) { this->intersect_y_ = new_intersect; }
private:
	float slope_;
	float intersect_y_;
};

class Polygon2D
{
public:
	Polygon2D(void);
	virtual ~Polygon2D(void);

	void push_counterclockwise(Vertex2D& v)
	{
		vertices_.push_back(v);
	};

	Vertex2D vertex_at(size_t index) const 
	{
		return (Vertex2D)vertices_.at(index);
	};

	void push_back(Vertex2D& v)
	{
		vertices_.push_back(v);
	}

	size_t size() const
	{
		return vertices_.size();
	};

	void remove_vertex_at(size_t index)
	{
		vertices_.erase(vertices_.begin() + index);
	};

	void remove_all_vertices()
	{
		vertices_.clear();
	};
protected:
	std::set<Vertex2D> unique_vertices_;
	std::deque<Vertex2D> vertices_;	
};

