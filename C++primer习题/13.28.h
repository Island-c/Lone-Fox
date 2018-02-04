#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<utility>
#include<map>
#include<string>
using namespace std;


class TreeNode
{
public:
	TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr)
	{
	}
	TreeNode(const TreeNode &);  //拷贝构造函数 
	TreeNode& operator= (const TreeNode &);
	~TreeNode();//析构函数.


private:
	std::string value;
	int *count; //拷贝计数。
	TreeNode *left;
	TreeNode *right;
};

TreeNode::~TreeNode()
{
	if (--*count == 0) //析构函数， 要先--count 再判断
	{
		if (left)
			delete left;
		if (right)
			delete right;
		left = nullptr;
		right = nullptr;
		delete count;
		count = nullptr;
	}
}

TreeNode& TreeNode::operator= (const TreeNode& t)
{
	++*t.count;

	auto c = t.count;
	auto l = t.left;
	auto r = t.right;
	if (--*count == 0) {
		delete count;
		if(left) delete left;
		if(right) delete right;
	}
	value = t.value;
	count = c;
	left = l;
	right = r;
	return *this;
}
TreeNode::TreeNode(const TreeNode & t):value(t.value),count(t.count),left(t.left),right(t.right) //拷贝构造函数。
{
	++*count; //引用计数+1
}



class BinStrTree
{
public:
	BinStrTree() : root(new TreeNode()){}
	BinStrTree(const BinStrTree&);
	BinStrTree& operator= (const BinStrTree&);
private:
	TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree& bst)
{
	TreeNode* new_root = new TreeNode(*bst.root);
	delete root;
	root = new_root;
	return *this;
}

BinStrTree::BinStrTree(const BinStrTree& t): root(t.root)
{
}


#endif
