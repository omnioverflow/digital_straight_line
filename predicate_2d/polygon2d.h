#pragma once
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
	float intersect() { return this->intersect_; }
	void set_slope(float new_slope) { this->slope_ = new_slope; }
	void set_intersect(float new_intersect) { this->intersect_ = new_intersect; }
private:
	float slope_;
	float intersect_;
};

class Polygon2d
{
public:
	Polygon2d(void);
	virtual ~Polygon2d(void);	
};

