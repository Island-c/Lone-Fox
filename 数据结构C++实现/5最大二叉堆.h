#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
class MaxHeap
{
public:
	MaxHeap(int c) :capacity(c),size(0),heap(new T[c]) {}
	bool insert(T val); //����
	bool remove(T data); //ɾ��
	void print(); //��ӡ��
	T getTop(); //��ȡ�Ѷ�Ԫ��
	bool createMaxHeap(T a[], int size); //���ݸ������鴴��һ������

private:
	int capacity; //�����С
	int size; //Ԫ�ظ���
	T * heap;
private:
	void filterUp(int index); //��index���ڽ�㿪ʼ����ڵ������
	void filterDown(int begin, int end); //��begin��ʼ��end��������ѡ�
};


//���¶��ϵ��� ������Ԫ��ʱʹ�ã�
template<typename T>
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];
	while (index > 0)
	{
		int indexparent = (index - 1) / 2;
		if (value > heap[indexparent])
		{
			heap[index] = heap[indexparent];
			index = indexparent;
		}
		else break;
	}
	heap[index] = value;

}
 // ���������
template<typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity)
		return false; //������
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}

//ɾ������
template<typename T>
bool MaxHeap<T>::remove(T data)
{
	if (size == 0)
		return false;
	int index;
	for (index = 0; index < size; ++index)
	{
		if (heap[index] == data)
			break;
	}
	if (index == size) return false;

	heap[index] = heap[size - 1]; //ʹ�����һ���ڵ����ɾ���Ľڵ㣬Ȼ��size-- ���µ���
	size--;
	filterDown(index, size);
	return true;

}
// ���϶��µ���
template<typename T>
void MaxHeap<T>::filterDown(int current, int end)
{
	T value = heap[current];
	int child = current * 2 + 1;

	while (child <= end)
	{
		if (child < end && heap[child] < heap[child + 1])
			child++;
		if (heap[child] < value)
			break;
		else
		{
			heap[current] = heap[child];
			current = child;
			child = child * 2 + 1;
		}
	}
	heap[current] = value;
}

template<typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; ++i)
		cout << heap[i] << "   ";
	cout << endl;
}


template<typename T>
T MaxHeap<T>::getTop()
{
	if (size != 0)
		return heap[0];
}


template<typename T>
bool MaxHeap<T>::createMaxHeap(T a[],int size)
{
	if (size > capacity)
		return false;
	for (int i = 0; i < size; ++i)
	{
		insert(a[i]);
	}
	return true;
}









#endif