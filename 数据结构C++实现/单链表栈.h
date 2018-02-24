#ifndef _HEAD_H
#define _HEAD_H
#include<string>

template<typename T>
class Node
{
public:
	Node(T t) :data(t), next(nullptr) {}
	Node() : next(nullptr) {}
public:
	T data;
	Node<T> *next;
};

template<typename T>
class LinkStack
{
public:
	LinkStack() :phead(new Node<T>), count(0) {}
	~LinkStack();
public:
	bool isEmpty();
	int size();
	void push(T t);
	T pop();
	T top();

private:
	Node<T> *phead; //栈首节点。
	int count;
};

template<typename T>
bool LinkStack<T>::isEmpty()
{
	return count==0;
}

template<typename T>
int LinkStack<T>::size()
{
	return count;
}

template<typename T>
void LinkStack<T>::push(T t)
{
	Node<T> *newp = new Node<T>(t);
	newp->next = phead->next; //newp到栈顶
	phead->next = newp;
	count++;
}

template<typename T>
T LinkStack<T>::pop()
{
	Node<T> *d=phead->next;
	phead->next = phead->next->next;
	T value = d->data;
	delete d;
	count--;
	return value;
}

template<typename T>
T LinkStack<T>::top()
{
	if(count!=0)
		return phead->next->data;
}

template<typename T>
LinkStack<T>::~LinkStack()
{
	Node<T> *d = phead->next;
	Node<T> *curr;
	while (d != nullptr)
	{
		curr = d->next;
		delete d;
		d = curr;
	}
	delete phead;
}

#endif