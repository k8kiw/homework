#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Calculator.h"
#define N 1000

int main()
{
	int F;
	do {
		std::cout << "1.��\t2.������" << std::endl;
		std::cin >> F;
	} while (F != 1 && F != 2);
	std::cin.ignore(100, '\n');

	if (F == 1)
	{
		BinaryTree<char> t;
		BiNode<char>* root = t.getRoot();
		std::cout << "����������һ����(����Ϊ#)" << std::endl;
		t.Create(root);

		void(*visit)(char e);
		visit = &(t.print);

		std::cout << "����ݹ����:";
		t.PreOrderTraverse(root, visit);
		std::cout << std::endl;
		std::cout << "�����������:";
		t.PreOrderTraverse_Stack(root, visit);
		std::cout << std::endl;

		std::cout << "����ݹ����:";
		t.InOrderTraverse(root, visit);
		std::cout << std::endl;
		std::cout << "�����������:";
		t.InOrderTraverse_Stack(root, visit);
		std::cout << std::endl;

		std::cout << "����ݹ����:";
		t.PostOrderTraverse(root, visit);
		std::cout << std::endl;
		std::cout << "�����������:";
		t.PostOrderTraverse_Stack(root, visit);
		std::cout << std::endl;

		std::cout << "��α���:";
		t.LevelOrderTraverse(root, visit);
		std::cout << std::endl;
	}
	else
	{
		while (1)
		{
			char input[N];
			Calculator calc;
			std::cout << "\n������һ����׺���ʽ��" << std::endl;
			std::cin.getline(input, N);
			if (calc.isLegal(input) == true)
			{
				calc.getstr1(input);

				calc.trans();
				calc.cal();
			}
			else
			{
				std::cerr << "���ʽ�Ƿ�������������!" << std::endl;
			}
		}
	}

	system("pause");
	return 0;
}