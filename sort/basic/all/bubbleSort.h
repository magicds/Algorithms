#pragma once
template <typename T>
// 冒泡排序
void bubbleSort(T arr[], int n) {
	int newEndIdx;
	do {
		newEndIdx = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				// 内层循环完成后 最后已经是最大，下一轮外层无须再次进行
				// 记录最后一次交换的结束位置 用于优化外层循环的遍历次数
				newEndIdx = i + 1;
			}
		}
		n = newEndIdx;
	} while (newEndIdx > 0);
}