#include<iostream>

using namespace std;

class node
{
public:
	double data;
	node *next;
};

class Link
{
public:
	Link()
	{
		pfront = NULL;
		pend = NULL;
	}
	double Getx(int n); //找到第n个节点
	void insert(double x); //尾插入
	void reverse(); //链表反转
	void delete_node(int n); //删除节点
	void show();
	~Link();

private:
	node *pfront, *pend;

};
void Link::insert(double x)
{
	node *newp;
	newp = new node;
	if (pfront == NULL&&pend == NULL) //链表为空
	{
		pfront = pend = newp;
		newp->data = x;
		newp->next = NULL;
	}
	else
	{
		pend->next = newp;
		newp->next = NULL;
		newp->data = x;
		pend = newp;
	}
}

double Link::Getx(int n)
{
	node *current = pfront;
	int i = 1;
	while (current != NULL &&i < n)
	{
		if (i == n)
			return current->data;
		++i;
		current = current->next;
	}
	return 0;

}

void Link::delete_node(int n)
{
	node *current = pfront;
	node *d;
	for (int i = 0; i < n-1; ++i)
	{
		current = current->next;
	}
	d = current->next;
	current->next = current->next->next;
	delete d;

}

void Link::show()
{
	node *current = pfront;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;
}

void Link::reverse()
{
	node *current=pfront;
	node *prev = NULL;
	if (pfront==NULL && pfront->next == NULL)
		return;
	node *n = pfront->next;
	while (n != NULL)  //易错！
	{
		current->next = prev;
		prev = current;
		current = n;
		n = n->next;
	}
	current->next = prev; //易错！！
	pend = pfront;
	pfront = current;

}

Link::~Link()
{
	node *current =pfront;
	while (pfront->next != NULL)
	{
		current = pfront->next;
		delete(pfront);
		pfront = current;
	}
}

int main(int argc, char **argv)
{
	Link my_list;
	double num;
	while (cin >> num)
		my_list.insert(num);
	my_list.show();
	my_list.reverse();
	my_list.show();
	my_list.delete_node(2);
	my_list.show();
	system("pause");
	return 0;
}