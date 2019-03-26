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
	else	//申请内存失败
	{
		head = nullptr;
	}
}

QGList::~QGList()
{
	if (head->next == nullptr)		//空链表直接销毁头节点
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
		Node *pre = head;		//上一节点
		for (int i = 0; i < n; i++)
		{
			Node *current = new Node;	//当前节点

			std::cout << "请输入第" << i + 1 << "个节点的数据:";	//输入数据
			std::cin >> current->data;

			pre->next = current;	//连接节点
			current->prior = pre;

			pre = current;
			current->next = nullptr;	//使尾节点的next为空

			if (i == n - 1)			//尾节点
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
		std::cout << "链表为空，无法打印！" << std::endl;
		return false;
	}
	Node *p = head->next;
	int i = 0;
	while (p != head)
	{
		std::cout << "链表的第" << i + 1 << "个元素为:" << p->data << std::endl;
		p = p->next;
		i++;
	}
	std::cout << "链表共有" << size() << "个元素" << std::endl;
	return true;
}

bool QGList::front(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空！" << std::endl;
		return false;
	}
	e = head->next->data;

	return true;
}

bool QGList::back(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空！" << std::endl;
		return false;
	}
	e = tail->data;

	return true;
}

bool QGList::push_front(ElemType & e)
{
	if (head == nullptr)
	{
		std::cout << "\n链表头节点为空，无法插入元素!\n" << std::endl;
		return false;
	}

	Node *p = new Node;
	p->data = e;

	p->next = head->next;	//正向连接
	head->next = p;

	p->prior = head;		//反向连接
	p->next->prior = p;

	std::cout << "元素已添加" << std::endl;
	return true;
}

bool QGList::pop_front()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空，无法删除第一个元素！" << std::endl;
		return false;
	}
	Node *p = head->next;
	head->next = p->next;	//正向断开
	p->next->prior = head;	//反向断开
	delete p;
	p = nullptr;
	std::cout << "第一个元素已删除" << std::endl;
	return true;
}

bool QGList::push_back(ElemType & e)
{
	if (head == nullptr)
	{
		std::cout << "\n链表头节点为空，无法插入元素!\n" << std::endl;
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
	std::cout << "元素已添加" << std::endl;
	return true;
}

bool QGList::pop_back()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空，无法删除最后一个元素！" << std::endl;
		return false;
	}
	Node *p = head;
	while (p->next != tail)	//使p指向倒数第二个节点
	{
		p = p->next;
	}

	p->next = head;
	head->prior = p;
	delete tail;
	tail = p;
	p = nullptr;

	std::cout << "最后一个元素删除成功！" << std::endl;
	return true;
}

bool QGList::insert(unsigned int index, ElemType & e)
{
	if (head == nullptr)
	{
		std::cout << "\n链表头节点为空，无法插入元素!\n" << std::endl;
		return false;
	}
	if (head->next == nullptr)	//空链表
	{
		std::cout << "由于链表为空，只能添加在第一节点！" << std::endl;
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
		std::cout << "插入位置越界！" << std::endl;
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
	std::cout << "\n插入完成!\n" << std::endl;
	return true;
}

bool QGList::erase(unsigned int index)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空" << std::endl;
		return false;
	}
	if (index < 1 || index > size())
	{
		std::cout << "删除位置越界！" << std::endl;
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
	if (head == nullptr)	//链表被销毁
	{
		std::cout << "链表已被销毁" << std::endl;
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
		std::cout << "链表为空，无法查找！" << std::endl;
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
				std::cout << "该元素为链表的第" << i + 1 << "个元素" << std::endl;
				return true;
			}
		}
		std::cout << "未找到该元素！" << std::endl;
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
		std::cout << "链表为空，无法执行" << std::endl;
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
