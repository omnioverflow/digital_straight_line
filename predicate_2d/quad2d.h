#pragma once

#include <iostream>

#include "ConvexPolygon2D.h"

class Quad2D: public ConvexPolygon2D
{
public:		
	Quad2D(Vertex2D& v0, Vertex2D& v1, Vertex2D& v2, Vertex2D& v3);
	virtual ~Quad2D(void);	
private:		
	Quad2D(void);
	Vertex2D v[4];
};