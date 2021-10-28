#include<iostream>
#include<conio.h>
using namespace std;

int insertionInArray(int array[], int size) {

	for (int i = 0; i < size; i++) {
		cout << "Plese enter the " << i << " element in your array: ";
		cin >> array[i];
	}
	return 0;
}

int insertionSort(int array[], int size) {
	for (int i = 1; i < size; i++) {	// Triverse from the 2nd elemenet that's why i=1
		int current = array[i];
		int j = i - 1;
		while (array[j] > current && j >= 0) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = current;
	}
	return 0; 
}

void merge(int array[], int l, int r, int mid) {

	int i = l;						// i index for the 1st Array
	int j = mid + 1;				// j index for the 2nd Array
	int t = l;						// t index for the Temp Array
	int temp[100];
	while (i<=mid && j<=r)
	{
		if (array[i] >= array[j]) {
			temp[t] = array[j];
			j++; t++;
		}
		else {
			temp[t] = array[i];
			i++; t++;
		}
	}
	while (i <= mid) {
		temp[t] = array[i];
		i++; t++;
	}
	while (j <= r) {
		temp[t] = array[j];
		j++; t++;
	}

	for (int p = l; p <= r; p++) {
		array[p] = temp[p];
	}

}

void mergeSort(int array[], int l, int r) {
	if (l < r) {

		int mid = (l + r) / 2;
		mergeSort(array, l, mid);
		mergeSort(array, mid + 1, r);
		merge(array, l, r, mid);

	}
}

void bubbleSort(int arr[], int size) {
	int counter = size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < counter - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			
		}
		counter--;
	}
}

//	QuickSort Starts from here

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int l, int r) {
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, r);
	return i + 1;
}

void quickSort(int arr[], int l, int r) {
	if (l < r) {
		int pi = partition(arr, l, r);
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, r);
	}
}

void displayArray(int array[], int size) {
	cout << "\nThe elements in your array are: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}


void main(void) {
	
	cout << "How many elements of the array you want? ";
	int size;
	cin >> size;

	int *array = new int[size];
	insertionInArray(array, size);
	//mergeSort(array, 0, 29);

	bubbleSort(array, size);

	////	quickSort(array, 0, size - 1);
	displayArray(array, size);
	/*char s[1] = { 'a' };
	int i, sum;
	sum = 0;
	for (i = 0; i < strlen(s); i++) 
		{ sum = sum + s[i]; }
	cout << sum<<endl;
	
	_getch();*/
	system("pause");
}