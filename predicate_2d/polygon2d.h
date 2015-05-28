#pragma once
#include <deque>
#include <iostream>
#include <limits>
#include <math.h>
#include <set>

class Vertex2d
{
public:
	Vertex2d(void) 
	{ 
		x_ = 0; y_ = 0; 
	}
	Vertex2d(float x, float y) { x_ = x; y_ = y; }
	Vertex2d(const Vertex2d& v)
	{
		x_ = v.x();
		y_ = v.y();
	}

	Vertex2d& operator = (const Vertex2d& v)
	{
		x_ = v.x();
		y_ = v.y();
		return *this;
	}

	friend bool operator < (const Vertex2d& v0, const Vertex2d v1)
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

	 bool operator ==(const Vertex2d& v0)
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

	friend bool operator ==(const Vertex2d& v0, const Vertex2d& v1)
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

	friend std::ostream &operator << (std::ostream &output, const Vertex2d& v)
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
	float x_;
	float y_;
};

class Line2d
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

class Polygon2d
{
public:
	Polygon2d(void);
	virtual ~Polygon2d(void);	

	void push_counterclockwise(Vertex2d& v)
	{
		vertices_.push_back(v);
	};

	Vertex2d vertex_at(size_t index) const 
	{
		return (Vertex2d)vertices_.at(index);
	};

	void push_back(Vertex2d& v)
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
	std::set<Vertex2d> unique_vertices_;
	std::deque<Vertex2d> vertices_;	
};

