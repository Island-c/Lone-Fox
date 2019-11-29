#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
class MaxHeap
{
public:
	MaxHeap(int c) :capacity(c),size(0),heap(new T[c]) {}
	bool insert(T val); //插入
	bool remove(T data); //删除
	void print(); //打印堆
	T getTop(); //获取堆顶元素
	bool createMaxHeap(T a[], int size); //根据给定数组创建一个最大堆

private:
	int capacity; //数组大小
	int size; //元素个数
	T * heap;
private:
	void filterUp(int index); //从index所在结点开始向根节点调整堆
	void filterDown(int begin, int end); //从begin开始向end方向调整堆。
};


//自下而上调整 （插入元素时使用）
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
 // 插入操作。
template<typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity)
		return false; //堆满了
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}

//删除操作
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

	heap[index] = heap[size - 1]; //使用最后一个节点代替删除的节点，然后size-- 重新调整
	size--;
	filterDown(index, size);
	return true;

}
// 自上而下调整
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