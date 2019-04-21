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
	//返回根节点
	BiNode<T>* getRoot();

	//销毁二叉树
	void Destroy(BiNode<T>* &root);


	//生成二叉树
	bool Create(BiNode<T>* &root);


	//先序遍历
	bool PreOrderTraverse(BiNode<T>* root, void(*visit)(T e));
	bool PreOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e));


	//中序遍历
	bool InOrderTraverse(BiNode<T>* root, void(*visit)(T e));
	bool InOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e));


	//后序遍历
	bool PostOrderTraverse(BiNode<T>* root, void(*visit)(T e));
	bool PostOrderTraverse_Stack(BiNode<T>* root, void(*visit)(T e));


	//层次遍历
	bool LevelOrderTraverse(BiNode<T>* root, void(*visit)(T e));


	//打印, 通过visit调用
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
		Destroy(root->left);		//销毁左子树
		Destroy(root->right);		//销毁右子树

		delete root;		//销毁根
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
		(*visit)(root->data);			//先序
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
	//空树
	if (root == nullptr)
		return false;
	//非空
	BiNode<T>* p = root;
	std::stack<BiNode<T>*> s;
	while (!s.empty() || p != nullptr)
	{
		//先序与中序的区别就是先输出根节点，然后入栈，其余部分(除了后面出栈时的输出)都一样
		while (p)
		{
			(*visit)(p->data);
			//根节点入栈是为了保存根节点，能够顺利访问所有右子树
			s.push(p);
			p = p->left;
		}

		//下方左子树为空时,栈不为空时就出栈(利用完该节点就出栈，以访问其父节点的右子树)
		//右子树仍为空就继续出栈(利用外层while循环),直到遇到有右子树的父节点(开始递归)
		if (!s.empty())
		{
			p = s.top();
			s.pop();

			//进入右子树，开始"递归"
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
		(*visit)(root->data);			//中序
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
	//空树
	if (root == NULL)
		return false;
	//树非空
	BiNode<T>* p = root;
	std::stack<BiNode<T>*> s;
	while (!s.empty() || p != nullptr)	//p为上一次p节点的右子树，以其为根进行中序遍历
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->left;
		}

		//下方左子树为空(p空)时,栈不为空时就出栈(利用完该节点就丢弃，访问其父节点的右子树)
		//右子树仍为空就继续出栈(利用外层while循环),直到遇到有右子树的父节点(开始递归)
		if (!s.empty())
		{
			p = s.top();		//中序遍历出栈即输出
			s.pop();
			(*visit)(p->data);

			//进入右子树，开始新的一轮左子树遍历(递归的实现)
			p = p->right;
			//若右子树为空但栈不为空，则连续出栈(本次if)，直到遇到有右子树(执行左子树遍历)
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
		(*visit)(root->data);			//后序

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
	
	//后序遍历需要知道上一个访问的节点，是左子树还是右子树
	//左子树就需要跳过根节点去访问右子树(此时栈顶为父节点即根节点)，需要先访问其右子树再访问栈顶
	//右子树就访问栈顶即可

	std::stack<BiNode<T>*> s;
	//cur:当前访问节点，pre:上次访问节点
	BiNode<T>* cur = root, *pre = nullptr;
	
	//先把cur移动到左子树最下边
	while (cur)
	{
		s.push(cur);
		cur = cur->left;
	}

	while (!s.empty())
	{
		//父节点出栈
		cur = s.top();
		s.pop();

		//一个根节点被访问的前提是：无右子树或右子树在上次被访问过
		if (cur->right == nullptr || cur->right == pre)
		{
			(*visit)(cur->data);
			//修改上次被访问的节点
			pre = cur;
		}
		else
		{
			//根节点再次入栈，接下来访问右子树即可
			s.push(cur);
			//进入右子树，右子树一定不为空(上面已判断)
			cur = cur->right;
			//以cur为根，遍历至最下方左子树，开始递归
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
		BiNode<T>* p = nullptr;		//用于层次遍历的指针
		std::queue<BiNode<T>*> q;	//队列中存放的是指针，故类型为BiNode<T>*

		q.push(root);				//根节点入队
		while (!q.empty())			//树不为空时
		{
			p = q.front();			//p指向队头
			q.pop();				//队头出队
			(*visit)(p->data);		//将出队的元素调用

			if (p->left != nullptr)	//若有左子树，将其入队
				q.push(p->left);
			if (p->right != nullptr)//若有右子树，将其入队
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
