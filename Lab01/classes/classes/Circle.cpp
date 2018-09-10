#include "stdafx.h"
#include "Circle.h"

#define PI 3.14

std::string Circle::getDescription() {
	std::string desc = "Circle area:";
	desc += std::to_string(PI * _radius * _radius);
	return desc;
}
