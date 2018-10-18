#include "Pet.h"

int Pet::number_pets = 0;
Pet::Pet(const char *nm) {
	name = nullptr;
	setName(nm);
	number_pets++;
	cout << "Constructor Called" << endl;
}

Pet::Pet(const Pet &src) {
	name = nullptr;
	setName(src.getName());
	number_pets++;
	cout << "Copy Constructor" << endl;
}

Pet::Pet(Pet &&obj) {
	name = obj.name;
	obj.name = nullptr;
	number_pets++;
	cout << "Move Constructor" << endl;
}

int Pet::getNameLength() const {
	int count = 0;
	while (name[count] != 0) {
		count++;
	}
	return count;
}

void Pet::setName(const char *nm) {
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	else if (nm == nullptr) {
		delete[] name;
		name = new char[1]{ 0 };
	}
	else if (nm != nullptr) {
		int count = 0;
		while (nm[count] != 0) {
			count++;
		}
		delete[] name;
		name = new char[count + 1];
		for (int i = 0; i < count + 1; i++) {
			name[i] = nm[i];
		}
	}
}

Pet::~Pet() {
	if (name != nullptr) {
		delete[] name;
		number_pets--;
		cout << "Destructor" << endl;
	}
}