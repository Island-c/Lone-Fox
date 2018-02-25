#ifndef _HEAD_H
#define _HEAD_H

#include<algorithm>
template<typename T>
struct AVLTreeNode
{
	AVLTreeNode(T value, AVLTreeNode<T> *l, AVLTreeNode<T> *r)
		:key(value), lchild(l), rchild(r),height(0) {}
	AVLTreeNode() :lchild(nullptr), rchild(nullptr),height(0) {}
	T key;  //�ڵ��ֵ
	int height;	//�ڵ�ĸ߶�
	AVLTreeNode<T>* lchild;
	AVLTreeNode<T>* rchild;
};

template<typename T>
class AVLTree
{
public:
	AVLTree() :root(nullptr) {}
	~AVLTree() { destory(); }

	void preOrder(); //ǰ�����
	void inOrder(); //�������
	void postOrder(); //�������

	//void print();
 	void destory(); //����AVL��

	void insert(T key);
	void remove(T key);

	AVLTreeNode<T> *search_recurse(T key); //�ݹ����ָ��ֵ
	AVLTreeNode<T> *search_iterator(T key); //��������ָ��ֵ
	T minimum(); //�������ֵ
	T maximum(); //������Сֵ

	int height();

private:
	AVLTreeNode<T>* root;

private:
	void preOrder(AVLTreeNode<T> *pnode)const;
	void inOrder(AVLTreeNode<T>* pnode) const;
	void postOrder(AVLTreeNode<T>* pnode) const;

	//void print(AVLTreeNode<T>* pnode, T key, int direction) const;
	void destory(AVLTreeNode<T>* &pnode); //���٣�����ʹ�����á�

	int height(AVLTreeNode<T>* pnode);

	AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key);
	AVLTreeNode<T>* remove(AVLTreeNode<T>* &pnode, T key); //ɾ���ڵ�pdel�������ر�ɾ���Ľڵ�

	AVLTreeNode<T>* minimum(AVLTreeNode<T>* pnode)const;
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* pnode)const;

	AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
	AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key)const;

	AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode);//��������������
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode); //��������������
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);//˫������������
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);//˫������������

};


//����һ�����ĸ߶�
template<typename T>
int AVLTree<T>::height(AVLTreeNode<T>* pnode)
{
	if (pnode != nullptr)
		return pnode->height;
	return 0; //�����ĸ߶�Ϊ0
}
template<typename T>
int AVLTree<T>::height()
{
	return height(root);
}

//����ת���� �� �����������Һ���
//pnodeΪ��Сʧ�������ĸ��ڵ�
template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftRotation(AVLTreeNode<T>* proot)
{
	AVLTreeNode<T>* prchild = proot->rchild;
	//��proot������������������proot���������ϡ�
	//�ٽ�proot����������������Ϊproot��
	proot->rchild = prchild->lchild;
	prchild->lchild = proot;

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;
	prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1;
	return prchild; 
}

//����ת���� �� ��������������
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

//������������: �������ϲ������ӵ����
template<typename T>
AVLTreeNode<T> * AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* proot)
{
	proot->rchild = rightRotation(proot->rchild);
	return leftRotation(proot);

}

//������������ �� �����������Һ���
template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* proot)
{
	proot->lchild = leftRotation(proot->lchild);
	return rightRotation(proot);
}

//����
template<typename T>
void AVLTree<T>::insert(T key)
{
	insert(root, key);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &pnode, T key)
{
	if (pnode == nullptr) //Ѱ�ҵ�����λ�á�
	{
		pnode = new AVLTreeNode<T>(key, nullptr, nullptr);
	}
	else if (key > pnode->key)
	{
		pnode->rchild = insert(pnode-> rchild, key);
		if (height(pnode->rchild) - height(pnode->lchild) == 2) //ʧ��
		{
			if (key > pnode->rchild->key) // �Ҳ��ң�����
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
	//���¼���߶�
	pnode->height = max(height(pnode->lchild), height(pnode->rchild)) + 1; //������Һ��Ӷ�Ϊ�գ���ڵ�߶�Ϊ1
	return pnode;


}

//ɾ��Ԫ��
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
		if (pnode->key == key) // �ҵ���
		{
			//���������������Ϊ��
			if (pnode->lchild != nullptr && pnode->rchild != nullptr)
			{
				//������������ߣ�����������Ѱ���滻
				if (height(pnode->lchild) > height(pnode->rchild))
				{
					//Ѱ�������������ڵ㣬��pnode��ǰ����
					AVLTreeNode<T>* ppre = maximum(pnode->lchild);
					pnode->key = ppre->key;
					pnode->lchild = remove(pnode->lchild, ppre->key);//�ݹ�ɾ�������������ڵ㡣
				}
				else //������������Ѱ���滻
				{
					//Ѱ������������С�ڵ�,pnode�ĺ��
					AVLTreeNode<T>* psuc = minimum(pnode->rchild); 
					pnode->key = psuc->key;
					pnode->rchild = remove(pnode->rchild, psuc->key);//�ݹ�ɾ��,�ܻ�ݹ鵽һ������������Ϊ�յģ��Ϳ���ֱ��ɾ���ˡ�

				}
			}
			else
			{
				//���ڿ���ɾ����
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
			//ɾ���������Ľڵ㣬ʹ��߸��ұߵ͡� ��Ҫ��������������������
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
			//ɾ���������Ľڵ㣬�ұ߸���ߵ͡�Ҫ��������������������
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


//�ݹ����ָ��Ԫ��
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

//�ǵݹ����ָ��Ԫ��
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

//����������
//�������
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

//�������
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
//�������
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

//��������
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
		destory(pnode->lchild); //���������������
		destory(pnode->rchild);
		delete pnode;
		pnode = nullptr; //����ָ����ָ��
	}	
}

//�����ֵ����Сֵ��
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