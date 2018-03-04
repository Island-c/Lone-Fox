#ifndef _HEAD_H
#define _HEAD_H

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

//Ã°ÅÝ
// ×îºÃ O(n) ×î»µ O£¨n^2£©

template<typename T>
void BubbleSort(T &a, int size)
{
	bool flag = true;

	for (int i = 0; i < size && flag; ++i)
	{
		flag = false;
		for (int j = size - 1; j > i; --j)
		{
			if (a[j] < a[j - 1])
			{
				swap(a, j, j - 1);
				flag = true;
			}
		}
	}
}




#endif
