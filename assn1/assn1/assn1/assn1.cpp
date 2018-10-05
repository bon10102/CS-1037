/**
	Purpose: Calculates average, median, or sum depending
		on the program arguments

	@author Wayne Fan
	@version 1.0 23/09/2018
*/
#include <iostream>

using namespace std;

/**
	Calculates the average (mean) of an array of doubles
	@param *values[] the array of doubles to have its average calculated
	@param sz the size of the array
	@return avg the average of the double array
*/
double calcAverage(char *values[], int sz);

/**
	Calulate the median of an array of doubles
	@param *values[] the array of doubles ot have its median calcualted
	@param sz the size of the array;
	@return med the median of the double array
*/
double calcMedian(char *values[], int sz);

/**
	calculates the sum of an array of doubles
	@param *values[] the array of doubles to have its sum calculated
		note that this function only works exactly three numbers
	@return sum the sum of the three values
*/
double calcSum(char *values[]);

/**
prints a specified array with spaces between elements
@param *values[] the array of characters to be printed
@param sz the size of the array
*/
void print(char *values[], int sz);

/**
uses bubblesSort to sort an array of doubles
@param *values[] the array of doubles to be sorted
@param sz the size of the array
*/
void bubbleSort(double *arr, int sz);

//Controls operation of program
int main(int argc, char *argv[]) {
	//The following code determines which function will be used
	if (*argv[1] == 'A') {
		cout << "Average" << endl;
		print(&argv[2], argc - 2);
		cout << calcAverage(&argv[2], argc-2);
	}
	else if (*argv[1] == 'M') {
		cout << "Median" << endl;
		print(&argv[2], argc - 2);
		cout << calcMedian(&argv[2], argc-2);
	}
	else if (*argv[1] == 'F') {
		cout << "Sum" << endl;
		print(&argv[2], argc - 2);
		cout << calcSum(&argv[2]);
	}
}

//Calculates the average (mean) of an array of doubles
double calcAverage(char *values[], int sz) {
	double sum = 0;
	double avg;
	//convert input array to doubles, place values in a new array
	double *numbers = new double[sz];
	for (int i = 0; i < sz; i++) {
		numbers[i] = atof(values[i]);
	}
	for (int i = 0; i < sz; i++) {
		sum += numbers[i];
	}
	delete[] numbers;
	avg = sum / sz;
	return avg;
}

//Calulate the median of an array of doubles
double calcMedian(char *values[], int sz) {
	double med;
	//convert input array to doubles, place values in a new array
	double *numbers = new double[sz];
	for (int i = 0; i < sz; i++) {
		*(numbers + i) = atof(*(values + i));
	}
	bubbleSort(numbers, sz);
	if (sz % 2 == 1) {
		med = *(numbers + (sz / 2));
	}
	else {
		double sum = *(numbers + ((sz / 2) - 1)) + *(numbers + (sz / 2)); 
		med = sum / 2.0;
	}
	delete[] numbers; 
	return med; 
}

//Calculates the sum of an array of doubles
double calcSum(char *values[]) {
	double numbers[3] = {};
	double sum = 0;
	//convert input array to doubles, place values in a new array
	for (int i = 0; i < 3; i++) {
		numbers[i] = atof(values[i]);
	}
	for (int i = 0; i < 3; i++) {
		sum += numbers[i];
	}
	return sum;
}

//Prints a specified array with spaces between elements
void print(char *values[], int sz) {
	for (int i = 0; i < sz; i++) {
		cout << atof(values[i]) << " ";
	}
	cout << endl;
}

//Uses bubblesSort to sort an array of doubles
void bubbleSort(double *arr, int sz) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < sz - 1; i++) {
			if (*(arr + i) > *(arr + i + 1)) {
				double temp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = temp;
				swapped = true;
			}
		}
	} while (swapped == true);
}
