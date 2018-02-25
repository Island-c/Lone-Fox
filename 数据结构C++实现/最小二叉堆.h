#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
class MinHeap
{
public:
	MinHeap(int c) :capacity(c),size(0),heap(new T[c]) {}
	~MinHeap() { delete[]heap; }
	bool insert(T val); //����
	bool remove(T data); //ɾ��
	void print(); //��ӡ��
	T getTop(); //��ȡ�Ѷ�Ԫ��
	bool createMaxHeap(T a[], int size); //���ݸ������鴴��һ����С��

private:
	int capacity; //�����С
	int size; //Ԫ�ظ���
	T * heap;
private:
	void filterUp(int index); //��index���ڽ�㿪ʼ����ڵ������
	void filterDown(int begin, int end); //��begin��ʼ��end��������ѡ�
};

template<typename T>
bool MinHeap<T>::insert(T val)
{
	if (size == capacity)
		return false; //��

	heap[size] = val;
	size++;
	filterUp(size-1);
	return true;
}
 //���ϵ���
template<typename T>
void MinHeap<T>::filterUp(int index)
{
	T value = heap[index];
	int parent = (index-1) / 2; 
	while (parent >= 0)
	{
		if (heap[parent] <= value)
			break;
		else {
			heap[index] = heap[parent ];
			index = parent;
			parent = (parent-1) / 2;
		}
	}
	heap[index] = value;

}

template<typename T>
bool MinHeap<T>::remove(T data)
{
	if (size == 0) return false;

	int index = 0;
	for (index; index<size; ++index)
	{
		if (heap[index] == data) break;
	}
	if (index == size) return false;

	heap[index] = heap[size - 1];
	size--;
	filterDown(index, size - 1);
	return true;
}

template<typename T>
void MinHeap<T>::filterDown(int begin, int end)
{
	if (size == 0) return;
	T value = heap[begin];
	int child = begin * 2 + 1;
	while (child <= end)
	{
		if (child<end && heap[child]>heap[child + 1])
			child++;
		if (heap[child] > value)
			break;
		else {
			heap[begin] = heap[child];
			begin = child;
			child = child * 2 + 1;
		}
	}
	heap[begin] = value;
}

template<typename T>
T MinHeap<T>::getTop()
{
	if (size != 0)
		return heap[0];
}
template<typename T>
void MinHeap<T>::print()
{
	if (size != 0)
	{
		for (int index = 0; index < size; ++index)
			cout << heap[index] << "   ";
		cout << endl;
	}
}

template<typename T>
bool MinHeap<T>::createMaxHeap(T a[], int s)
{
	if (capacity >= s)
	{
		for (int i = 0; i < s; ++i)
			insert(a[i]);
		return true;
	}
	else return false;
}

#endif