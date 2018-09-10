#pragma once
#include <string>
class Circle
{
private:
	float _radius;
public:
	Circle(float radius) :_radius(radius) {}
	~Circle() {}
	std::string getDescription();
};