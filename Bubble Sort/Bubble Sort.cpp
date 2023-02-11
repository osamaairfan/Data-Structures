#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr[] = { 5,3,4,2,1 };
	BubbleSort(arr, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}