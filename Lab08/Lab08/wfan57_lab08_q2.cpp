/*
	Purpose: Find the averages of 3 different courses and determines
		the courses with the highest and lowest average
	
	@author Wayne Fan
	@version 1.0 04/05/2018
*/
#include <iostream>
#include <string>

using namespace std;

/*
	Populates the array of each course with grades and finds the course average
	@param *&ptrArr the array of grades
	@param &avg the array to store the course average
	@param size the size of the array of grades
*/
void populateAndFindAverage(double *&ptrArr, double &avg, int size);

//Controls operation of program
int main() {
	double *ptr[3] = {};
	string names[3] = { "ES1036", "ES1050", "ES1021" };
	double average[3];
	int classSize;
	int maxMark = 0;
	int minMark = 0;
	//Fills courses with grades
	for (int i = 0; i < 3; i++){
		cout << "Enter class size for " << names[i] << ": ";
		cin >> classSize;
		ptr[i] = new double[classSize]();
		populateAndFindAverage(ptr[i], average[i], classSize);
	}
	//Determines the course with lowest/highest average
	double max = average[0];
	double min = average[0];
	for (int i = 0; i < 3; i++) {
		if (average[i] > max) {
			max = average[i];
			maxMark = i;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (average[i] < min) {
			min = average[i];
			minMark = i;
		}
	}
	cout << names[maxMark] << " course has the highest class average.\n";
	cout << names[minMark] << " course has the lowest class average.\n";

	//Releases memory taken up by the course grades
	for (int i = 0; i < 3; i++) {
		delete ptr[i];
		ptr[i] = NULL;
	}
	cout << "\nGoodbye!\n";
	return 0;
}

//Populates the array of each course with grades and finds the course average
void populateAndFindAverage(double *&ptrArr, double &avg, int size){
	char choice;
	int extraStudents = 0;
	double sum = 0;
	for (int i = 0; i < size; i++) {
		cout << "Enter grade for student " << i + 1 << ": ";
		cin >> ptrArr[i];
	}
	cout << "Have all students been added (y/n)? "; cin >> choice;
	tolower(choice);
	if (choice == 'n') {
		cout << "How many students do you wish to add? "; cin >> extraStudents;
		double *temp = new double[size + extraStudents]();
		for (int i = 0; i < size; i++) {
			temp[i] = ptrArr[i];
		}
		delete [] ptrArr;
		ptrArr = NULL;
		ptrArr = temp;

		for (int i = size; i < (size + extraStudents); i++) {
			cout << "Enter grade for student " << i + 1 << ": ";
			cin >> ptrArr[i];
		}
	}
	for (int i = 0; i < size + extraStudents; i++) {
		sum += ptrArr[i];
	}
	avg = sum / (size + extraStudents);
	cout << "Class average: " << avg << endl << endl;
}
