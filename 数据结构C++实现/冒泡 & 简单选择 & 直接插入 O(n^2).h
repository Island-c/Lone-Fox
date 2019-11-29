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

//冒泡法
template<typename T>
void BubbleSort(T a[], int size)
{
	for(int i=0;i<size;++i)
		for (int j = 0; j < size - i - 1; ++j)
		{
			if(a[j]>a[j+1])
				swap(a, j, j + 1);
		}
}

//简单选择排序 ,比较次数和冒泡一样，但交换次数要优于冒泡
template<typename T>
void SelectSort(T a[], int size)
{
	int i, j, min;
	for (i = 0; i < size - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < size; ++j)
		{
			if (a[min] > a[j])
				swap(a, min, j);
		}
	}
}

//直接插入排序, O(n^2),但性能略优于上面两个。
template<typename T>
void InsertSort(T a[], int size)
{
	int i, j;
	for (i = 1; i < size; ++i)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			for (j = i - 1; a[j] > temp; --j)
				//当a[j]>temp时，不正常，就继续循环，--j
			{
				a[j + 1] = a[j];
			}
			//目前a[j]是正确的a[j]<=temp，把temp放在j后面即可
			a[j + 1] = temp;
		}
	}
	
}

#endif