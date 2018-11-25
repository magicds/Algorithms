// 06-Insertion-sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "selectionSort.h"
#include "SortTestHelper.h"
#include "insertionSort.h"

using namespace std;

void main() {
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	cout << "正常数组排序,长度：" << n << endl;
	SortTestHelper::printArray(arr, 10);

	SortTestHelper::testSort("insertionSort", insertionSort, arr, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);

	SortTestHelper::printArray(arr, 10);
	SortTestHelper::printArray(arr2, 10);

	delete[] arr;
	delete[] arr2;

	n = 10000;
	int swapTimes = 100;
	int *arr3 = SortTestHelper::generateNearlySortedArray(n, swapTimes);
	int *arr4 = SortTestHelper::copyIntArray(arr3, n);

	cout << "近乎有序数组排序,长度：" << n << "，其中被打乱的顺序的个数：" << swapTimes << endl;
	SortTestHelper::printArray(arr3, 10);

	SortTestHelper::testSort("insertionSort", insertionSort, arr3, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr4, n);

	SortTestHelper::printArray(arr3, 10);
	SortTestHelper::printArray(arr4, 10);

	delete[] arr3;
	delete[] arr4;
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
