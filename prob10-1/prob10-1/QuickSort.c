#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int MedianOfThree(int arr[], int left, int right) {
	if (arr[left] >= arr[right] && arr[left] <= arr[(left + right) / 2]) {
		//arr[left] is median
		return left;
	}
	else if (arr[right] >= arr[left] && arr[right] <= arr[(left + right) / 2]) {
		//arr[right] is median
		return right;
	}

	else {
		return arr[(left + right) / 2];
	}
}


int Partition(int arr[], int left, int right) {
	//int pivot = arr[left];
	//int low = left + 1;
	//int high = right

	int pivotIndex = MedianOfThree(arr, left, right);
	int pivot = arr[pivotIndex];
	int low = left + 1;
	int high = right;

	Swap(arr, left, pivotIndex);
	printf("pivot is %d\n", pivot);

	while (low <= pivot && high >= pivot) {
		while (pivot > arr[low])
			low++;
		while (pivot < arr[high])
			high--;
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main() {
	//int arr[7] = { 3,2,4,1,7,6,5 };
	//int arr[3] = { 3,3,3 };
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}