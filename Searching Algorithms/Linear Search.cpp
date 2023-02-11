#include <iostream>
using namespace std;

int LinearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int main() {
	int key;
	int arr[10];

	cout << "Enter the elements of the array: " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	cout << "Enter the key to search: ";
	cin >> key;

	int result = LinearSearch(arr, 10, key);

	if (result == -1)
		cout << "Key not found!";
	else
		cout << "Key found at index: " << result;
}