#include "main.h"
#define N 1000

int main()
{

	while (1)
	{
		char input[N];
		Calculator calc;
		std::cout << "\n������һ����׺���ʽ��" << std::endl;
		std::cin.getline(input,N);
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

	system("pause");
	return 0;
}