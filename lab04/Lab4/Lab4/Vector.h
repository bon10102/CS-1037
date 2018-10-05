/*
 * Vector.h
 *
 *  Created on: Sep 20, 2018
 *      Author: Jason Brasse
 *        Note: Nearly identical functionality to c++ vector class,
 *              except added bounds checking
 */

#ifndef XVECTOR_H_
#define XVECTOR_H_

#include <cstdlib>
#include <iostream>

#define VECTOR_DFLT_CAP 2

template <class T>
class Vector {
private:
	unsigned int cap;	//capacity of array
	unsigned int sz;	//number of elements in the array
	T *arr;				//Array of elements
	void expand();		//Increase array capacity
	void shrink();		//Decrease array capacity
	void validateIndex(unsigned int position) const;//exit program if position is out of bounds
public:
	Vector(unsigned int init_sz=0);					//Create uninitialized vector of specified size
	Vector(unsigned int init_sz, T value);			//Create initialized vector of specified size
	Vector(const Vector &src);						//Create a new vector which is an exact copy of src vector
	~Vector();										//Destructor frees memory

	unsigned int size() const {return sz;}			//Return the size (not capacity of vector)
	T& operator[] (int x)
		{validateIndex(x);return arr[x];}			//Return a REFERENCE to the requested element - will exit program if invalid index
	void push_back(T value);						//Append a new value to the end of the array (expand if necessary)

	void swap(Vector &other);						//swap the contents of this this vector with other vector
	void resize(unsigned int new_sz,T value=0);		//resize the contents of this array, if larger than existing, new elements are initialized to value
	void reverse();									//reverse the order of the elements
	T at(unsigned int position) const;				//Return a copy of value at index position - will exit program if invalid index
	T pop_back();									//Return and remove the last element of the array - will exit program if vector is empty
	void clear();									//remove all elements from vector
	bool empty() const{return (sz==0);}				//returns true if sz is 0
};

template <class T>
Vector<T>::Vector(unsigned int init_sz):cap(init_sz),sz(init_sz) {
	if (cap==0) cap=VECTOR_DFLT_CAP;
	arr=new T[cap];
}

template <class T>
Vector<T>::Vector(unsigned int init_sz, T value):cap(init_sz),sz(init_sz) {
	if (cap==0) cap=VECTOR_DFLT_CAP;
	arr=new T[cap];
	for (unsigned int x=0;x<sz;x++)
		arr[x]=value;
}

template <class T>
Vector<T>::Vector(const Vector &src):cap(src.sz),sz(src.sz) {
	if (cap==0) cap=VECTOR_DFLT_CAP;
	arr=new T[cap];
	for (unsigned int x=0;x<sz;x++)
		arr[x]=src.arr[x];
}

template <class T>
Vector<T>::~Vector() {
	delete[] arr;
}

template <class T>
void Vector<T>::push_back(T value){
	//Append a new value to the end of the array (expand if necessary)
	if (sz==cap) expand();
	arr[sz++]=value;
}

template <class T>
void Vector<T>::swap(Vector &other){
	//swap the contents of this this vector with other vector
	//temporary holder variables
	unsigned int tmp_cap=other.cap;
	unsigned int tmp_sz=other.sz;
	T *tmp_arr=other.arr;
	other.cap=cap;
	other.sz=sz;
	other.arr=arr;
	cap=tmp_cap;
	sz=tmp_sz;
	arr=tmp_arr;
}

template <class T>
void Vector<T>::resize(unsigned int new_sz,T value){
	//resize the contents of this array, if larger than existing, new elements are initialized to value
	if (new_sz==0){
		clear();
		return;
	}
	T *tmp=new T[new_sz];
	unsigned int x;
	for (x=0;x<sz&&x<new_sz;x++)
		tmp[x]=arr[x];
	while (x<new_sz)
		tmp[x++]=value;
	delete[] arr;
	cap=sz=new_sz;
	arr=tmp;
}

template <class T>
void Vector<T>::reverse(){
	//reverse the order of the elements
	T tmp;
	for (unsigned int x=0;x<sz/2;x++){
		tmp=arr[x];
		arr[x]=arr[sz-1-x];
		arr[sz-1-x]=tmp;
	}
}

template <class T>
T Vector<T>::at(unsigned int position) const{
	//Return a copy of value at index position - will exit program if invalid index
	validateIndex(position);
	return arr[position];
}

template <class T>
T Vector<T>::pop_back(){
	//Return the last element of the array - will exit program if vector is empty
	T tmp=at(sz-1);
	sz--;
	if (sz<cap/3) shrink();
	return tmp;
}

template <class T>
void Vector<T>::clear(){
	//remove all elements from vector
	delete[] arr;
	sz=0;
	cap=VECTOR_DFLT_CAP;
	arr=new T[cap];
}

template <class T>
void Vector<T>::expand() {
	cap*=2;
	T *tmp=new T[cap];
	for (unsigned int x=0;x<sz;x++)
		tmp[x]=arr[x];
	delete[] arr;
	arr=tmp;
}

template <class T>
void Vector<T>::shrink() {
	cap/=2;
	if (cap<sz) cap=sz;
	T *tmp=new T[cap];
	for (unsigned int x=0;x<sz;x++)
		tmp[x]=arr[x];
	delete[] arr;
	arr=tmp;
}

template <class T>
void Vector<T>::validateIndex(unsigned int position) const{
	//exit program if position is out of bounds
	if (position>=sz){
		std::cerr << "Vector invalid index value:" << position << " Size:" << sz << std::endl;
		exit(-1);
	}
}

#endif /* XVECTOR_H_ */
