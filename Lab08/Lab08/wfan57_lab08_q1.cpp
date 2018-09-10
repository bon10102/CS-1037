/*
	Purpose: use pointers and DMA to calculate mean and standard
		deviation of for an array of numbers
	@author Wayne Fan
	@version 1.0 04/05/2018
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
	Increases the size of the array when it approaches its maximum storage
	@param *&array the array to have its size increased
	@param *curentArrayMaxSize the address of the variable storing the max size of array
	@param numberOfLocationsUsed the current number of used locations in the array
*/
void increaseSize(double *&array, int *currentArrayMaxSize, int numberOfLocationsUsed);

/*
	Computes the mean of an array of numbers
	@param *array the array storing the numbers
	@param size the size of the array storing the numbers
	@return mean the calculated mean
*/
double computeMean(const double *array, int size);

/*
	Computes the standard deviation of an array of numbers
	@param array[] the array storing the numbers
	@param size the size of the array
	@param mean the mean of the numbers in the array
	@return std the calculated standard deviation
*/
double computeStdDev(const double array[], int size, double mean);

//Controls operation of program
int main() {
	double *inputs = NULL;
	double input;
	double mean;
	int sizeOfArray = 5;
	int locationsUsed = 0;
	inputs = new double[sizeOfArray];

	while (1) {
		cout << "Enter Real Number " << locationsUsed + 1 << " (0 to exit): ";
		cin >> input;
		if (input == 0) {
			break;
		}
		inputs[locationsUsed] = input;
		locationsUsed++;

		mean = computeMean(inputs, locationsUsed);
		cout << "The current mean is " << fixed << setprecision(3) << mean << endl;
		cout << "The current standard deviation is: " << computeStdDev(inputs, locationsUsed, mean) << endl;
		//Increases the size of the array storing the numbers if it approaches its max size
		if ((sizeOfArray - locationsUsed) < 3) {
			increaseSize(inputs, &sizeOfArray, locationsUsed);
		}
	}
	cout << "\nGoodbye!\n";
	return 0;
}

//Increases the size of the array when it approaches its maximum storage
void increaseSize(double *&array, int *currentArrayMaxSize, int numberOfLocationsUsed) {
	*currentArrayMaxSize = *currentArrayMaxSize + 5;
	double *temp = new double[*currentArrayMaxSize];
	for (int i = 0; i < numberOfLocationsUsed; i++) {
		temp[i] = array[i];
	}
	delete array;
	array = NULL;
	array = temp;
	cout << "\nThe possible number of inputs to store has increased to " 
		<< *currentArrayMaxSize << endl << endl;
}

//Computes the mean of an array of numbers
double computeMean(const double *array, int size) {
	double sum = 0;
	double mean;
	for (int i = 0; i < (size); i++) {
		sum += array[i];
	}
	mean = sum / size;
	return mean;
}

//Computes the standard deviation of an array of numbers
double computeStdDev(const double array[], int size, double mean) {
	double sum = 0;
	double std;
	for (int i = 0; i < size; i++) {
		sum += pow((array[i] - mean), 2);
	}
	std = sqrt(sum / size);
	return std;
}
