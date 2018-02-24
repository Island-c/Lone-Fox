#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
struct BSNode //二叉树的节点
{
	BSNode(T t) :value(t), lchild(nullptr), rchild(nullptr) {}
	BSNode() = default;

	T value;
	BSNode<T>* lchild;
	BSNode<T>* rchild;
	BSNode<T>* parent;

};

template<typename T>
class BSTree //二叉查找树。
{
public:
	BSTree() :root(nullptr) {}
	~BSTree() { destory(root); }

	void preOrder();  //前序遍历
	void inOrder();  //中序遍历
	void postOrder(); //后序遍历
//	void layerOrder(); //层次遍历

	BSNode<T>* search_recursion(T key); //递归查找
	BSNode<T>* search_Iterator(T key); //迭代查找

	T search_minimum(); //查找最小元素
	T search_maximum(); //查找最大元素

	BSNode<T>* successor(BSNode<T>* x); //查找后继节点
	BSNode<T>* preducessor(BSNode<T>* x); //查找前驱节点

	void insert(T key); //插入指定值节点
	void remove(T key); //删除指定值节点
	void destory(); //销毁二叉树
	void print(); //打印二叉树

private:
	BSNode<T>* root; //根节点
private:
	BSNode<T>* search(BSNode<T>* &p, T key);  //以下是递归使用的接口
	void remove(BSNode<T>* p, T key); 
	void preOrder(BSNode<T>* p);
	void inOrder(BSNode<T> *p);
	void postOrder(BSNode<T>* p);
	T search_minimum(BSNode<T> *p);
	T search_maximum(BSNode<T>* p);
	void destory(BSNode<T> * &p);
};


template<typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T>* pparent = nullptr;
	BSNode<T>* pnode = root;
	while (pnode != nullptr)
	{
		pparent = pnode;
		if (key < pnode->value)
			pnode = pnode->lchild;
		else if (key > pnode->value)
//		if (key > pnode->value) //error! 如果上一个if成功执行，pnode会发生改变。
			pnode = pnode->rchild;
		else 
			break;  //遇到相同key时不继续查找...
	}
	pnode = new BSNode<T>(key);
	if (pparent == nullptr)
	{
		root = pnode;
	}
	else
	{
		if (key > pparent->value)
		{
			pparent->rchild = pnode;
		}
		else
		{
			pparent->lchild = pnode;
		}
	}
	pnode->parent = pparent;

}

//前序遍历
template<typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
}

template<typename T>
void BSTree<T>::preOrder(BSNode<T> *p)
{
	if (p != nullptr)
	{
		cout << p->value << endl;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

//中序遍历
template<typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
}
template<typename T>
void BSTree<T>::inOrder(BSNode<T> *p)
{
	if (p != nullptr)
	{
		inOrder(p->lchild);
		cout << p->value << endl;
		inOrder(p->rchild);
	}
}

//后序遍历

template<typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
}

template<typename T>
void BSTree<T>::postOrder(BSNode<T> *p)
{
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << endl;
	}
}


//寻找前驱节点

template<typename T>
BSNode<T>* BSTree<T>::preducessor(BSNode<T>* pnode)
{

	if (pnode->lchild != nullptr)
	{
		pnode = pnode->lchild;
		while (pnode->rchild != nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode;
	}
	BSNode<T>* pparent = pnode->parent;
	while (pparent != nullptr && pparent->rchild != pnode)
	{
		pnode = pparent;
		pparent = pparent->parent;
	}
	return pparent;

}

//寻找后继节点

template<typename T>
BSNode<T> * BSTree<T>::successor(BSNode<T>* pnode)
{
	if (pnode->rchild != nullptr)
	{
		pnode = pnode->rchild;
		while (pnode->lchild != nullptr)
		{
			pnode = pnode->lchild;
		}
		return pnode;
	}
	BSNode<T>* pparent = pnode->parent;
	while (pparent != nullpter && pparent->rchild == pnode)
	{
		pnode = pparent;
		pparent = pparent->parent;
	}
	return pparent;
}

//删除指定节点
template<typename T>
void BSTree<T>::remove(T key)
{
	remove(root, key);
}

template<typename T>
void BSTree<T>::remove(BSNode<T>* pnode, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>* pdel = nullptr; //要删除的节点

			if (pnode->lchild == nullptr || pnode->rchild == nullptr) //左右子树有一个为空
			{
				pdel = pnode;
			}
			else
				pdel = preducessor(pnode); //左右子树都不为空，则找其前驱节点

			//pdel节点只有一个孩子或者没有孩子，保存孩子指针
			BSNode<T>* pchild = nullptr;
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else
				pchild = pdel->rchild;
			//如果pdel节点的孩子不为空，让他的父节点指向pdel的父节点
			if (pchild != nullptr)
				pchild->parent = pdel->parent;
			//如果pdel是根节点，要记得改root的值
			if (pdel->parent == nullptr)
				root = pchild;
			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
				pdel->parent->rchild = pchild;

			//把pdel的值给pnode
			if (pnode->value != pdel->value)
				pnode->value = pdel->value;

			delete pdel;
		}
		else if (key > pnode->value)
			remove(pnode->rchild, key);
		else
			remove(pnode->lchild, key);
	}
}


//查找元素 非递归
template<typename T>
BSNode<T>* BSTree<T>::search_Iterator(T key)
{
	BSNode<T>* pnode = root;
	while (pnode != nullptr)
	{
		if (key == pnode->value)
			return pnode;
		if (key > pnode->valude)
			pnode = pnode->rchild;
		else
			pnode = pnode->lchild;
	}
	return nullptr; //没有相应的值
}

//查找元素 递归 ,多用几个if代替while
template<typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
	return search(root, key);
}

template<typename T>
BSNode<T> * BSTree<T>::search(BSNode<T>* &pnode, T key)
{
	if (pnode == nullptr)
		return nullptr;
	if (pnode->valude == key)
		return pnode;
//	cout << pnode->valude << endl; //输出查找路径
	if (key > pnode->value)
		return search(pnode->rchild, key);
	else return search(pnode->lchild, key);
}

//寻找最小元素

template<typename T>
T BSTree<T>::search_minimum()
{
	return search_minimum(root);
}
template<typename T>
T BSTree<T>::search_minimum(BSNode<T>* p) //非递归
{
	while (p->lchild != nullptr)
	{
		p = p->lchild;
	}
	return p->value;
}

//寻找最大元素
template <typename T>
T BSTree<T>::search_maximum()
{
	return search_maximum(root);
}
template <typename T>
T BSTree<T>::search_maximum(BSNode<T> *p) //递归
{
	if (p->rchild != nullptr)
		return search_maximum(p->rchild);
	return p->value;
}

//销毁二叉树
//使用后序遍历。 删除节点时不会破坏其他的结构

template<typename T>
void BSTree<T>::destory()
{
	destory(root);
}
template<typename T>
void BSTree<T>::destory(BSNode<T>*  &p)
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr)
			destory(p->lchild);
		if (p->rchild != nullptr)
			destory(p->rchild);
		delete p;
		p = nullptr;
	}
}


#endif