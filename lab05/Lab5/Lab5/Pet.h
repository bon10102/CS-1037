#pragma once 
#include <iostream>
using namespace std;
class Pet
{
private:
	char *name;
	static int number_pets;
	int getNameLength() const;
public:
	Pet(const char *nm=nullptr);
	Pet(const Pet &src);
	Pet(Pet &&obj);
	void setName(const char *nm);
	static int getNumber_pets() { return number_pets; }
	char *getName() const { return name; }
	Pet operator=(const Pet &rhs) {
		delete[] name;
		name = new char[rhs.getNameLength() + 1];
		for (int i = 0; i < rhs.getNameLength() + 1; i++) {
			name[i] = rhs.name[i];
		}
		return name;
	}

	Pet operator+(const Pet &rhs) {
		char *newName = new char[getNameLength() + rhs.getNameLength() + 1];
		for (int i = 0; i < getNameLength(); i++) {
			newName[i] = name[i];
		}
		for (int i = getNameLength(); i < getNameLength() + rhs.getNameLength(); i++) {
			newName[i] = rhs.name[i-getNameLength()];
		}
		newName[getNameLength() + rhs.getNameLength()] = 0;
		Pet tempadd(newName);
		return tempadd;
	}
	~Pet();
};

