#include <iostream>
#include <ctime>

using namespace std;

void print(int sz, char arr[]);
void init(char arr[], int sz);
void swapElements(char arr[], int index1, int index2);
void randomizeArray(char arr[], int sz);
void bubbleSort(char arr[], int sz);

int main(int argc, int *argv[]) {
	int alphabetSize;
	char alphabet[32] = {};
	char letters[] = {'A', 'B' ,'C'};

	print(3, letters);

	cout << "Enter array size: ";
	cin >> alphabetSize;
	init(alphabet, alphabetSize);
	print(alphabetSize, alphabet);

	/*
	int elem1;
	int elem2;
	cout << "Choose 2 elements to swap: " << endl;
	cin >> elem1;
	cin >> elem2;
	swapElements(alphabet, elem1, elem2);
	print(alphabetSize, alphabet);
	*/

	randomizeArray(alphabet, alphabetSize);
	print(alphabetSize, alphabet);

	bubbleSort(alphabet, alphabetSize);
	print(alphabetSize, alphabet);

	char c;
	cin >> c;
}

void print(int sz, char arr[]) {
	for (int i = 0; i < sz - 1; i++) 
		cout << arr[i] << ":";
	cout << arr[sz - 1] << endl;
}

void init(char arr[], int sz) {
	for (int i = 0; i < sz; i++) {
		arr[i] = 'A'+ i%26;
	}
}

void swapElements(char arr[], int index1, int index2) {
	char temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void randomizeArray(char arr[], int sz) {
	srand((unsigned)time(NULL));
	for (int p = 0; p < sz; p++) {
		int r = rand()%sz;
		swapElements(arr, p, r);
	}
}

void bubbleSort(char arr[], int sz) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < sz-1; i++) {
			if (arr[i] > arr[i + 1]) {
				char temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped == true);
}