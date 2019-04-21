#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Calculator.h"
#define N 1000

int main()
{
	int F;
	do {
		std::cout << "1.树\t2.计算器" << std::endl;
		std::cin >> F;
	} while (F != 1 && F != 2);
	std::cin.ignore(100, '\n');

	if (F == 1)
	{
		BinaryTree<char> t;
		BiNode<char>* root = t.getRoot();
		std::cout << "以先序输入一棵树(空树为#)" << std::endl;
		t.Create(root);

		void(*visit)(char e);
		visit = &(t.print);

		std::cout << "先序递归遍历:";
		t.PreOrderTraverse(root, visit);
		std::cout << std::endl;
		std::cout << "先序迭代遍历:";
		t.PreOrderTraverse_Stack(root, visit);
		std::cout << std::endl;

		std::cout << "中序递归遍历:";
		t.InOrderTraverse(root, visit);
		std::cout << std::endl;
		std::cout << "中序迭代遍历:";
		t.InOrderTraverse_Stack(root, visit);
		std::cout << std::endl;

		std::cout << "中序递归遍历:";
		t.PostOrderTraverse(root, visit);
		std::cout << std::endl;
		std::cout << "中序迭代遍历:";
		t.PostOrderTraverse_Stack(root, visit);
		std::cout << std::endl;

		std::cout << "层次遍历:";
		t.LevelOrderTraverse(root, visit);
		std::cout << std::endl;
	}
	else
	{
		while (1)
		{
			char input[N];
			Calculator calc;
			std::cout << "\n请输入一个中缀表达式：" << std::endl;
			std::cin.getline(input, N);
			if (calc.isLegal(input) == true)
			{
				calc.getstr1(input);

				calc.trans();
				calc.cal();
			}
			else
			{
				std::cerr << "表达式非法，请重新输入!" << std::endl;
			}
		}
	}

	system("pause");
	return 0;
}