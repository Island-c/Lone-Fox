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

//归并排序
// 合
template<typename T>
void merge(T a[], int first, int mid, int last, T temp[])
{
	int i = first;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= last)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= last)
		temp[k++] = a[j++];

	for (i = 0; i < k; ++i)
	{
		a[first++] = temp[i];//注意拷贝 temp从0开始，而a从first开始。
	}
}
//分
template<typename T>
void sort(T a[], int first, int last, T temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		sort(a, first, mid, temp);
		sort(a, mid + 1, last, temp);
		merge(a, first, mid, last , temp);
	}
}

template<typename T>
bool MergeSort(T a[], int size)
{
	T *p = new T[size];
	if (p == nullptr)
		return false;
	sort(a, 0, size - 1, p);
	delete[]p;
	return true;
}




#endif

