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
void swap(T a[], int x, int y) //���x����y ���÷���ʧЧ��
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

//��������
template<typename T>
void QuickSort(T a[], int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int x = a[left];//��׼ֵ
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
		//���εݹ�
		QuickSort(a, left, i - 1);
		QuickSort(a, i + 1, right);


	}
}

#endif

