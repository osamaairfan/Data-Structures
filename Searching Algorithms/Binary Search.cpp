#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key) {
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == key)
		return mid;

	if (arr[mid] < key)                /*If key is greater than mid, it is in the right subarray*/
		BinarySearch(arr, mid + 1, high, key);

	else if (arr[mid] > key)           /*If key is lesser than mid, it is in the left subarray*/
		BinarySearch(arr, low, mid - 1, key);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };        /*Binary Search works only on sorted arrays*/
	int key = 5;
	int index = BinarySearch(arr, 0, 9, key);

	if (index == -1)
		cout << "Key not found!";
	else
		cout << "Key found at index " << index;

	return 0;
}