#pragma once
#include <iostream>
#include <stack>
#include <queue>


template<class T>
struct BiNode
{
	T data;
	BiNode<T>* left;
	BiNode<T>* right;
	BiNode():left(nullptr), right(nullptr){}
};

template<class T>
class BinaryTree
{
protected:
	BiNode<T>* m_pRoot;

public:
	BinaryTree();
	~BinaryTree();

public:
	//���ظ��ڵ�
	BiNode<T>* getRoot();

	//���ٶ�����
	void Destroy(BiNode<T>* &root);


	//���ɶ�����
	bool Create(BiNode<T>* &root);


	//�������
	bool PreOrderTraverse(BiNode<T>* root, void(*visit)(T e));
	bool PreOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e));


	//�������
	bool InOrderTraverse(BiNode<T>* root, void(*visit)(T e));
	bool InOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e));


	//�������
	bool PostOrderTraverse(BiNode<T>* root, void(*visit)(T e));
	bool PostOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e));


	//��α���
	bool LevelOrderTraverse(BiNode<T>* root, void(*visit)(T e));


	//��ӡ, ͨ��visit����
	static void print(T e);
	
};

template<class T>
BinaryTree<T>::BinaryTree()
{
	m_pRoot = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	Destroy(m_pRoot);
}

template<class T>
inline BiNode<T>* BinaryTree<T>::getRoot()
{
	return m_pRoot;
}

template<class T>
inline void BinaryTree<T>::Destroy(BiNode<T>* &root)
{
	if (root != nullptr)
	{
		Destroy(root->left);		//����������
		Destroy(root->right);		//����������

		delete root;		//���ٸ�
		root = nullptr;
	}
}

template<class T>
inline bool BinaryTree<T>::Create(BiNode<T>* &root)
{
	T e;
	std::cin >> e;

	if (e == '#')
	{
		root = nullptr;
	}
	else
	{
		root = new BiNode<T>;
		if (root == nullptr)
		{
			return false;
		}
		root->data = e;
		Create(root->left);
		Create(root->right);
	}

	return true;
}

template<class T>
inline bool BinaryTree<T>::PreOrderTraverse(BiNode<T>* root, void(*visit)(T e))
{
	if (root != nullptr)
	{
		(*visit)(root->data);			//����
		PreOrderTraverse(root->left, &print);
		PreOrderTraverse(root->right, &print);

		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline bool BinaryTree<T>::PreOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e))
{
	//����
	if (root == nullptr)
		return false;
	//�ǿ�
	BiNode<T>* p = root;
	std::stack<BiNode<T>*> s;
	while (!s.empty() || p != nullptr)
	{
		//��������������������������ڵ㣬Ȼ����ջ�����ಿ��(���˺����ջʱ�����)��һ��
		while (p)
		{
			(*visit)(p->data);
			//���ڵ���ջ��Ϊ�˱�����ڵ㣬�ܹ�˳����������������
			s.push(p);
			p = p->left;
		}

		//�·�������Ϊ��ʱ,ջ��Ϊ��ʱ�ͳ�ջ(������ýڵ�ͳ�ջ���Է����丸�ڵ��������)
		//��������Ϊ�վͼ�����ջ(�������whileѭ��),ֱ���������������ĸ��ڵ�(��ʼ�ݹ�)
		if (!s.empty())
		{
			p = s.top();
			s.pop();

			//��������������ʼ"�ݹ�"
			p = p->right;
		}
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::InOrderTraverse(BiNode<T>* root, void(*visit)(T e))
{
	if (root != nullptr)
	{
		InOrderTraverse(root->left, &print);
		(*visit)(root->data);			//����
		InOrderTraverse(root->right, &print);

		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline bool BinaryTree<T>::InOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e))
{
	//����
	if (root == NULL)
		return false;
	//���ǿ�
	BiNode<T>* p = root;
	std::stack<BiNode<T>*> s;
	while (!s.empty() || p != nullptr)	//pΪ��һ��p�ڵ��������������Ϊ�������������
	{
		//һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
		while (p)
		{
			s.push(p);
			p = p->left;
		}

		//�·�������Ϊ��(p��)ʱ,ջ��Ϊ��ʱ�ͳ�ջ(������ýڵ�Ͷ����������丸�ڵ��������)
		//��������Ϊ�վͼ�����ջ(�������whileѭ��),ֱ���������������ĸ��ڵ�(��ʼ�ݹ�)
		if (!s.empty())
		{
			p = s.top();		//���������ջ�����
			s.pop();
			(*visit)(p->data);

			//��������������ʼ�µ�һ������������(�ݹ��ʵ��)
			p = p->right;
			//��������Ϊ�յ�ջ��Ϊ�գ���������ջ(����if)��ֱ��������������(ִ������������)
		}
	}

	return true;
}

template<class T>
inline bool BinaryTree<T>::PostOrderTraverse(BiNode<T>* root, void(*visit)(T e))
{
	if (root != nullptr)
	{
		PostOrderTraverse(root->left, &print);
		PostOrderTraverse(root->right, &print);
		(*visit)(root->data);			//����

		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline bool BinaryTree<T>::PostOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e))
{
	if (root == nullptr)
		return false;
	
	//���������Ҫ֪����һ�����ʵĽڵ㣬������������������
	//����������Ҫ�������ڵ�ȥ����������(��ʱջ��Ϊ���ڵ㼴���ڵ�)����Ҫ�ȷ������������ٷ���ջ��
	//�������ͷ���ջ������

	std::stack<BiNode<T>*> s;
	//cur:��ǰ���ʽڵ㣬pre:�ϴη��ʽڵ�
	BiNode<T>* cur = root, *pre = nullptr;
	
	//�Ȱ�cur�ƶ������������±�
	while (cur)
	{
		s.push(cur);
		cur = cur->left;
	}

	while (!s.empty())
	{
		//���ڵ��ջ
		cur = s.top();
		s.pop();

		//һ�����ڵ㱻���ʵ�ǰ���ǣ��������������������ϴα����ʹ�
		if (cur->right == nullptr || cur->right == pre)
		{
			(*visit)(cur->data);
			//�޸��ϴα����ʵĽڵ�
			pre = cur;
		}
		else
		{
			//���ڵ��ٴ���ջ����������������������
			s.push(cur);
			//������������������һ����Ϊ��(�������ж�)
			cur = cur->right;
			//��curΪ�������������·�����������ʼ�ݹ�
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
		}
	}

	return 0;
}

template<class T>
inline bool BinaryTree<T>::LevelOrderTraverse(BiNode<T>* root, void(*visit)(T e))
{
	if (root != nullptr)
	{
		BiNode<T>* p = nullptr;		//���ڲ�α�����ָ��
		std::queue<BiNode<T>*> q;	//�����д�ŵ���ָ�룬������ΪBiNode<T>*

		q.push(root);				//���ڵ����
		while (!q.empty())			//����Ϊ��ʱ
		{
			p = q.front();			//pָ���ͷ
			q.pop();				//��ͷ����
			(*visit)(p->data);		//�����ӵ�Ԫ�ص���

			if (p->left != nullptr)	//�������������������
				q.push(p->left);
			if (p->right != nullptr)//�������������������
				q.push(p->right);
		}

		return true;
	}
	return false;
}

template<class T>
inline void BinaryTree<T>::print(T e)
{
	std::cout << e << "  ";
}
