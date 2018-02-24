#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
class node
{
public:
	T data;
	node* next;
};

template<typename T>
class Linklist
{
public:
	Linklist() :pfront(new node<T>) { pfront->next = NULL; }
	int InsertLinklist(T d);  //首插，带头结点
	node<T>* GetLinklist(int pos);
	int DelLinklist(int pos);
	void PrintLinklist();
	~Linklist();

private:
	node<T> *pfront;
	//node<T> *pend;
};

template<typename T>
int Linklist<T>::InsertLinklist(T d)
{
	node<T> *newp = new node<T>;
	newp->data = d;
	newp->next = pfront->next;
	pfront->next = newp;
	return 1;
}



template<typename T>
node<T> *Linklist<T>::GetLinklist(int pos)
{
	node<T> *current=pfront;
	int i = 0;
	while (i < pos &&current != NULL)
	{
		current = current->next;
		++i;
	}
	return i == pos ? current : NULL;
}

template<typename T>
int Linklist<T>::DelLinklist(int pos)
{
	node<T> *current=pfront;
	node<T> *d;
	int i = 0;
	while (i < pos-1 && current->next != NULL)
	{
		current = current->next;
		++i;
	}
	if (i != pos-1)	return -1;
	d = current->next;
	current->next = current->next->next;
	delete d;
	return 1;
}

template<typename T>
void Linklist<T>::PrintLinklist()
{
	node<T> *current = pfront->next;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;
}

template<typename T>
 Linklist<T>::~Linklist()
{
	node<T> *current=pfront->next ;
	node<T> *p;
	while (current != NULL)
	{
		p = current->next;
		delete current;
		current = p;
	}
	delete pfront;
}



#endif