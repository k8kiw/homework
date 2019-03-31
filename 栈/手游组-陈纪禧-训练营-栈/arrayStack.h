#pragma once
#include <iostream>

template<class T>
class arrayStack
{
public:
	/*
	构造函数
	*/
	arrayStack(int n);

	/*
	析构函数
	*/
	~arrayStack();

	/*
	判断是否为空
	*/
	bool empty();

	/*
	清空栈
	*/
	bool clear();

	/*
	栈长度
	*/
	int size();

	/*
	返回栈顶元素
	*/
	T& top();

	/*
	出栈
	*/
	bool pop(T& Elem);

	/*
	入栈
	*/
	bool push(const T& Elem);

private:
	int stackTop;
	int arrayLen;	//数组长度
	T* stack;		//栈
};






template<class T>
arrayStack<T>::arrayStack(int n)
{
	if (n < 1)
	{
		std::cerr << "栈长度必须大于1！" << std::endl;
		exit(0);
	}
	arrayLen = n;
	stack = new T[n];
	stackTop = -1;
}

template<class T>
arrayStack<T>::~arrayStack()
{
	delete[]stack;
}

template<class T>
bool arrayStack<T>::empty()
{
	if (-1 == stackTop)
	{
		return true;
	}
	return false;
}

template<class T>
bool arrayStack<T>::clear()
{
	stackTop = -1;
	return true;
}

template<class T>
int arrayStack<T>::size()
{
	return (stackTop + 1);
}

template<class T>
T & arrayStack<T>::top()
{
	if (-1 == stackTop)
	{
		std::cerr << "栈为空，无法返回" << std::endl;
		exit(0);
	}
	return stack[stackTop];
}

template<class T>
bool arrayStack<T>::pop(T & Elem)
{
	if (stackTop == -1)
	{
		std::cerr << "栈为空，无法出栈！" << std::endl;
		return false;
	}
	Elem = stack[stackTop];
	stack[stackTop--].~T();
	return true;
}

template<class T>
bool arrayStack<T>::push(const T & Elem)
{
	if (stackTop == arrayLen - 1)	//爆栈容量翻倍
	{
		T* temp = new T[arrayLen * 2];

		for (int i = 0; i < arrayLen; i++)	//复制数组
		{
			temp[i] = stack[i];
		}

		delete[]stack;
		stack = temp;	//扩容后的栈
		arrayLen *= 2;
	}
	stack[++stackTop] = Elem;
	return true;
}