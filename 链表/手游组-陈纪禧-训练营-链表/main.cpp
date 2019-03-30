#include <iostream>
#include <stdlib.h>
#include "qgforwardlist.h"
#include "qglist.h"


QGForwardList::ElemType sum1 = 0;
void Listsum1(QGForwardList::ElemType& e)
{
	sum1 += e;
}

QGList::ElemType sum2 = 0;
void Listsum2(QGList::ElemType& e)
{
	sum2 += e;
}

int main()
{
	std::cout << "请选择要创建的链表：" << std::endl;
	std::cout << "1.单链表\t2.双链表\t0.退出程序" << std::endl;
	int a;
	std::cin >> a;
	while (a != 1 && a != 2 && a != 0)
	{
		std::cout << "输入错误，请重新选择：" << std::endl;
		std::cout << "1.单链表\t2.双链表\t0.退出程序" << std::endl;
		std::cin >> a;
	}
	if (a == 0)
	{
		system("pause");
		return 0;
	}
	if (a == 1)		//单链表
	{
		std::cout << std::endl;
		std::cout << "请输入链表的节点个数:";
		int n;
		std::cin >> n;
		QGForwardList single;
		single.setList(n);
		std::cout << "链表已生成！" << std::endl;
		if (n == 0)
		{
			std::cout << "警告：链表为空，以下功能很可能会出错！" << std::endl;
		}
		
		while (1)
		{
			std::cout << std::endl;
			std::cout << "请选择想要的功能：" << std::endl;
			std::cout << "1.打印链表\t2.返回第一个元素\t3.返回最后一个元素" << std::endl;
			std::cout << "4.插入元素\t5.删除元素\t\t6.查找元素" << std::endl;
			std::cout << "7.清空链表\t8.链表长度\t\t9.链表反转" << std::endl;
			std::cout << "10.链表判环\t11.调用函数\t\t12.返回中间节点" << std::endl;
			std::cout << "0.退出程序" << std::endl;

			int flag;
			std::cin >> flag;
			if (flag == 0)
			{
				system("pause");
				return 0;
			}

			switch (flag)
			{
			case 1:
				single.print();
				break;
			case 2:
				QGForwardList::ElemType first;
				single.front(first);
				std::cout << "第一个元素为：" << first << std::endl;
				break;
			case 3:
				QGForwardList::ElemType last;
				single.back(last);
				std::cout << "最后一个元素为：" << last << std::endl;
				break;
			case 4:
				QGForwardList::ElemType e;
				std::cout << "\n请输入要插入的数据:";
				std::cin >> e;

				unsigned int index;
				std::cout << "请输入该数据要插入到第几节点后:";
				std::cin >> index;
				single.insert(index, e);

				std::cout << "新的链表：" << std::endl;
				single.print();
				break;
			case 5:
				std::cout << "\n请输入要删除第几节点：";
				std::cin >> index;
				single.erase(index);

				std::cout << "新的链表：" << std::endl;
				single.print();
				break;
			case 6:
				std::cout << "\n请输入要查找的元素：";
				std::cin >> e;
				single.contain(e);
				break;
			case 7:
				single.clear();
				std::cout << "\n链表已清空！" << std::endl;
				break;
			case 8:
				std::cout << "\n链表长度为：" << single.size() << std::endl;
				break;
			case 9:
				single.reverse();
				std::cout << "新的链表：" << std::endl;
				single.print();
				break;
			case 10:
				single.isLoop();
				break;
			case 11:
				void(*visit)(QGForwardList::ElemType& e);

				std::cout << "\n请输入要执行的函数:" << std::endl;
				std::cout << "1.链表求和" << std::endl;
				std::cout << "(输入不是上面的功能将返回上一级)" << std::endl;
				int a;
				std::cin >> a;
				if (a == 1)
				{
					visit = &Listsum1;
					single.traverse(visit);
					std::cout << "链表所有元素的和为：" << sum1 << std::endl;
				}
				break;
			case 12:
				QGForwardList::ElemType middle;
				single.middleElem(middle);
				std::cout << "中间节点的值为:" << middle << std::endl;
				break;
			default:
				std::cout << "未找到该功能，请重新选择！" << std::endl;
				break;
			}
		}
	}
	if (a == 2)
	{
		std::cout << std::endl;
		std::cout << "请输入链表的节点个数:";
		int n;
		std::cin >> n;
		QGList dual;
		dual.setList(n);
		std::cout << "链表已生成！" << std::endl;
		if (n == 0)
		{
			std::cout << "警告：链表为空，以下功能很可能会出错！" << std::endl;
		}

		while (1)
		{
			std::cout << std::endl;
			std::cout << "请选择想要的功能：" << std::endl;
			std::cout << "1.打印链表\t2.返回第一个元素\t3.返回最后一个元素" << std::endl;
			std::cout << "4.插入元素\t5.删除元素\t\t6.查找元素" << std::endl;
			std::cout << "7.清空链表\t8.链表长度\t\t9.调用函数" << std::endl;
			std::cout << "0.退出程序" << std::endl;

			int flag;
			std::cin >> flag;
			if (flag == 0)
			{
				system("pause");
				return 0;
			}

			switch (flag)
			{
			case 1:
				dual.print();
				break;
			case 2:
				QGList::ElemType first;
				dual.front(first);
				std::cout << "第一个元素为：" << first << std::endl;
				break;
			case 3:
				QGList::ElemType last;
				dual.back(last);
				std::cout << "最后一个元素为：" << last << std::endl;
				break;
			case 4:
				QGList::ElemType e;
				std::cout << "\n请输入要插入的数据:";
				std::cin >> e;

				unsigned int index;
				std::cout << "请输入该数据要插入到第几节点后:";
				std::cin >> index;
				dual.insert(index, e);

				std::cout << "新的链表：" << std::endl;
				dual.print();
				break;
			case 5:
				std::cout << "\n请输入要删除第几节点：";
				std::cin >> index;
				dual.erase(index);

				std::cout << "新的链表：" << std::endl;
				dual.print();
				break;
			case 6:
				std::cout << "\n请输入要查找的元素：";
				std::cin >> e;
				dual.contain(e);
				break;
			case 7:
				dual.clear();
				std::cout << "\n链表已清空！" << std::endl;
				break;
			case 8:
				std::cout << "\n链表长度为：" << dual.size() << std::endl;
				break;
			case 9:
				void(*visit)(QGList::ElemType& e);

				std::cout << "\n请输入要执行的函数:" << std::endl;
				std::cout << "1.链表求和" << std::endl;
				std::cout << "(输入不是上面的功能将返回上一级)" << std::endl;
				int a;
				std::cin >> a;
				if (a == 1)
				{
					visit = &Listsum2;
					dual.traverse(visit);
					std::cout << "链表所有元素的和为：" << sum2 << std::endl;
				}
				break;
			default:
				std::cout << "未找到该功能，请重新选择！" << std::endl;
				break;
			}
		}
	}

	system("pause");
	return 0;
}
