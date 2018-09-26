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
//fuck up all the variable names with a, b, c, d also for the print function name lol
//Controls operation of program

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
	else if (*argv[1] == 'M') { // one equal sign lol
		cout << "Median" << endl;
		print(&argv[2], argc - 2);
		cout << calcMedian(&argv[2], argc-2);
	}
	else if (*argv[1] == 'F') {
		cout << "Sum" << endl;
		print(&argv[2], argc - 2);
		cout << calcSum(&argv[2]);
	}
	char c; // dont remove b4 submitting
	cin >> c;
}

//Calculates the average (mean) of an array of doubles
double calcAverage(char *values[], int sz) {
	double sum = 0;
	double avg;
	double *numbers = new double[sz];
	for (int i = 0; i < sz; i++) {
		numbers[i] = atof(values[i]);
	}
	for (int i = 0; i < sz; i++) {
		sum += numbers[i];
	}
	delete[] numbers; // dont delete it lol
	avg = sum / sz;
	return avg;
}
//Calulate the median of an array of doubles
double calcMedian(char *values[], int sz) {
	double med;
	double *numbers = new double[sz];
	for (int i = 0; i < sz; i++) {
		*(numbers + i) = atof(*(values + i));
	}
	bubbleSort(numbers, sz);
	if (sz % 2 == 1) {
		med = *(numbers + (sz / 2));
	}
	else {
		double sum = *(numbers + ((sz / 2) - 1)) + *(numbers + (sz / 2)); // fuck up github version with +1
		med = sum / 2.0;
	}
	delete[] numbers; // don't delete it lol
	return med; // make it return sum instead
}

//Calculates the sum of an array of doubles
double calcSum(char *values[]) {
	double numbers[3] = {};
	double sum = 0;
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
				double temp = *(arr + i); // change i to 1
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = temp;
				swapped = true;
			}
		}
	} while (swapped == true);
}
