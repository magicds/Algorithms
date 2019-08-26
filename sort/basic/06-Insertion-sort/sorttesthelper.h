#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper {

	// �ж��Ƿ�����ɹ�
	// �ж�arr�����Ƿ�����
	template<typename T>
	bool isSorted(T arr[], int n) {

		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;

		return true;
	}

	// �������鿽��
	int* copyIntArray(int a[], int n) {
		int * arr = new int[n];
		// copy(a, a + n, arr);

		for (int i = 0; i < n; i++) {
			arr[i] = a[i];
		}

		return arr;
	}

	// ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int *generateRandomArray(int n, int range_l, int range_r) {

		int *arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
		return arr;
	}
	// ����һ���������������
	int *generateNearlySortedArray(int n, int swapTimes) {
		int *arr = new int[n];

		for (int i = 0; i < n; i++)
			arr[i] = i;

		srand(time(NULL));

		for (int i = 0; i < swapTimes; i++) {
			int pos_x = rand() % n;
			int pos_y = rand() % n;

			swap(arr[pos_x], arr[pos_y]);
		}
		return arr;
	}

	// ���������ӡ����
	template <typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}

	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {

		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(SortTestHelper::isSorted(arr, n));
		//cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		cout << sortName << " : " << double(endTime - startTime) << " ms" << endl;

		return;
	}

}