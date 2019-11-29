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



//ϣ������ ������
template<typename T>
void ShellChangeSort(T a[], int size)
{
	//����gap������С����
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		//�Ե�gap��Ԫ�أ�����������ڵ���ֱ�Ӳ�������
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

//ϣ������ �ƶ���
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