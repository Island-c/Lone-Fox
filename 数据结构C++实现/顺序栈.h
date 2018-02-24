#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int s = 10) :array(new T[s]), count(0), capacity(10) {} //默认容量为10 
	~ArrayStack()
	{
		delete[]array;
	}
public:
	T top(); //获取栈顶元素
	void push(T t); //入栈
	T pop(); //出栈
	bool isEmpty(); //判空
	int size(); //求栈的大小。

private:
	int count; //元素数量
	int capacity; //总的空间大小
	T *array;

};

template<typename T>
bool ArrayStack<T>::isEmpty()
{
	return count == 0;
}

template<typename T>
int ArrayStack<T>::size()
{
	return count;
}

template<typename T>
void ArrayStack<T>::push(T t)
{
	if (count != capacity)
	{
		array[count++] = t; //count从1开始计算，而数组从0开始。
	}
}

template<typename T>
T ArrayStack<T>::pop()
{
	if (count != 0) //先判空
	{
		return array[--count];
	}

}
template<typename T>
T ArrayStack<T>::top()
{
	if (count != 0)
		return array[count-1];
}


#endif