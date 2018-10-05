#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
}

Point::Point(double val1, double val2) {
	x = val1;
	y = val2;
}

 void Point::Print(){
	cout << "{" << x << ", " << y << "}" << endl;
}


Point::~Point()
{
}
