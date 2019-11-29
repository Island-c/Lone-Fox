#ifndef _HEAD_H
#define _HEAD_H
template <typename T>
struct Node
{
//默认是public
	Node(T t) :data(t), next(nullptr) {}
	Node() :  next(nullptr) {}
	T data;
	Node* next;
};

template<typename T>
class LinkQueue
{
public:
	LinkQueue() :count(0), phead(new Node<T>), pend(phead) {}
	~LinkQueue();

	bool isEmpty();
	int size();
	bool pop();
	void push(T t);
	T front();

private:
	Node<T> *phead;
	Node<T> *pend;
	int count;
};

template<typename T>
bool LinkQueue<T>::isEmpty()
{
	return count == 0;
}

template<typename T>
int LinkQueue<T>::size()
{
	return count;
}
template<typename T >
bool LinkQueue<T>::pop() //队首出
{
	if (count == 0)
		return false;
	Node<T> *newp = phead->next->next;
	delete phead->next;
	phead->next = newp;
	count--;
	return true;
}

template<typename T>
void LinkQueue<T>::push(T t) //队尾进
{
	Node<T> *newp = new Node<T>(t);
	pend->next = newp;
	pend = newp;
	count++;
}

template<typename T>
T LinkQueue<T>::front()
{
	return phead->next->data;
}

template<typename T>
LinkQueue<T>:: ~LinkQueue()
{
	while (phead != nullptr)
	{
		Node<T> *pnode = phead;
		phead = phead->next;
		delete pnode;
	}
}

#endif