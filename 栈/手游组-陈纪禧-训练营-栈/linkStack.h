#pragma once
#include <iostream>

template<class T>
struct Node
{
	T data;
	Node<T>* next;
	Node() :next(nullptr){}
};

template<class T>
class linkStack
{
protected:
	Node<T> * stackTop;
	int length;

public:
	/*
	���캯��
	*/
	linkStack();

	/*
	��������
	*/
	~linkStack();

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
	bool top(T & Elem);

	/*
	��ջ
	*/
	bool pop();
	bool pop(T& Elem);

	/*
	��ջ
	*/
	bool push(const T& Elem);

};





template<class T>
linkStack<T>::linkStack()
{
	stackTop = nullptr;
	length = 0;
}

template<class T>
linkStack<T>::~linkStack()
{
	clear();
}

template<class T>
bool linkStack<T>::empty()
{
	if (0 == length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool linkStack<T>::clear()
{
	while (stackTop != nullptr)
	{
		Node<T>* p = stackTop;
		stackTop = stackTop->next;
		delete p;
	}
	return true;
}

template<class T>
int linkStack<T>::size()
{
	return lenth;
}

template<class T>
bool linkStack<T>::top(T & Elem)
{
	if (empty())
	{
		std::cerr << "ջΪ�գ��޷�����" << std::endl;
		return false;
	}
	Elem = stackTop->data;
	return true;
}

template<class T>
bool linkStack<T>::pop()
{
	if (empty())
	{
		std::cerr << "ջΪ�գ��޷���ջ��" << std::endl;
		return false;
	}
	Node<T> *p = stackTop;
	stackTop = stackTop->next;
	delete(p);
	length--;
	return true;
}

template<class T>
bool linkStack<T>::pop(T & Elem)
{
	if (empty())
	{
		std::cerr << "ջΪ�գ��޷���ջ��" << std::endl;
		return false;
	}
	Elem = stackTop->data;

	Node<T> *p = stackTop;
	stackTop = stackTop->next;
	delete(p);
	length--;
	return true;
}

template<class T>
bool linkStack<T>::push(const T & Elem)
{
	Node<T> *newTop = new Node<T>;
	newTop->data = Elem;
	newTop->next = stackTop;

	stackTop = newTop;
	length++;
	return true;
}
