template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}

		std::swap(arr[i], arr[minIdx]);
		//T temp = arr[i];
		//arr[i] = arr[minIdx];
		//arr[minIdx] = temp;
	}
}
