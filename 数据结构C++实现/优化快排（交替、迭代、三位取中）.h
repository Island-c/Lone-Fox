#pragma once
#include<stack>
template<typename T>
void print(T &a, int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << "  ";
	cout << endl;
}

template<typename T>
void swap(T &x, int a, int b)
{
	if (a != b)
	{
		x[a] = x[a] + x[b];
		x[b] = x[a] - x[b];
		x[a] = x[a] - x[b];
	}
	else
	{
		auto temp = x[a];
		x[a] = x[b];
		x[b] = temp;
	}
}
template<typename T>
void QuickSort(T *a, int size)
{
	Quick(a, 0, size - 1);
}

//ԭʼ�汾
/*
template<typename T>
void Quick(T *a, int left, int right)
{
	if (left < right)
	{
		int pivot = a[left]; //ȡ��Ԫ��Ϊ��׼
		int i = left + 1;
		int j = right;
		while (i < j)
		{
			while (i < j)
			{
				if (a[j] >= pivot && j > i)
					j--;
				else if (a[i] < pivot && i < j)
					i++;
				else
					break;
			}
			if (i < j)
				swap(a, i, j);
			else
				swap(a, left, j);
		}
		print(a, 8);
		Quick(a, left, j - 1);
		Quick(a, j + 1, right);
	}
}
*/
//�Ż�һ �� ʹ���滻�����ǽ����� ���ٲ���Ҫ�Ľ���
/*
template<typename T>
void Quick(T *a, int left, int right)
{
	if (left < right)
	{
		int pivot = a[left];
		int i = left; //�ӻ�׼��ʼ����Ҫ������׼����
		int j = right;
		while (i < j)
		{
			while (i<j && a[j]>=pivot)
				j--;
			if (i < j)
				a[i] = a[j];
			while (i < j && a[i] < pivot)
				i++; 
			if (i < j)
				a[j]=a[i];
		}
		a[j] = pivot;

		print(a, 8);
		Quick(a, left, j - 1);
		Quick(a, j + 1, right);
	}

}
*/


//�Ż����� ʹ�õ��������ǵݹ�
template<typename T>
int QuickPartion(T *a, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = a[left]; 
	while (i < j)
	{
		while (i < j && a[j] >= pivot)
			j--;
		if (i < j)
			a[i] = a[j];
		while (i < j && a[i] < pivot) //��һ����j������i �����j��pivot�Ļ�����һ��ѭ���ᱻ������
			i++;
		if (i < j)
			a[j] = a[i];
	}
	a[j] = pivot;
	print(a, 8);
	return j; //������Ŧ����λ�ã�����������ֳɹ���
}

template<typename T>
void Quick(T *a, int left, int right)
{
	std::stack<T> st;
	if (left < right)
	{
		int mid = QuickPartion(a, left, right);
		if (left < mid - 1)
		{
			st.push(left);
			st.push(mid - 1); //��һ�ε��������left��right
		}
		if (mid + 1 < right)
		{
			st.push(mid + 1);
			st.push(right);
		}

		while (!st.empty())
		{
			int q = st.top();
			st.pop();
			int p = st.top();
			st.pop();
			int mid = QuickPartion(a, p, q);  //ǧ��Ҫע��pq��˳�򡣣�
			if (p < mid - 1)
			{
				st.push(p);
				st.push(mid - 1);
			}
			if (mid + 1 < q)
			{
				st.push(mid + 1);
				st.push(q);
			}
			print(a, 8);
		}
	}

}
