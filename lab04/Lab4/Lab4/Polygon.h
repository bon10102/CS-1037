#include "Point.h"
#include "Vector.h"
#include <iostream>
using namespace std;
#pragma once

class Polygon
{
private: 
	Vector<Point> vertex;
public:
	Polygon();
	void addPoint(Point pt);
	void print(int pt);
	void printPoints() {
		cout << "Polygon: " << vertex.size() << endl;
		for (int i = 0; i < vertex.size(); i++) {
			print(i);
		}
	}
	~Polygon();
};

inline void Polygon::addPoint(Point pt) {
	vertex.push_back(pt);
}

