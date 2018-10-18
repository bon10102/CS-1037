#include <iostream>
#include "Pet.h"

using namespace std;

int main(int argc, char *argv) {
	Pet turtle("Zach");
	Pet dog(turtle);
	Pet iguana(move(dog));
	turtle = dog = iguana;
	iguana = dog + turtle;
	cout << dog.getName() << endl;
	cout << iguana.getName() << endl;
	char c;
	cin >> c;
}