#include "core2d/MBRegion.h"

MBRegion::MBRegion() {
	triangle_ = nullptr;
	Vertex2D v0(0, 0);
	Vertex2D v1(0, 1);
	Vertex2D v2(1, 1);
	Vertex2D v3(0, 1);
	quad_ = std::make_shared<Quad2D>(v0, v1, v2, v3);
}

std::shared_ptr<Triangle2D> MBRegion::triangle() const {
	return triangle_;
}

std::shared_ptr<Quad2D> MBRegion::quad() const {
	return quad_;
}