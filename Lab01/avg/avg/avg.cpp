// avg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int total = 0;
	for (int x = 0; x < argc; x++) {
		cout << x << " " << argv[x] << endl;
		if (x>0) total += atoi(argv[x]);
	}
	cout << "The average is " << float(total) / float(argc - 1) << endl;
	char c;
	std::cin >> c;
    return 0;
}

