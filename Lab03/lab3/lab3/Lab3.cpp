#include <iostream>
#include "Box.h"

using namespace std;

Box* makeBox();
Box* destroyBox(Box *BoxPtr);

int main(int argc, char *argv[]) {
	cout << "Hello" << endl;
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
		cout << (unsigned long)argv << " ";
		cout << (unsigned long)&argv[i] << " ";
		cout << (unsigned long)*argv[i];
		cout << endl;
	}
	int count = 0;
	while (argv[1][count] != '0') {
		count++;
		cout << argv[1][count] << " " << (unsigned long)argv[count] << endl;
	}
	//cout << (unsigned long)argv;
	Box myBox; 
	myBox.l = 1;
	myBox.w = 2;
	myBox.h = 3;
	Box *myBoxPtr = &myBox;
	cout << myBoxPtr->l << " ";
	cout << myBoxPtr->w << " ";
	cout << myBoxPtr->h << endl;

	Box *dynBoxPtr;
	dynBoxPtr = new Box();
	delete dynBoxPtr;

	Box *tempBoxPtr = makeBox();
	destroyBox(tempBoxPtr);

	char c;
	cin >> c;
}

Box* makeBox() {
	Box *dynBoxPtr;
	return new Box();
}

Box* destroyBox(Box *BoxPtr) {
	delete BoxPtr;
	return new Box();
}

