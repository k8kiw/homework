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
	std::cout << "��ѡ��Ҫ����������" << std::endl;
	std::cout << "1.������\t2.˫����\t0.�˳�����" << std::endl;
	int a;
	std::cin >> a;
	while (a != 1 && a != 2 && a != 0)
	{
		std::cout << "�������������ѡ��" << std::endl;
		std::cout << "1.������\t2.˫����\t0.�˳�����" << std::endl;
		std::cin >> a;
	}
	if (a == 0)
	{
		system("pause");
		return 0;
	}
	if (a == 1)		//������
	{
		std::cout << std::endl;
		std::cout << "����������Ľڵ����:";
		int n;
		std::cin >> n;
		QGForwardList single;
		single.setList(n);
		std::cout << "���������ɣ�" << std::endl;
		if (n == 0)
		{
			std::cout << "���棺����Ϊ�գ����¹��ܺܿ��ܻ����" << std::endl;
		}
		
		while (1)
		{
			std::cout << std::endl;
			std::cout << "��ѡ����Ҫ�Ĺ��ܣ�" << std::endl;
			std::cout << "1.��ӡ����\t2.���ص�һ��Ԫ��\t3.�������һ��Ԫ��" << std::endl;
			std::cout << "4.����Ԫ��\t5.ɾ��Ԫ��\t\t6.����Ԫ��" << std::endl;
			std::cout << "7.�������\t8.������\t\t9.����ת" << std::endl;
			std::cout << "10.�����л�\t11.���ú���\t\t12.�����м�ڵ�" << std::endl;
			std::cout << "0.�˳�����" << std::endl;

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
				std::cout << "��һ��Ԫ��Ϊ��" << first << std::endl;
				break;
			case 3:
				QGForwardList::ElemType last;
				single.back(last);
				std::cout << "���һ��Ԫ��Ϊ��" << last << std::endl;
				break;
			case 4:
				QGForwardList::ElemType e;
				std::cout << "\n������Ҫ���������:";
				std::cin >> e;

				unsigned int index;
				std::cout << "�����������Ҫ���뵽�ڼ��ڵ��:";
				std::cin >> index;
				single.insert(index, e);

				std::cout << "�µ�����" << std::endl;
				single.print();
				break;
			case 5:
				std::cout << "\n������Ҫɾ���ڼ��ڵ㣺";
				std::cin >> index;
				single.erase(index);

				std::cout << "�µ�����" << std::endl;
				single.print();
				break;
			case 6:
				std::cout << "\n������Ҫ���ҵ�Ԫ�أ�";
				std::cin >> e;
				single.contain(e);
				break;
			case 7:
				single.clear();
				std::cout << "\n��������գ�" << std::endl;
				break;
			case 8:
				std::cout << "\n������Ϊ��" << single.size() << std::endl;
				break;
			case 9:
				single.reverse();
				std::cout << "�µ�����" << std::endl;
				single.print();
				break;
			case 10:
				single.isLoop();
				break;
			case 11:
				void(*visit)(QGForwardList::ElemType& e);

				std::cout << "\n������Ҫִ�еĺ���:" << std::endl;
				std::cout << "1.�������" << std::endl;
				std::cout << "(���벻������Ĺ��ܽ�������һ��)" << std::endl;
				int a;
				std::cin >> a;
				if (a == 1)
				{
					visit = &Listsum1;
					single.traverse(visit);
					std::cout << "��������Ԫ�صĺ�Ϊ��" << sum1 << std::endl;
				}
				break;
			case 12:
				QGForwardList::ElemType middle;
				single.middleElem(middle);
				std::cout << "�м�ڵ��ֵΪ:" << middle << std::endl;
				break;
			default:
				std::cout << "δ�ҵ��ù��ܣ�������ѡ��" << std::endl;
				break;
			}
		}
	}
	if (a == 2)
	{
		std::cout << std::endl;
		std::cout << "����������Ľڵ����:";
		int n;
		std::cin >> n;
		QGList dual;
		dual.setList(n);
		std::cout << "���������ɣ�" << std::endl;
		if (n == 0)
		{
			std::cout << "���棺����Ϊ�գ����¹��ܺܿ��ܻ����" << std::endl;
		}

		while (1)
		{
			std::cout << std::endl;
			std::cout << "��ѡ����Ҫ�Ĺ��ܣ�" << std::endl;
			std::cout << "1.��ӡ����\t2.���ص�һ��Ԫ��\t3.�������һ��Ԫ��" << std::endl;
			std::cout << "4.����Ԫ��\t5.ɾ��Ԫ��\t\t6.����Ԫ��" << std::endl;
			std::cout << "7.�������\t8.������\t\t9.���ú���" << std::endl;
			std::cout << "0.�˳�����" << std::endl;

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
				std::cout << "��һ��Ԫ��Ϊ��" << first << std::endl;
				break;
			case 3:
				QGList::ElemType last;
				dual.back(last);
				std::cout << "���һ��Ԫ��Ϊ��" << last << std::endl;
				break;
			case 4:
				QGList::ElemType e;
				std::cout << "\n������Ҫ���������:";
				std::cin >> e;

				unsigned int index;
				std::cout << "�����������Ҫ���뵽�ڼ��ڵ��:";
				std::cin >> index;
				dual.insert(index, e);

				std::cout << "�µ�����" << std::endl;
				dual.print();
				break;
			case 5:
				std::cout << "\n������Ҫɾ���ڼ��ڵ㣺";
				std::cin >> index;
				dual.erase(index);

				std::cout << "�µ�����" << std::endl;
				dual.print();
				break;
			case 6:
				std::cout << "\n������Ҫ���ҵ�Ԫ�أ�";
				std::cin >> e;
				dual.contain(e);
				break;
			case 7:
				dual.clear();
				std::cout << "\n��������գ�" << std::endl;
				break;
			case 8:
				std::cout << "\n������Ϊ��" << dual.size() << std::endl;
				break;
			case 9:
				void(*visit)(QGList::ElemType& e);

				std::cout << "\n������Ҫִ�еĺ���:" << std::endl;
				std::cout << "1.�������" << std::endl;
				std::cout << "(���벻������Ĺ��ܽ�������һ��)" << std::endl;
				int a;
				std::cin >> a;
				if (a == 1)
				{
					visit = &Listsum2;
					dual.traverse(visit);
					std::cout << "��������Ԫ�صĺ�Ϊ��" << sum2 << std::endl;
				}
				break;
			default:
				std::cout << "δ�ҵ��ù��ܣ�������ѡ��" << std::endl;
				break;
			}
		}
	}

	system("pause");
	return 0;
}
