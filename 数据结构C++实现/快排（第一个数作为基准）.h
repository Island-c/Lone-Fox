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
template<typename T>
void QuickSort(T a[], int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int x = a[left];//基准值
		while (i < j)
		{
			while (i < j && a[j] >= x)
				j--;
			if (i < j)
				a[i++] = a[j]; 
			while (i < j && a[i] < x)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		//分治递归
		QuickSort(a, left, i - 1);
		QuickSort(a, i + 1, right);


	}
}

#endif

