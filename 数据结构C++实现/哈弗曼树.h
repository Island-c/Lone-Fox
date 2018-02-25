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
void Huffman<T>::creat(T a[], int size)
{
	for (int i = 0; i < size ; ++i)
	{
		HuffmanNode<T>* ptr = new HuffmanNode<T>(a[i], nullptr, nullptr);
		forest.push_back(ptr);
	}
	for (int i = 0; i < size - 1; ++i)
	{
		//lambda确定排序方式 按照key排
		sort(forest.begin(), forest.end(), [](HuffmanNode<T>* a, HuffmanNode<T>* b) {return a->key < b->key; });
		//选其中最小的两个节点构建新树，这两个节点分别是左右子树。
		HuffmanNode<T>* node = new HuffmanNode<T>(forest[0]->key + forest[1]->key, forest[0], forest[1]);
		forest.push_back(node);
		forest.pop_front();
		forest.pop_front();
	}
	root = forest.front();
	forest.clear(); //排完了 清空森林。

}

template<typename T>
void Huffman<T>::print()
{
	print(root);
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
void Huffman<T>::destory()
{
	destory(root);
}
template<typename T>
void Huffman<T>::destory(HuffmanNode<T>* root)
{
	if (root != nullptr)
	{
		if(root->lchild!=nullptr)
			destory(root->lchild);
		if (root->rchild != nullptr)
			destory(root->rchld);
		delete root;
	}

}

#endif