/*
	Purpose: Use classes to store employee data

	@author Wayne Fan
	@version 1.0 04/05/2018
*/
#include <iostream>
#include <string>

using namespace std;

//Employee class, has properties, firstname, lastname, ID, and salary
class Employee {
public:
	string m_firstName;
	string m_lastName;
	int m_ID;
	int m_Salary;
	Employee() {}
	void printInfo() {
		cout << m_firstName;
		for (int i = 0; i <= (13-m_firstName.length()); i++) {
			cout << " ";
		}
		cout << m_lastName;
		for (int i = 0; i <= (14 - m_lastName.length()); i++) {
			cout << " ";
		}
		cout << m_ID;
		for (int i = 0; i <= 4; i++) {
			cout << " ";
		}
		cout << m_Salary;
	}
	~Employee(){
		cout << "Employee deallocated.\n";
	}
};

/*
	Assigns properties to each employee object
	@param database[] the array where employee objects are stored
	@param size the size of the database array
*/
void dataEntry(Employee database[], int size);

/*
	Prints the properties of each employee object
	@param *myArray the array where employee objects are stored
	@param size the size of myArray
*/
void printArray(Employee *myArray, int size);

//Controls operation of program
int main() {
	int databaseSize;
	Employee *database;
	cout << "Enter number of employees in the database: ";
	cin >> databaseSize;
	cout << "\nCreating the database...\n\n";
	database = new Employee[databaseSize]();
	dataEntry(database, databaseSize);
	printArray(database, databaseSize);

	cout << endl << endl;
	delete[] database;
	database = NULL;
}

//Assigns properties to each employee object
void dataEntry(Employee database[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the first name for employee " << i+1 << ": ";
		cin >> database[i].m_firstName;
		cout << "Enter the last name for employee " << i+1 << ": ";
		cin >> database[i].m_lastName;
		cout << "Enter the ID for employee " << i+1 << ": ";
		cin >> database[i].m_ID;
		do {
			cout << "Enter the salary for employee " << i+1 << ": ";
			cin >> database[i].m_Salary;
		} while (database[i].m_Salary < 0);
		cout << endl;
	}
}

//Prints the properties of each employee object
void printArray(Employee *myArray, int size) {
	cout << "Employee Listing: " << endl;
	cout << "Last          First          ID       Salary" << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		myArray[i].printInfo();
		cout << endl;
	}
}

