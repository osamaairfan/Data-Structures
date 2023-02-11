#include <iostream> 
using namespace std;

int  InterpolationSearch(int arr[], int low, int high, int key) {
	if (low > high)
		return -1;
	/*Interpolation Search Formula*/
	int index = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

	if (arr[index] == key)
		return index;

	if (arr[index] < key)         /*If key is greater than index, it is in the right subarray*/
		InterpolationSearch(arr, index + 1, high, key);

	else if (arr[index] > key)    /*If key is lesser than index, it is in the left subarray*/
		InterpolationSearch(arr, low, index - 1, key);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };        /*Interpolation Search works only on sorted arrays*/
	int key = 1;
	int index = InterpolationSearch(arr, 0, 9, key);

	if (index == -1)
		cout << "Key not found!";
	else
		cout << "Key found at index " << index;

	return 0;
}
