#pragma once


template <typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		T temp = arr[j];
		for (; j > 0; j--) {
			if (temp < arr[j - 1]) {
				arr[j - 1] = arr[j];
			}
			else {
				break;
			}
		}

		arr[j] = temp;
	}
}