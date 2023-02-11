#include <iostream> 
using namespace std;

void SelectionSort(int arr[], int n ) {
	for (int i = 0; i < n; i++) {
		int min = i;    /*Take the first value as min*/

		for (int j = i + 1; j < n; j++) 
			if (arr[j] < arr[min]) 
				min = j;     /*Change the min value if found smaller than that*/

		/*Swap the found min value with the first element*/
		int temp = arr[min]; 
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	int arr[] = { 2,5,7,9,1,3,8 };
	SelectionSort(arr, 7);
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
}