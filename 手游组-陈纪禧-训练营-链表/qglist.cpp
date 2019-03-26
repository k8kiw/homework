#include "qglist.h"
#include <iostream>


QGList::QGList() :head(nullptr), tail(nullptr)
{
	head = new Node;
	if (head != nullptr)
	{
		head->data = NULL;
		head->next = nullptr;
		head->prior = nullptr;
	}
	else	//�����ڴ�ʧ��
	{
		head = nullptr;
	}
}

QGList::~QGList()
{
	if (head->next == nullptr)		//������ֱ������ͷ�ڵ�
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node *p = head;

		while (head != tail)
		{
			head = head->next;
			delete p;
			p = head;
		}
		delete head;
		head = nullptr;
		tail = nullptr;
		p = nullptr;
	}
}

void QGList::setList(int n)
{
	if (n == 0)
	{
		head->prior = nullptr;
		head->next = nullptr;
		tail = nullptr;
	}
	else
	{
		Node *pre = head;		//��һ�ڵ�
		for (int i = 0; i < n; i++)
		{
			Node *current = new Node;	//��ǰ�ڵ�

			std::cout << "�������" << i + 1 << "���ڵ������:";	//��������
			std::cin >> current->data;

			pre->next = current;	//���ӽڵ�
			current->prior = pre;

			pre = current;
			current->next = nullptr;	//ʹβ�ڵ��nextΪ��

			if (i == n - 1)			//β�ڵ�
			{
				tail = current;
			}
		}
		tail->next = head;
		head->prior = tail;
	}
}

bool QGList::print()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷���ӡ��" << std::endl;
		return false;
	}
	Node *p = head->next;
	int i = 0;
	while (p != head)
	{
		std::cout << "����ĵ�" << i + 1 << "��Ԫ��Ϊ:" << p->data << std::endl;
		p = p->next;
		i++;
	}
	std::cout << "������" << size() << "��Ԫ��" << std::endl;
	return true;
}

bool QGList::front(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ�" << std::endl;
		return false;
	}
	e = head->next->data;

	return true;
}

bool QGList::back(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ�" << std::endl;
		return false;
	}
	e = tail->data;

	return true;
}

bool QGList::push_front(ElemType & e)
{
	if (head == nullptr)
	{
		std::cout << "\n����ͷ�ڵ�Ϊ�գ��޷�����Ԫ��!\n" << std::endl;
		return false;
	}

	Node *p = new Node;
	p->data = e;

	p->next = head->next;	//��������
	head->next = p;

	p->prior = head;		//��������
	p->next->prior = p;

	std::cout << "Ԫ�������" << std::endl;
	return true;
}

bool QGList::pop_front()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ɾ����һ��Ԫ�أ�" << std::endl;
		return false;
	}
	Node *p = head->next;
	head->next = p->next;	//����Ͽ�
	p->next->prior = head;	//����Ͽ�
	delete p;
	p = nullptr;
	std::cout << "��һ��Ԫ����ɾ��" << std::endl;
	return true;
}

bool QGList::push_back(ElemType & e)
{
	if (head == nullptr)
	{
		std::cout << "\n����ͷ�ڵ�Ϊ�գ��޷�����Ԫ��!\n" << std::endl;
		return false;
	}
	Node *p = new Node;
	p->data = e;

	tail->next = p;
	p->next = head;
	p->prior = tail;
	tail = p;
	head->prior = tail;

	p = nullptr;
	std::cout << "Ԫ�������" << std::endl;
	return true;
}

bool QGList::pop_back()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ɾ�����һ��Ԫ�أ�" << std::endl;
		return false;
	}
	Node *p = head;
	while (p->next != tail)	//ʹpָ�����ڶ����ڵ�
	{
		p = p->next;
	}

	p->next = head;
	head->prior = p;
	delete tail;
	tail = p;
	p = nullptr;

	std::cout << "���һ��Ԫ��ɾ���ɹ���" << std::endl;
	return true;
}

bool QGList::insert(unsigned int index, ElemType & e)
{
	if (head == nullptr)
	{
		std::cout << "\n����ͷ�ڵ�Ϊ�գ��޷�����Ԫ��!\n" << std::endl;
		return false;
	}
	if (head->next == nullptr)	//������
	{
		std::cout << "��������Ϊ�գ�ֻ������ڵ�һ�ڵ㣡" << std::endl;
		Node *p = new Node;
		p->data = e;

		head->next = p;
		head->prior = p;
		p->next = head;
		p->prior = head;

		tail = p;
		p = nullptr;
		return true;
	}
	if (index < 0 || index > size())
	{
		std::cout << "����λ��Խ�磡" << std::endl;
		return false;
	}
	else if (index == 0)
	{
		push_front(e);
	}
	else if (index == size())
	{
		push_back(e);
	}
	else
	{
		Node *pre = head;
		for (unsigned int i = 0; i < index; i++)
		{
			pre = pre->next;
		}
		Node *current = new Node;
		current->data = e;

		current->next = pre->next;
		pre->next = current;
		current->prior = pre;
		current->next->prior = current;

		current = nullptr;
		pre = nullptr;
	}
	std::cout << "\n�������!\n" << std::endl;
	return true;
}

bool QGList::erase(unsigned int index)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ��" << std::endl;
		return false;
	}
	if (index < 1 || index > size())
	{
		std::cout << "ɾ��λ��Խ�磡" << std::endl;
		return false;
	}
	else if (index == 1)
	{
		pop_front();
	}
	else if (index == size())
	{
		pop_back();
	}
	else
	{
		Node *pre = head;
		for (unsigned int i = 1; i < index; i++)
		{
			pre = pre->next;
		}
		Node *current = pre->next;

		pre->next = current->next;
		current->next->prior = pre;

		delete current;
		current = nullptr;
		pre = nullptr;
	}
	return true;
}

bool QGList::clear()
{
	if (head == nullptr)	//��������
	{
		std::cout << "�����ѱ�����" << std::endl;
		return false;
	}
	else
	{
		Node *pre = head->next;
		Node *current = pre->next;
		while (current != head)
		{
			delete pre;
			pre = current;
			current = current->next;
		}
		delete pre;
		pre = nullptr;
		head->next = nullptr;
		return true;
	}
}

bool QGList::contain(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷����ң�" << std::endl;
		return false;
	}
	else
	{
		Node *current = head;
		for (unsigned int i = 0; i < size(); i++)
		{
			current = current->next;
			if (current->data == e)
			{
				std::cout << "��Ԫ��Ϊ����ĵ�" << i + 1 << "��Ԫ��" << std::endl;
				return true;
			}
		}
		std::cout << "δ�ҵ���Ԫ�أ�" << std::endl;
		return false;
	}
}

unsigned int QGList::size()
{
	if (head == nullptr || head->next == nullptr)
	{
		return 0;
	}
	unsigned int count = 0;
	Node *current = head;
	while (current != tail)
	{
		count++;
		current = current->next;
	}
	return count;
}

bool QGList::traverse(void(*visit)(ElemType &e))
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ִ��" << std::endl;
		return false;
	}
	else
	{
		Node *p = head;
		while ((p = p->next) != head)
		{
			(*visit)(p->data);
		}
		return true;
	}
}
