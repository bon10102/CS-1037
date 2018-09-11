#include <iostream>

using namespace std;

void print(double arr[], int sz) {
	for (int x = 0; x < sz; x++)
		cout << arr[x] << " ";
	cout << endl;
}

void init(double arr[], int sz) {
	for (int x = 0; x < sz; x++)
		arr[x] = rand() % 100;
}

void rotate(double arr[], int sz) {
	double temp = arr[0];
	for (int x = 1; x < sz; x++)
		arr[x-1] = arr[x];
	arr[sz - 1] = temp;
}

void copy1(const double src[], int sz, double dst[]) {

}
int main() {
	const int sz = 5;
	double arr[sz] = { 3, 2, 1 };
	init(arr, sz);
	print(arr, sz);
	rotate(arr, sz);
	print(arr, sz);

	int a = 5;
	cout << "a=" << a << endl;
	cout << "address " << &a << endl;

	char c;
	cin >> c;
}