#ifndef _HEAD_H
#define _HEAD_H

//��ӡ��
template<typename T>
void print(T a[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << "   ";
	cout << endl;
}

//��������Ԫ�ء�
template<typename T>
void swap(T n[], int a, int b)
{
	n[a] = n[a] + n[b];
	n[b] = n[a] - n[b];
	n[a] = n[a] - n[b];
}

//ð�ݷ�
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

//��ѡ������ ,�Ƚϴ�����ð��һ��������������Ҫ����ð��
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

//ֱ�Ӳ�������, O(n^2),����������������������
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
				//��a[j]>tempʱ�����������ͼ���ѭ����--j
			{
				a[j + 1] = a[j];
			}
			//Ŀǰa[j]����ȷ��a[j]<=temp����temp����j���漴��
			a[j + 1] = temp;
		}
	}
	
}

#endif