#pragma once
#include <string>
class Box
{
private:
	int _w, _h, _d;
public:
	Box(int w,
		int h, int d) :_w(w), _h(h), _d(d) {}
	~Box() {}
	std::string getDescription();
};

