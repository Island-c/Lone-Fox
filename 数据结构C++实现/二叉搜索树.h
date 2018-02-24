#ifndef _HEAD_H
#define _HEAD_H

template<typename T>
struct BSNode //�������Ľڵ�
{
	BSNode(T t) :value(t), lchild(nullptr), rchild(nullptr) {}
	BSNode() = default;

	T value;
	BSNode<T>* lchild;
	BSNode<T>* rchild;
	BSNode<T>* parent;

};

template<typename T>
class BSTree //�����������
{
public:
	BSTree() :root(nullptr) {}
	~BSTree() { destory(root); }

	void preOrder();  //ǰ�����
	void inOrder();  //�������
	void postOrder(); //�������
//	void layerOrder(); //��α���

	BSNode<T>* search_recursion(T key); //�ݹ����
	BSNode<T>* search_Iterator(T key); //��������

	T search_minimum(); //������СԪ��
	T search_maximum(); //�������Ԫ��

	BSNode<T>* successor(BSNode<T>* x); //���Һ�̽ڵ�
	BSNode<T>* preducessor(BSNode<T>* x); //����ǰ���ڵ�

	void insert(T key); //����ָ��ֵ�ڵ�
	void remove(T key); //ɾ��ָ��ֵ�ڵ�
	void destory(); //���ٶ�����
	void print(); //��ӡ������

private:
	BSNode<T>* root; //���ڵ�
private:
	BSNode<T>* search(BSNode<T>* &p, T key);  //�����ǵݹ�ʹ�õĽӿ�
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
//		if (key > pnode->value) //error! �����һ��if�ɹ�ִ�У�pnode�ᷢ���ı䡣
			pnode = pnode->rchild;
		else 
			break;  //������ͬkeyʱ����������...
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

//ǰ�����
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

//�������
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

//�������

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


//Ѱ��ǰ���ڵ�

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

//Ѱ�Һ�̽ڵ�

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

//ɾ��ָ���ڵ�
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
			BSNode<T>* pdel = nullptr; //Ҫɾ���Ľڵ�

			if (pnode->lchild == nullptr || pnode->rchild == nullptr) //����������һ��Ϊ��
			{
				pdel = pnode;
			}
			else
				pdel = preducessor(pnode); //������������Ϊ�գ�������ǰ���ڵ�

			//pdel�ڵ�ֻ��һ�����ӻ���û�к��ӣ����溢��ָ��
			BSNode<T>* pchild = nullptr;
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else
				pchild = pdel->rchild;
			//���pdel�ڵ�ĺ��Ӳ�Ϊ�գ������ĸ��ڵ�ָ��pdel�ĸ��ڵ�
			if (pchild != nullptr)
				pchild->parent = pdel->parent;
			//���pdel�Ǹ��ڵ㣬Ҫ�ǵø�root��ֵ
			if (pdel->parent == nullptr)
				root = pchild;
			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
				pdel->parent->rchild = pchild;

			//��pdel��ֵ��pnode
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


//����Ԫ�� �ǵݹ�
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
	return nullptr; //û����Ӧ��ֵ
}

//����Ԫ�� �ݹ� ,���ü���if����while
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
//	cout << pnode->valude << endl; //�������·��
	if (key > pnode->value)
		return search(pnode->rchild, key);
	else return search(pnode->lchild, key);
}

//Ѱ����СԪ��

template<typename T>
T BSTree<T>::search_minimum()
{
	return search_minimum(root);
}
template<typename T>
T BSTree<T>::search_minimum(BSNode<T>* p) //�ǵݹ�
{
	while (p->lchild != nullptr)
	{
		p = p->lchild;
	}
	return p->value;
}

//Ѱ�����Ԫ��
template <typename T>
T BSTree<T>::search_maximum()
{
	return search_maximum(root);
}
template <typename T>
T BSTree<T>::search_maximum(BSNode<T> *p) //�ݹ�
{
	if (p->rchild != nullptr)
		return search_maximum(p->rchild);
	return p->value;
}

//���ٶ�����
//ʹ�ú�������� ɾ���ڵ�ʱ�����ƻ������Ľṹ

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