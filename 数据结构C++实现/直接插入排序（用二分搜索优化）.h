#ifndef _HEAD_H
#define _HEAD_H
#include<string>

template<typename T>
void print(T &a, int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << "  ";
	cout << endl;
}


//�ö��ֲ����Ż�ֱ�Ӳ�������
//��Ч���ٱȽϴ���
//���ڳ���Ϊn��������˵���Ƚϴ���Ϊlog2n ,ʱ�临�Ӷ�ΪO��log2n��
//������ÿ�ζ����������е���ʼλ�ò��룬�������������е�Ԫ����Ҫ���ƣ�ʱ�临�Ӷ�ΪO��n^2��
//������(��������)�����������鱾���������ģ�ÿ��Ԫ������λ�ü�Ϊ���Ĳ���λ�ã���ʱʱ�临�ӶȽ�Ϊ�Ƚ�ʱ��ʱ�临�Ӷ�
//ΪO(log2n)
//ƽ�������O��n^2��
template<typename T>
int Binary_Insert(T *a, int beg, int end, const T&value)
{
	while (beg <= end)
	{
		int mid = (beg + end) >> 1;
		if (a[mid] > value)
			end = mid - 1;
		else
			beg = mid + 1;
	}
	return beg;  //Emmmmm ����λ���ǵ�һ����value�����
}

template<typename T>
void InsertSort_Binary(T *a, int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			//Ѱ��a[i]�ĺ��ʵĲ���λ�á�
			int index = Binary_Insert(a, 0, i, temp);
			for (int j = i - 1; j >= index; --j)
			{
				a[j + 1] = a[j];
			}
			a[index] = temp;
		}
	}
}

#endif
