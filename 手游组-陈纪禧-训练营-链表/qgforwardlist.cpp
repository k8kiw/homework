#include "qgforwardlist.h"
#include <iostream>


QGForwardList::QGForwardList() :head(nullptr), tail(nullptr)
{
	head = new Node;
	if (head != nullptr)
	{
		head->data = NULL;
		head->next = nullptr;
	}
	else	//�����ڴ�ʧ��
	{
		head = nullptr;
	}
}

QGForwardList::~QGForwardList()
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

void QGForwardList::setList(int n)
{
	if (n == 0)
	{
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
			pre = current;
			current->next = nullptr;	//ʹβ�ڵ��nextΪ��

			if (i == n - 1)			//β�ڵ�
			{
				tail = current;
			}
		}
	}
}

bool QGForwardList::print()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷���ӡ��" << std::endl;
		return false;
	}
	Node *p = head->next;
	int i = 0;
	while (p != nullptr)
	{
		std::cout << "����ĵ�"<< i + 1 << "��Ԫ��Ϊ:" << p->data << std::endl;
		p = p->next;
		i++;
	}
	std::cout << "������" << size() << "��Ԫ��" << std::endl;
	return true;
}

bool QGForwardList::front(ElemType& e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ�" << std::endl;
		return false;
	}
	e = head->next->data;

	return true;
}

bool QGForwardList::back(ElemType& e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ�" << std::endl;
		return false;
	}
	e = tail->data;

	return true;
}

bool QGForwardList::push_front(ElemType& e)
{
	if (head == nullptr)
	{
		std::cout << "����ͷ�ڵ�Ϊ�գ��޷����Ԫ�أ�" << std::endl;
		return false;
	}

	Node *p = new Node;
	p->data = e;
	p->next = head->next;
	head->next = p;

	return true;
}

bool QGForwardList::pop_front()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ɾ����һ��Ԫ�أ�" << std::endl;
		return false;
	}
	Node *p = head->next;
	head->next = p->next;
	delete p;
	p = nullptr;
	return true;
}

bool QGForwardList::push_back(ElemType& e)
{
	if (head == nullptr)
	{
		std::cout << "\n����ͷ�ڵ�Ϊ�գ��޷�����Ԫ��!\n" << std::endl;
		return false;
	}
	Node *p = new Node;
	p->data = e;

	tail->next = p;
	p->next = nullptr;
	tail = p;
	p = nullptr;
	return true;
}

bool QGForwardList::pop_back()
{
	if (tail == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ɾ�����һ��Ԫ�أ�" << std::endl;
		return false;
	}
	Node *p = head;
	while (p->next != tail)	//ʹpָ�����ڶ����ڵ�
	{
		p = p->next;
	}
	p->next = nullptr;
	delete tail;
	tail = p;
	p = nullptr;
	std::cout << "���һ��Ԫ��ɾ���ɹ���" << std::endl;
	return true;
}

bool QGForwardList::insert(unsigned int index, ElemType& e)
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
		p->next = nullptr;
		tail = p;

		p = nullptr;
		return true;
	}
	if (index < 0 || index > size())
	{
		std::cout << "\n����λ��Խ�磡\n" << std::endl;
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
		current = nullptr;
		pre = nullptr;
	}
	std::cout << "\n�������!\n" << std::endl;
	return true;
}

bool QGForwardList::erase(unsigned int index)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "\n����Ϊ�գ��޷�ɾ��Ԫ�أ�\n" << std::endl;
		return false;
	}
	if (index < 1 || index > size())
	{
		std::cout << "\nɾ��λ��Խ�磡\n" << std::endl;
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
		delete current;
		current = nullptr;
		pre = nullptr;
	}
	std::cout << "\nɾ�����!\n" << std::endl;
	return true;
}

bool QGForwardList::clear()
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
		while (current != nullptr)
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

bool QGForwardList::contain(ElemType & e)
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

unsigned int QGForwardList::size()
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

bool QGForwardList::traverse(void(*visit)(ElemType &e))
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ִ��" << std::endl;
		return false;
	}
	else
	{
		Node *p = head;
		while ((p = p->next) != nullptr)
		{
			(*visit)(p->data);
		}
		return true;
	}
}

bool QGForwardList::reverse()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷���ת!" << std::endl;
		return false;
	}
	while (1)
	{
		std::cout << "\n1.��ת��������\t2.��תż�ڵ�" << std::endl;
		int n;
		std::cin >> n;
		if (n != 1 && n != 2)
		{
			std::cout << "����������������룡" << std::endl;
			continue;
		}
		if (n == 1)
		{
			Node *pre = head->next;
			Node *current = pre->next;

			while (current != nullptr)
			{
				pre->next = current->next;
				current->next = head->next;
				head->next = current;
				current = pre->next;
			}
			tail = pre;
			std::cout << "�����ѷ�ת" << std::endl;
			break;
		}
		if (n == 2)
		{
			reverseEven();
			break;
		}
	}
	return true;
}

bool QGForwardList::isLoop()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷��ж�" << std::endl;
		return false;
	}
	else
	{
		std::cout << "\n�Ƿ�Ҫ���������γɻ�?(���жϽ���ʱ�Ὣ�临ԭ)" << std::endl;
		std::cout << "1.��\t2.����" << std::endl;
		int n;
		std::cin >> n;
		if (n == 1)
		{
			tail->next = head;
		}

		Node *fast = head;
		Node *slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				std::cout << "\n�������л�" << std::endl;
				return true;
			}
		}
		std::cout << "\n�������޻�" << std::endl;
		return false;
	}
}

bool QGForwardList::reverseEven()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷���ת��" << std::endl;
		return false;
	}
	else if(size() == 1)
	{
		std::cout << "������ż�ڵ㣬�޷���ת��" << std::endl;
		return false;
	}
	else
	{
		Node *p1 = head->next;
		Node *p2 = p1->next;
		Node *pre = head;
		while (p2 != nullptr)
		{	
			p1->next = p2->next;
			p2->next = p1;
			pre->next = p2;

			if (p1->next == nullptr)	//�ڵ�ż����
			{
				tail = p1;
				break;
			}
			if (p1->next->next == nullptr)		//�ڵ�Ϊ������
			{
				break;
			}
			
			p1 = p1->next;
			pre = p2->next;
			p2 = p1->next;
		}
		std::cout << "ż�ڵ��ѷ�ת" << std::endl;
		return true;
	}
}

bool QGForwardList::middleElem(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "����Ϊ�գ��޷�ִ��" << std::endl;
		return false;
	}
	else if (size() == 1)
	{
		std::cout << "�����Ȳ��㣡" << std::endl;
		return false;
	}
	else
	{
		Node *p = head;
		for (unsigned int i = 0; i <= size() / 2 - 1; i++)
		{
			p = p->next;
		}
		e = p->data;
		return true;
	}
}
