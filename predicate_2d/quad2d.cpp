#include "Quad2D.h"

Quad2D::Quad2D(void)
{
}

Quad2D::Quad2D(Vertex2d& v0, Vertex2d& v1, Vertex2d& v2, Vertex2d& v3)
{	
	v[0] = v0;
	v[1] = v1;
	v[2] = v2;
	v[3] = v3;	
}

Quad2D::~Quad2D(void)
{
	std::cout << "Deleting quad object " << std::endl;
}