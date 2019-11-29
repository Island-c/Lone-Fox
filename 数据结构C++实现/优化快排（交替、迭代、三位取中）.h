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

//原始版本
/*
template<typename T>
void Quick(T *a, int left, int right)
{
	if (left < right)
	{
		int pivot = a[left]; //取首元素为基准
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
//优化一 ： 使用替换而不是交换。 减少不必要的交换
/*
template<typename T>
void Quick(T *a, int left, int right)
{
	if (left < right)
	{
		int pivot = a[left];
		int i = left; //从基准开始找起，要包括基准在内
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


//优化二： 使用迭代而不是递归
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
		while (i < j && a[i] < pivot) //上一步把j赋给了i ，如果j是pivot的话，这一步循环会被跳过。
			i++;
		if (i < j)
			a[j] = a[i];
	}
	a[j] = pivot;
	print(a, 8);
	return j; //返回枢纽所在位置，即将数组二分成功。
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
			st.push(mid - 1); //下一次调用排序的left和right
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
			int mid = QuickPartion(a, p, q);  //千万要注意pq的顺序。！
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
