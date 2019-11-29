#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
struct Node
{
	Node(T t) : data(t) { next = this; pre = this; }
	Node()  { next = this;  pre = this; }
	T data;
	Node<T> *next;
	Node<T> *pre;
};

template<typename T>
class DoubleLink
{
public:
	typedef Node<T>* pointer;
	DoubleLink() :count(0), phead(new Node<T>) {}
	~DoubleLink();
public:
	Node<T>* insert(int index, T value);
	Node<T>* insert_front(T t);
	Node<T>* insert_last(T t);

	Node<T>* del(int index);// 删除
	Node<T>* delete_front();
	Node<T>* delete_last();

	bool isEmpty();
	int size();
	
	T get(int dex);
	T get_front();
	T get_last();
	Node<T>* getHead();
private:
	Node<T>* phead;
	int count;
private:
	Node<T>* getNode(int index);

};

template <typename T>
bool DoubleLink<T>::isEmpty()
{
	return count == 0;
}

template<typename T>
int DoubleLink<T>::size()
{
	return count;
}

template<typename T>
Node<T>* DoubleLink<T>::getHead()
{
	return phead;
}

template<typename T>
T DoubleLink<T>::get_front()
{
	return phead->next->data;
}

template<typename T>
T DoubleLink<T>::get_last()
{
	return phead->pre->data;
}
template<typename T>
T DoubleLink<T>::get(int index)
{
	Node<T>* p = getNode(index);
	return p->data;
}




template<typename T>
Node<T>* DoubleLink<T>::getNode(int index)
{
	if (index >= count || index < 0)
		return nullptr;
	Node<T>* current=phead;
	int i = 0;
	while ( i < index)
	{
		current = current->next;
		++i;
//		return current;
	}
	return current;
}

template<typename T>
Node<T>* DoubleLink<T>::insert_front(T value)
{
	Node<T>* newp = new Node<T>(value);
	newp->pre = phead;
	newp->next = phead->next;
	phead->next->pre = newp;
	phead->next = newp;
	count++;
	return newp;
}
template<typename T>
Node<T> * DoubleLink<T>::insert_last(T value)
{
	Node<T>* newp = new Node<T>(value);
	newp->next = phead;
	newp->pre = phead->pre;
	phead->pre->next = newp;
	phead->pre = newp;
	count++;
	return newp;

}

template<typename T>
Node<T>* DoubleLink<T>::insert(int index, T value)
{
	if (index == 0)	return insert_front(value);
	Node<T> *p = getNode(index);
	if (p == nullptr)	return nullptr;
	Node<T> *newp = new Node<T>(value);
	newp->pre = p->pre;  //默认了链表不为空。
	newp->next = p;
	p->pre->next = newp;
	p->pre = p;
	count++;
	return newp;

}

template<typename T>
Node<T>* DoubleLink<T>::delete_front()
{
	if (count == 0)	return nullptr;
	Node<T>* d = phead->next;
	phead->next = phead->next->next;
	phead->next->pre = phead;
	delete d;
	count--;
	return phead->next;
}

template<typename T>
Node<T>* DoubleLink<T>::delete_last()
{
	if (count == 0)return nullptr;
	Node<T> *d = phead->pre;
	phead->pre->pre->next = phead;
	phead->pre = phead->pre->pre;
	delete d;
	count--;
	return phead->pre;

}

template<typename T>
Node<T>* DoubleLink<T>::del(int index)
{
	if (index == 0)
		return delete_front();
	if (index == count - 1) 
		return delete_last();
	if (index >= count || count==0)
		return nullptr;
	Node<T>* d = getNode(index);
	d->pre->next = d->next;
	d->next->pre = d->pre;
	 
	Node<T>* r = d->pre;
	delete d;
	count--;
	return r;
}

template<typename T>
DoubleLink<T>::~DoubleLink()
{
	Node<T>* pre = phead->pre;
	while (phead!=pre)
	{
		Node<T>* p = phead->next;
		delete phead;
		phead = p;
	}
	delete phead;
}

#endif