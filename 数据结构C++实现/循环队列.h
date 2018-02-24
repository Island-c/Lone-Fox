#ifndef _HEAD_H
#define _HEAD_H

template <typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10) : queue(new T[c]), capacity(c), begin(0), end(0) {}
	~LoopQueue() { delete[]queue; }
public:
	bool isEmpty();
	int size();
	bool push(T t);
	bool pop();
	T front(); //队首元素。
private:
	int capacity; //可用空间
	int begin;
	int end;
	T *queue;

};

template<typename T>
bool LoopQueue<T>::isEmpty()
{
	if (begin == end) return true;
	else return false;
}

template<typename T>
int LoopQueue<T>::size()
{
	return (end - begin + capacity) % capacity;
}
template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin)
		return false;
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
}

template<typename T>
bool LoopQueue<T>::pop()
{
	if (begin==end) return false;
	begin = (begin + 1) % capacity;
	return true;
}

template<typename T>
T LoopQueue<T>::front()
{
	if (begin==end) return false;
	return queue[begin];
}

#endif