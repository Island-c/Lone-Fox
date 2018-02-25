#ifndef _HEAD_H
#define _HEAD_H

#include <deque>
#include<algorithm>
#include<iostream>
using namespace std;
template<typename T>
struct HuffmanNode
{
	HuffmanNode(T k, HuffmanNode<T>*l = nullptr, HuffmanNode<T>* r = nullptr)
		:key(k), lchild(l), rchild(r) {}
	~HuffmanNode() { destory(); }
	T key;
	HuffmanNode<T>* lchild;
	HuffmanNode<T>* rchild;
};

template<typename T>
class Huffman
{
public:
	Huffman() :root(nullptr) {}
	~Huffman() {}

	void preOrder();
	void inOrder();
	void postOrder();

	void creat(T a[], int size);
	void destory();
	void print();
	
private:
	void preOrder(HuffmanNode<T>* pnode);
	void inOrder(HuffmanNode<T>* pnode);
	void postOrder(HuffmanNode<T>* pnode);
	void print(HuffmanNode<T>* pnode);
	void destory(HuffmanNode<T>* pnode);

private:
	HuffmanNode<T>* root; //哈弗曼树根节点
	deque<HuffmanNode<T>* > forest;
};

template<typename T>
inline void Huffman<T>::preOrder()
{
	preOrder(root);
}

template<typename T>
inline void Huffman<T>::inOrder()
{
	inOrder(root);
}

template<typename T>
inline void Huffman<T>::postOrder()
{
	postOrder(root);
}

template<typename T>
void Huffman<T>::print()
{
	print(root);
}

template<typename T>
inline void Huffman<T>::preOrder(HuffmanNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		cout << pnode->key << endl;
		preOrder(pnode->lchild);
		preOrder(pnode->rchild);
	}
}

template<typename T>
inline void Huffman<T>::inOrder(HuffmanNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		inOrder(pnode->lchild);
		cout << pnode->key << endl;
		inOrder(pnode->rchild);
	}
}

template<typename T>
inline void Huffman<T>::postOrder(HuffmanNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		postOrder(pnode->lchild);
		postOrder(pnode->rchild);
		cout << pnode->key << endl;
	}
}

template<typename T>
void Huffman<T>::print(HuffmanNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		cout << "当前节点: " << pnode->key << ".";
		if (pnode->lchild != nullptr)
			cout << "它的左孩子节点是 ：" << pnode->lchild->key << ". ";
		else cout << "它没有左孩子。";
		if (pnode->rchild != nullptr)
			cout << "它的右孩子节点为：" << pnode->rchild->key << ".";
		else cout << "它没有右孩子.";
		cout << endl;
		print(pnode->lchild);
		print(pnode->rchild);
	}
}

template<typename T>
inline void Huffman<T>::creat(T a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		HuffmanNode<T>* ptr = new HuffmanNode<T>(a[i], nullptr, nullptr);
		forest.push_back(ptr);
	}

	for(int i=0;i<size-1;++i)
	{	
		sort(forest.begin(), forest.end(), [](HuffmanNode<T>* l, HuffmanNode<T>* r) {return l->key < r->key; });
		HuffmanNode<T>* pnode = new HuffmanNode<T>(forest[0]->key + forest[1]->key, forest[0], forest[1]);
		forest.push_back(pnode);
		forest.pop_front();
		forest.pop_front();
		//root = pnode;
	}
//	root = forest.front();
	root = forest.back(); //此时forest内仅有一个节点，就是root。
	forest.clear();
}



template<typename T>
void Huffman<T>::destory()
{
	destory(root);
}
template<typename T>
void Huffman<T>::destory(HuffmanNode<T>* root)
{
	if (root != nullptr)
	{
		destory(root->lchild);
		destory(root->rchld);
		delete root;
	}

}

#endif