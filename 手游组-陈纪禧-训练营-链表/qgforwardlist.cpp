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
	else	//申请内存失败
	{
		head = nullptr;
	}
}

QGForwardList::~QGForwardList()
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

void QGForwardList::setList(int n)
{
	if (n == 0)
	{
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
			pre = current;
			current->next = nullptr;	//使尾节点的next为空

			if (i == n - 1)			//尾节点
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
		std::cout << "链表为空，无法打印！" << std::endl;
		return false;
	}
	Node *p = head->next;
	int i = 0;
	while (p != nullptr)
	{
		std::cout << "链表的第"<< i + 1 << "个元素为:" << p->data << std::endl;
		p = p->next;
		i++;
	}
	std::cout << "链表共有" << size() << "个元素" << std::endl;
	return true;
}

bool QGForwardList::front(ElemType& e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空！" << std::endl;
		return false;
	}
	e = head->next->data;

	return true;
}

bool QGForwardList::back(ElemType& e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空！" << std::endl;
		return false;
	}
	e = tail->data;

	return true;
}

bool QGForwardList::push_front(ElemType& e)
{
	if (head == nullptr)
	{
		std::cout << "链表头节点为空，无法添加元素！" << std::endl;
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
		std::cout << "链表为空，无法删除第一个元素！" << std::endl;
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
		std::cout << "\n链表头节点为空，无法插入元素!\n" << std::endl;
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
		std::cout << "链表为空，无法删除最后一个元素！" << std::endl;
		return false;
	}
	Node *p = head;
	while (p->next != tail)	//使p指向倒数第二个节点
	{
		p = p->next;
	}
	p->next = nullptr;
	delete tail;
	tail = p;
	p = nullptr;
	std::cout << "最后一个元素删除成功！" << std::endl;
	return true;
}

bool QGForwardList::insert(unsigned int index, ElemType& e)
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
		p->next = nullptr;
		tail = p;

		p = nullptr;
		return true;
	}
	if (index < 0 || index > size())
	{
		std::cout << "\n插入位置越界！\n" << std::endl;
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
	std::cout << "\n插入完成!\n" << std::endl;
	return true;
}

bool QGForwardList::erase(unsigned int index)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "\n链表为空，无法删除元素！\n" << std::endl;
		return false;
	}
	if (index < 1 || index > size())
	{
		std::cout << "\n删除位置越界！\n" << std::endl;
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
	std::cout << "\n删除完成!\n" << std::endl;
	return true;
}

bool QGForwardList::clear()
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
		std::cout << "链表为空，无法执行" << std::endl;
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
		std::cout << "链表为空，无法反转!" << std::endl;
		return false;
	}
	while (1)
	{
		std::cout << "\n1.反转整个链表\t2.反转偶节点" << std::endl;
		int n;
		std::cin >> n;
		if (n != 1 && n != 2)
		{
			std::cout << "输入错误，请重新输入！" << std::endl;
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
			std::cout << "链表已反转" << std::endl;
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
		std::cout << "链表为空，无法判断" << std::endl;
		return false;
	}
	else
	{
		std::cout << "\n是否要将该链表形成环?(在判断结束时会将其复原)" << std::endl;
		std::cout << "1.是\t2.不是" << std::endl;
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
				std::cout << "\n该链表有环" << std::endl;
				return true;
			}
		}
		std::cout << "\n该链表无环" << std::endl;
		return false;
	}
}

bool QGForwardList::reverseEven()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空，无法反转！" << std::endl;
		return false;
	}
	else if(size() == 1)
	{
		std::cout << "链表无偶节点，无法反转！" << std::endl;
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

			if (p1->next == nullptr)	//节点偶数个
			{
				tail = p1;
				break;
			}
			if (p1->next->next == nullptr)		//节点为奇数个
			{
				break;
			}
			
			p1 = p1->next;
			pre = p2->next;
			p2 = p1->next;
		}
		std::cout << "偶节点已反转" << std::endl;
		return true;
	}
}

bool QGForwardList::middleElem(ElemType & e)
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "链表为空，无法执行" << std::endl;
		return false;
	}
	else if (size() == 1)
	{
		std::cout << "链表长度不足！" << std::endl;
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
