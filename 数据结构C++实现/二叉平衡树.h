#ifndef _HEAD_H
#define _HEAD_H

#include<algorithm>
template<typename T>
struct AVLTreeNode
{
	AVLTreeNode(T value, AVLTreeNode<T> *l, AVLTreeNode<T> *r)
		:key(value), lchild(l), rchild(r),height(0) {}
	AVLTreeNode() :lchild(nullptr), rchild(nullptr),height(0) {}
	T key;  //节点的值
	int height;	//节点的高度
	AVLTreeNode<T>* lchild;
	AVLTreeNode<T>* rchild;
};

template<typename T>
class AVLTree
{
public:
	AVLTree() :root(nullptr) {}
	~AVLTree() { destory(); }

	void preOrder(); //前序遍历
	void inOrder(); //中序遍历
	void postOrder(); //后序遍历

	//void print();
 	void destory(); //销毁AVL树

	void insert(T key);
	void remove(T key);

	AVLTreeNode<T> *search_recurse(T key); //递归查找指定值
	AVLTreeNode<T> *search_iterator(T key); //迭代查找指定值
	T minimum(); //返回最大值
	T maximum(); //返回最小值

	int height();

private:
	AVLTreeNode<T>* root;

private:
	void preOrder(AVLTreeNode<T> *pnode)const;
	void inOrder(AVLTreeNode<T>* pnode) const;
	void postOrder(AVLTreeNode<T>* pnode) const;

	//void print(AVLTreeNode<T>* pnode, T key, int direction) const;
	void destory(AVLTreeNode<T>* &pnode); //销毁，必须使用引用。

	int height(AVLTreeNode<T>* pnode);

	AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key);
	AVLTreeNode<T>* remove(AVLTreeNode<T>* &pnode, T key); //删除节点pdel，并返回被删除的节点

	AVLTreeNode<T>* minimum(AVLTreeNode<T>* pnode)const;
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* pnode)const;

	AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
	AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key)const;

	AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode);//单旋，左旋操作
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode); //单旋：右旋操作
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);//双旋，先左再右
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);//双旋：先右再左。

};


//返回一棵树的高度
template<typename T>
int AVLTree<T>::height(AVLTreeNode<T>* pnode)
{
	if (pnode != nullptr)
		return pnode->height;
	return 0; //空树的高度为0
}
template<typename T>
int AVLTree<T>::height()
{
	return height(root);
}

//左旋转操作 ： 右子树插入右孩子
//pnode为最小失衡子树的根节点
template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftRotation(AVLTreeNode<T>* proot)
{
	AVLTreeNode<T>* prchild = proot->rchild;
	//将proot右子树的左子树挂在proot的右子树上。
	//再将proot右子树的左子树置为proot。
	proot->rchild = prchild->lchild;
	prchild->lchild = proot;

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;
	prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1;
	return prchild; 
}

//右旋转操作 ： 左子树插入左孩子
template<typename T>
AVLTreeNode<T> *AVLTree<T>::rightRotation(AVLTreeNode<T>* proot)
{
	AVLTreeNode<T>* plchild = proot->lchild;
	proot->lchild = plchild->rchild;
	plchild->rchild = proot;


	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;
	plchild->height = max(height(plchild->lchild), height(plchild->lchild)) + 1;
	return plchild;
}

//先右旋再左旋: 右子树上插入左孩子的情况
template<typename T>
AVLTreeNode<T> * AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* proot)
{
	proot->rchild = rightRotation(proot->rchild);
	return leftRotation(proot);

}

//先左旋再右旋 ： 左子树插入右孩子
template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* proot)
{
	proot->lchild = leftRotation(proot->lchild);
	return rightRotation(proot);
}

//插入
template<typename T>
void AVLTree<T>::insert(T key)
{
	insert(root, key);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &pnode, T key)
{
	if (pnode == nullptr) //寻找到合适位置。
	{
		pnode = new AVLTreeNode<T>(key, nullptr, nullptr);
	}
	else if (key > pnode->key)
	{
		pnode->rchild = insert(pnode-> rchild, key);
		if (height(pnode->rchild) - height(pnode->lchild) == 2) //失衡
		{
			if (key > pnode->rchild->key) // 右插右，左旋
				pnode = leftRotation(pnode);
			else if (key < pnode->rchild->key)
				pnode = rightLeftRotation(pnode);
		}
	}
	else if (key < pnode->key)
	{
		pnode->lchild = insert(pnode->lchild, key);
		if (height(pnode->lchild) - height(pnode->rchild) == 2)
		{
			if (key < pnode->lchild->key)
				pnode = rightRotation(pnode);
			else if (key > pnode->lchild->key)
				pnode = leftRightRotation(pnode);
		}
	}
	//重新计算高度
	pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1; //如果左右孩子都为空，则节点高度为1
	return pnode;


}

