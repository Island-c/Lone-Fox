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
void swap(T a[], int x, int y) //如果x等于y ，该方法失效。
{
	if (x != y)
	{
		a[x] = a[x] + a[y];
		a[y] = a[x] - a[y];
		a[x] = a[x] - a[y];
	}
	else
	{
		T temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}

}
//快速排序

//处理枢纽值
template<typename T>
void dealPivot(T a[], int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
		swap(a, left, mid);
	if (a[left] > a[right])
		swap(a, left, right);
	if (a[right] < a[mid])
		swap(a, right, mid);
	swap(a, right - 1, mid);

}


//排
template<typename T>
void quickSort(T a[], int left, int right)
{
	if (left < right)
	{
		//排好枢纽以及首尾 三个值
		dealPivot(a, left, right);
		int pivot = right - 1;
		int i = left;
		int j = right - 1;
		while (true)
		{
			while(a[++i]<a[pivot])
			{ }
			while (j > left && a[--j] > a[pivot])
			{ }
			if (i < j)
				swap(a, i, j);
			else
				break;
		}
		if (i < right)
			swap(a, i, right - 1);
	
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
	}
}

template<typename T>
void QuickSort(T a[], int size)
{
	quickSort(a, 0 ,size - 1);
}


#endif

