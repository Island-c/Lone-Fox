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

//快排三位取中。
template<typename T>
void partation(T a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		if (a[mid] < a[left])
			swap(a,mid,left);
		if (a[left] > a[right])
			swap(a, left, right);
		if (a[mid] > a[right])
			swap(a, mid, right);
		cout << "aaa  "; swap(a, mid, right - 1);
		print(a, 7);
	}
}
template<typename T>
void QuickSort(T a[], int left, int right)
{
	if (left < right)
	{
		int i = left;
		partation(a, left, right); //找基准
		int x = a[right - 1]; //基准值
		int j = right-2; //基准值前一位

		while (i < j)
		{
			while (i<j && a[j]>=x)
				j--;
			while (i < j && a[i] < x)
				i++;
			if (i < j)
				swap(a, i, j);
		}
		swap(a, j + 1, right - 1);
		print(a, 7);
		QuickSort(a, left, j);
		QuickSort(a, j + 2, right);


	}
}

#endif

