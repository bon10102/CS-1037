/*
 * main.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: jason
 */


#include <iostream>
#include "Vector.h"
using namespace std;

void print(Vector<int> *pvec){
	cout << "Vector size:" << pvec->size() << " {";
	for (unsigned int x=0;x<pvec->size();x++)
		cout << pvec->at(x) << " ";
	cout << "}" << endl;
}
int main(int argc,char *argv[]){
	Vector<int> v(5,1);
	print(&v);
	v[1]=3;
	print(&v);
	v.reverse();
	print(&v);
	Vector<int> nv(v);
	print(&nv);
	nv.resize(10,2);
	print(&nv);
	nv.resize(2,9);
	print(&nv);
	nv.clear();
	print(&nv);
	for (int x=10;x<50;x++)
		nv.push_back(x);
	print(&nv);
	cout << "Popping off:";
	for (int x=0;x<10;x++)
		cout << nv.pop_back() << " ";
	cout << endl;
	print(&nv);
	char c;
	cin >> c;
}

