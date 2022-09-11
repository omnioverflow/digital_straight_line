#pragma once

#include <memory>

#include "core2D/Triangle.h"
#include "core2D/Quad.h"

// m*x + b = y
class MBRegion {
public:
	MBRegion();
	~MBRegion() = default;
	MBRegion(const MBRegion& other) = default;
	MBRegion& operator= (const MBRegion& other) = default;
	MBRegion(MBRegion&& other) = default;
	MBRegion& operator=(MBRegion&& other) = default;

	std::shared_ptr<Triangle2D> triangle() const;
	std::shared_ptr<Quad2D>	quad() const;

private:
	std::shared_ptr<Triangle2D> triangle_;
	std::shared_ptr<Quad2D>	quad_;
}; // class MBRegion