//删除元素
template<typename T>
void AVLTree<T>::remove(T key)
{
	remove(root, key);
}
template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &pnode, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->key == key) // 找到了
		{
			//如果左右子树都不为空
			if (pnode->lchild != nullptr && pnode->rchild != nullptr)
			{
				//如果左子树更高，就在左子树寻找替换
				if (height(pnode->lchild) > height(pnode->rchild))
				{
					//寻找左子树的最大节点，即pnode的前驱。
					AVLTreeNode<T>* ppre = maximum(pnode->lchild);
					pnode->key = ppre->key;
					pnode->lchild = remove(pnode->lchild, ppre->key);//递归删除左子树的最大节点。
				}
				else //否则在右子树寻找替换
				{
					//寻找右子树的最小节点,pnode的后继
					AVLTreeNode<T>* psuc = minimum(pnode->rchild); 
					pnode->key = psuc->key;
					pnode->rchild = remove(pnode->rchild, psuc->key);//递归删除,总会递归到一个左右子树都为空的，就可以直接删除了。

				}
			}
			else
			{
				//终于可以删除了
				AVLTreeNode<T> * ptemp = pnode;
				if (pnode->lchild != nullptr)
					pnode = pnode->lchild;
				else if (pnode->rchild != nullptr)
					pnode = pnode->rchild;
				else pnode = nullptr;
				delete ptemp;
			//	return nullptr;
				return pnode;
			}
		}
		else if (pnode->key < key)
		{
			pnode->rchild = remove(pnode->rchild, key);
			//删掉右子树的节点，使左边高右边低。 需要右旋或者先左旋后右旋
			if (height(pnode->lchild) - height(pnode->lchild) == 2)
			{
				if (height(pnode->lchild->rchild) > height(pnode->lchild->lchild))
					pnode = leftRightRotation(pnode);
				else
					pnode = rightRotation(pnode);
			}
		}
		else if (pnode->key > key)
		{
			pnode->lchild = remove(pnode->lchild, key);
			//删掉左子树的节点，右边高左边低。要左旋或者先右旋后左旋
			if (height(pnode->rchild) - height(pnode->lchild) == 2)
			{
				if (height(pnode->rchild->lchild) > height(pnode->rchild->rchild))
				{
					pnode = rightLeftRotation(pnode);
				}
				else
					pnode = leftRotation(pnode);


			}

		}

		return pnode;

	}
	return nullptr;


}


//递归查找指定元素
template<typename T>
AVLTreeNode<T>* AVLTree<T>::search_recurse(T key)
{
	return search_recurse(root, key);
}
template<typename T>
AVLTreeNode<T>* AVLTree<T>::search_recurse(AVLTreeNode<T>* pnode, T key) const
{
	if (pnode != nullptr)
	{
		if (key == pnode->key)
			return pnode;
		else if (key < pnode->key)
			return search_recurse(pnode->lchild, key);
		else
			return search_recurse(pnode->rchild, key);
	}
	return nullptr;

}

//非递归查找指定元素
template<typename T>
AVLTreeNode<T>* AVLTree<T>::search_iterator(T key)
{
	return search_iterator(root, key);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::search_iterator(AVLTreeNode<T>* pnode, T key)const 
{
	while (pnode != nullptr)
	{
		if (key == pnode->key)
			return pnode;
		else if (key < pnode->key)
			pnode = pnode->lchild;
		else if (key > pnode->key)
			pnode = pnode->rchild;

	}
	return nullptr;
}

//遍历二叉树
//先序遍历
template<typename T>
void AVLTree<T>::preOrder()
{
	preOrder(root);
}
template<typename T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		cout << pnode->key << endl;
		preOrder(pnode->lchild);
		preOrder(pnode->rchild);
	}
}

//中序遍历
template<typename T>
void AVLTree<T>::inOrder()
{
	inOrder(root);
}

template<typename T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		inOrder(pnode->lchild);
		cout << pnode->key << endl;
		inOrder(pnode->rchild);
	}
}
//后序遍历
template<typename T>
void AVLTree<T>::postOrder()
{
	postOrder(root);
}
template<typename T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* pnode)const
{
	if (pnode != nullptr)
	{
		postOrder(pnode->lchild);
		postOrder(pnode->rchild);
		cout << pnode->key << endl;
	}
}

//树的销毁
template<typename T>
void AVLTree<T>::destory()
{
	destory(root);
}
template<typename T>
void AVLTree<T>::destory(AVLTreeNode<T>* &pnode)
{
	if (pnode != nullptr)
	{
		destory(pnode->lchild); //后序遍历销毁树。
		destory(pnode->rchild);
		delete pnode;
		pnode = nullptr; //避免指针乱指。
	}	
}

//求最大值和最小值。
template<typename T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		while (pnode->rchild != nullptr)
			pnode = pnode->rchild;
		return pnode;
	 }
	return nullptr;
}
template<typename T>
T AVLTree<T>::maximum()
{
	AVLTreeNode<T>* presult = maximum(root);
	if (presult != nullptr)
		return presult->key;
}

template<typename T>
T AVLTree<T>::minimum()
{
	AVLTreeNode<T>* presult = minimun(root);
	if (presult != nullptr)
		return presult->key;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* pnode) const
{
	if (pnode != nullptr)
	{
		while (pnode->lchild != nullptr)
			pnode = pnode->lchild;
		return pnode;

	}
}






#endif