#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int s = 10) :array(new T[s]), count(0), capacity(10) {} //Ĭ������Ϊ10 
	~ArrayStack()
	{
		delete[]array;
	}
public:
	T top(); //��ȡջ��Ԫ��
	void push(T t); //��ջ
	T pop(); //��ջ
	bool isEmpty(); //�п�
	int size(); //��ջ�Ĵ�С��

private:
	int count; //Ԫ������
	int capacity; //�ܵĿռ��С
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
		array[count++] = t; //count��1��ʼ���㣬�������0��ʼ��
	}
}

template<typename T>
T ArrayStack<T>::pop()
{
	if (count != 0) //���п�
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