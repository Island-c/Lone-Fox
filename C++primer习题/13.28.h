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
	TreeNode(const TreeNode &);  //�������캯�� 
	TreeNode& operator= (const TreeNode &);
	~TreeNode();//��������.


private:
	std::string value;
	int *count; //����������
	TreeNode *left;
	TreeNode *right;
};

TreeNode::~TreeNode()
{
	if (--*count == 0) //���������� Ҫ��--count ���ж�
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
TreeNode::TreeNode(const TreeNode & t):value(t.value),count(t.count),left(t.left),right(t.right) //�������캯����
{
	++*count; //���ü���+1
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
