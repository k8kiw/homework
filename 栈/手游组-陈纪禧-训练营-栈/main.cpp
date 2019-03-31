#include "main.h"
#define N 1000

int main()
{

	while (1)
	{
		char input[N];
		Calculator calc;
		std::cout << "\n请输入一个中缀表达式：" << std::endl;
		std::cin.getline(input,N);
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

	system("pause");
	return 0;
}