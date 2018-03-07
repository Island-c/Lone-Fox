#ifndef _HEAD_H
#define _HEAD_H
#include<string>

template<typename T>
void print(T &a, int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << "  ";
	cout << endl;
}


//用二分查找优化直接插入排序
//有效减少比较次数
//对于长度为n的数组来说，比较次数为log2n ,时间复杂度为O（log2n）
//最坏情况：每次都在有序序列的起始位置插入，则整个有序序列的元素需要后移，时间复杂度为O（n^2）
//最好情况(提升明显)：待排序数组本身就是正序的，每个元素所在位置即为它的插入位置，此时时间复杂度仅为比较时的时间复杂度
//为O(log2n)
//平均情况：O（n^2）
template<typename T>
int Binary_Insert(T *a, int beg, int end, const T&value)
{
	while (beg <= end)
	{
		int mid = (beg + end) >> 1;
		if (a[mid] > value)
			end = mid - 1;
		else
			beg = mid + 1;
	}
	return beg;  //Emmmmm 返回位置是第一个比value大的数
}

template<typename T>
void InsertSort_Binary(T *a, int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			//寻找a[i]的合适的插入位置。
			int index = Binary_Insert(a, 0, i, temp);
			for (int j = i - 1; j >= index; --j)
			{
				a[j + 1] = a[j];
			}
			a[index] = temp;
		}
	}
}

#endif
