#ifndef _HEAD_H
#define _HEAD_H
#include<string>

//归并 非递归
template<typename T>
void Merge(T &a, T &b, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= right)
		b[k++] = a[j++];
	for (i = left; i <= right; ++i)
	{
		a[i] = b[i];
	}
}
template<typename T>
void merge_pass(T *a, T *temp, int s, int len)
{
	int i = 0;
	while (i < len - 2 * s + 1)
	{
		Merge(a, temp, i, i + s - 1, i + s - 1 + s);
		i += 2 * s;
	}
	if (i < len - s + 1)
		Merge(a, temp, i, i + s - 1, len);//归并最后两个序列
}
template<typename T>
void merge_sort_no_recurse(T *a, int size)
{
	T *temp = new T[size];
	int k = 1;
	while (k <= size-1)
	{
		merge_pass(a, temp, k, size-1);
		k *= 2;//子序列长度加倍
	}
	delete[]temp;
}

#endif
