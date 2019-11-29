#pragma once

#include<iostream>


template<typename T>
void print(T *a, int size)
{
	for (int i = 0; i < size; ++i)
		cout << *a++ << "   ";
	cout << endl;
}

template<typename T>
void Merge(T *a, T *temp, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= right)
		temp[k++] = a[j++];

	for (j = 0; j < k; ++j)
	{
		a[left++] = temp[j];
	}


}

template<typename T>
void MergeN(T *a, T * temp, int skip, int size)
{
	int i = 0;
	while (i + 2 * skip - 1 < size)
	{
		//当前所在的整个组都在范围内时
		Merge(a, temp, i, i + skip - 1, i + 2 * skip - 1);
		i = i + 2 * skip; //i移动到下一组的首位
	}
	if (i + skip - 1 < size) //当前组的前一半在范围时
	{
		Merge(a, temp, i, i + skip - 1, size - 1);
	}
	print(a, 8);
}


template<typename T>
void MergeNoRecursion(T *a, int size)
{
	int skip = 1; //分组间隔
	T *temp = new T[size];
	while (skip < size)
	{
		MergeN(a, temp, skip, size);
		skip *= 2;
	}
}
