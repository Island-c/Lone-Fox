#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
void print(T a[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << "   ";
	cout << endl;
}

template<typename T>
void swap(T a[], int x, int y)
{
	a[x] = a[x] + a[y];
	a[y] = a[x] - a[y];
	a[x] = a[x] - a[y];
}

template<typename T>
void adjustHeap(T a[], int i, int size)
{
	int temp = a[i];
	for (int k = i * 2 + 1; k < size; k = k * 2 + 1)
	{
		if (k + 1 < size && a[k + 1] > a[k])
			k++;
		if (a[k] > temp)
		{
			a[i] = a[k];
			i = k;
		}
		else
			break;
	}
	a[i] = temp;
}

template<typename T>
void sort(T a[], int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		adjustHeap(a, i, size);
	}

	for (int j = size-1; j >0; --j)
	{
		swap(a,0,j);//交换首尾元素
		adjustHeap(a, 0, j); //重新调整
	}
}

#endif