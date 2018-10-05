#include <iostream>
#include "Vector.h"
#include "Point.h"
#include "Polygon.h"
using namespace std;

void print(Vector<int> *vect);
void print(Vector<double> &vect);

int main(int argc, char *argv[]) {
	cout << "Hello" << endl;
	Vector<int> v(3, 1);
	Vector<double> doubVector(4);

	doubVector[0] = 2.4;
	doubVector[1] = 4.3;
	doubVector[2] = 3.6;
	doubVector[3] = 2.3;
	print(&v);
	print(doubVector);

	Point a(1.5, 2.5);
	a.Print();
	Point b(2.1, 3.2);
	Point d(21.2, 2.5);
	Point e(8.6, 3.7);

	Polygon foo;
	foo.addPoint(a);
	foo.addPoint(b);
	foo.addPoint(d);
	foo.addPoint(e);
	foo.printPoints();

	char c; 
	cin >> c;
}

void print(Vector<int> *vect) {
	cout << "Size:" << vect->size() << " ";
	for (int i = (unsigned int)0; i < vect->size(); i++) {
		cout << vect->at(i) << " ";
	}
	cout << endl;
}

void print(Vector<double> &vect) {
	cout << "Size:" << vect.size() << " ";
	for (int i = (unsigned int)0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
}