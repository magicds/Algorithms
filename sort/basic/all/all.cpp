// all.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>;
#include <math.h>;
#include "sorttesthelper.h";
#include "selectionSort.h";
#include "insertionSort.h";
#include "bubbleSort.h";

using namespace std;


template <typename T>
void bubbleSort1(T arr[], int n) {
	int c = 0;
	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
			SortTestHelper::printArray(arr, n);
			c++;
		}
		// 内层循环完成后 最大的已经在最后了
		// 实际外层的下一次无须继续到最后的位置
	}

	cout << "循环次数:" << c << endl;
}

// 优化外层的结束索引
template <typename T>
void bubbleSort2(T arr[], int n) {
	int c = 0;

	int newEndIdx;
	do {
		newEndIdx = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				newEndIdx = i + 1;
				SortTestHelper::printArray(arr, n);
			}
			c++;
		}
		n = newEndIdx;
	} while (newEndIdx > 0);

	cout << "循环次数:" << c << endl;
}

void testBubble() {
	int n = 10;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	std::cout << "初始数组:\n";
	SortTestHelper::printArray(arr1, n);

	SortTestHelper::testSort("bubbleSort1", bubbleSort1, arr1, n);
	SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

	SortTestHelper::printArray(arr1, n);
	SortTestHelper::printArray(arr2, n);

	delete[] arr1;
	delete[] arr2;
}


void testSortedArr(int n) {
	int swapTimes = 0;
	cout << "\n\n 完全有序排序测试，长度：" << n << "，被打乱的元素对：" << swapTimes << endl;
	int* arr = SortTestHelper::generateNearlySortedArray(n, swapTimes);
	int* arr1 = SortTestHelper::copyIntArray(arr, n);
	int* arr2 = SortTestHelper::copyIntArray(arr, n);

	// SortTestHelper::testSort("selectionSort", selectionSort, arr, n);
	SortTestHelper::testSort("bubbleSort", bubbleSort, arr1, n);
	SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);

	delete[] arr;
	delete[] arr1;
	delete[] arr2;
}
int main()
{
	int n = 10000;

	cout << "\n 随机数组排序测试，长度：" << n << endl;
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr1 = SortTestHelper::copyIntArray(arr, n);
	int* arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("selectionSort", selectionSort, arr, n);
	SortTestHelper::testSort("bubbleSort", bubbleSort, arr1, n);
	SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);
	delete[] arr;
	delete[] arr1;
	delete[] arr2;


	n = 10000;
	int swapTimes = 100;
	cout << "\n\n 近乎有序数组排序测试，长度：" << n << "，被打乱的元素对：" << swapTimes << endl;
	arr = SortTestHelper::generateNearlySortedArray(n, swapTimes);
	arr1 = SortTestHelper::copyIntArray(arr, n);
	arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("selectionSort", selectionSort, arr, n);
	SortTestHelper::testSort("bubbleSort", bubbleSort, arr1, n);
	SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);
	delete[] arr;
	delete[] arr1;
	delete[] arr2;

	// 有序数组排序测试
	testSortedArr(pow(10, 4));
	testSortedArr(pow(10, 5));
	testSortedArr(pow(10, 6));
	testSortedArr(pow(10, 7));
	testSortedArr(pow(10, 8));


	system("pause");
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


