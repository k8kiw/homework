#pragma once
#include <iostream>

template<class T>
class arrayStack
{
public:
	/*
	���캯��
	*/
	arrayStack(int n);

	/*
	��������
	*/
	~arrayStack();

	/*
	�ж��Ƿ�Ϊ��
	*/
	bool empty();

	/*
	���ջ
	*/
	bool clear();

	/*
	ջ����
	*/
	int size();

	/*
	����ջ��Ԫ��
	*/
	T& top();

	/*
	��ջ
	*/
	bool pop(T& Elem);

	/*
	��ջ
	*/
	bool push(const T& Elem);

private:
	int stackTop;
	int arrayLen;	//���鳤��
	T* stack;		//ջ
};






template<class T>
arrayStack<T>::arrayStack(int n)
{
	if (n < 1)
	{
		std::cerr << "ջ���ȱ������1��" << std::endl;
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
		std::cerr << "ջΪ�գ��޷�����" << std::endl;
		exit(0);
	}
	return stack[stackTop];
}

template<class T>
bool arrayStack<T>::pop(T & Elem)
{
	if (stackTop == -1)
	{
		std::cerr << "ջΪ�գ��޷���ջ��" << std::endl;
		return false;
	}
	Elem = stack[stackTop];
	stack[stackTop--].~T();
	return true;
}

template<class T>
bool arrayStack<T>::push(const T & Elem)
{
	if (stackTop == arrayLen - 1)	//��ջ��������
	{
		T* temp = new T[arrayLen * 2];

		for (int i = 0; i < arrayLen; i++)	//��������
		{
			temp[i] = stack[i];
		}

		delete[]stack;
		stack = temp;	//���ݺ��ջ
		arrayLen *= 2;
	}
	stack[++stackTop] = Elem;
	return true;
}