#ifndef _HEAD_H
#define _HEAD_H



//�鲢����

//�������кϲ�
template<typename T>
void mergearray(T a[], int first, int mid, int last, T temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; ++i) //��temp�е�Ԫ�ؿ�����a�С�
		a[first+i] = temp[i]; 
	print(a, 7);
	cout << endl;
}

template<typename T>
void  mergesort(T a[], int first, int last, T temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);
		mergesort(a, mid + 1, last, temp);
		mergearray(a, first, mid, last, temp);
	}
}

template<typename T>
void MergeSort(T a[], int size)
{
	int *p = new T[size];
	if (p == nullptr)
		return;
	mergesort(a, 0, size - 1, p);
	delete[]p;
	return;
}


#endif

