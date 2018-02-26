#ifndef _HEAD_H
#define _HEAD_H

//打印。
template<typename T>
void print(T a[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << "   ";
	cout << endl;
}

//交换数组元素。
template<typename T>
void swap(T n[], int a, int b)
{
	n[a] = n[a] + n[b];
	n[b] = n[a] - n[b];
	n[a] = n[a] - n[b];
}



//希尔排序 交换法
template<typename T>
void ShellChangeSort(T a[], int size)
{
	//增量gap，逐渐缩小增量
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		//对第gap个元素，逐个对其所在的组直接插入排序
		for (int i = gap; i < size; ++i)
		{
			int j = i;
			while (j - gap >= 0 && a[j-gap]>a[j])
			{
				swap(a, j, j - gap);
				j -= gap;
				print(a, size);
			}
		}
	}
}

//希尔排序 移动法
template<typename T>
void ShellMoveSort(T a[], int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; ++i)
		{
			int j = i;
			int temp = a[j];
			if (a[j] < a[j - gap]) {
				while (j - gap >= 0 && a[j - gap] > temp)
				{
					a[j] = a[j - gap];
					print(a, size);
					j -= gap;
				}
				a[j] = temp;
			}
		}
	}
}


#endif