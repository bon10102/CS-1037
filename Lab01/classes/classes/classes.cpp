// classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Box.h"
#include "Circle.h"

int main()
{
	Box b(1, 2, 3);
	Circle c(9);
	std::cout<<b.getDescription() << std::endl;
	std::cout << c.getDescription() << std::endl;
    return 0;
}

