#include "Polygon.h"

Polygon::Polygon()
{
}

void Polygon::print(int pt) {
	vertex.at(pt).Print();
}

Polygon::~Polygon()
{
}
