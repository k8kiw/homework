#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "linkStack.h"
#include "Calculator.h"
#include "Operator.h"


Calculator::Calculator()
{
	result = 0;
}

bool Calculator::isLegal(char input[])
{
	if (strlen(input) == 0)
		return false;

	int left = 0, right = 0;		//判断左右括号

	for (unsigned int i = 0; i < strlen(input); i++)		//遍历
	{
		if (input[i] >= '0' && input[i] <= '9')	//数字跳过
		{
			continue;
		}
		else
		{
			Operator x;
			x.setch(input[i]);
			if (x.isOperator() == true)
			{
				/*后面为数字的运算符*/
				if (i != strlen(input) - 1 && (input[i + 1] >= '0' && input[i + 1] <= '9' || input[i + 1] == '('))
				{
					/*加减*/
					if (input[i] == '+' || input[i] == '-')
					{
						if (i == 0 || input[i - 1] >= '0' && input[i - 1] <= '9')	//正负号或运算符
						{
							continue;
						}
						else if (input[i - 1] == '(' || input[i - 1] == ')')
						{
							continue;
						}
						else
						{
							return false;
						}
					}

					/*乘除幂模*/
					if (input[i] == '*' || input[i] == '/' && input[i + 1] != '0'\
						|| input[i] == '^' || input[i] == '%' && input[i + 1] != '0')
					{
						if (i != 0 && input[i - 1] >= '0' && input[i - 1] <= '9')	//前面是数字
						{
							continue;
						}
						else if (input[i - 1] == ')')	//括号
						{
							continue;
						}
						else
						{
							return false;
						}
					}

					/*点，前面为数字*/
					if (input[i] == '.')
					{
						if (i != 0 && input[i - 1] >= '0' && input[i - 1] <= '9')
						{
							continue;
						}
						else
						{
							return false;
						}
					}

					/*左括号*/
					if (input[i] == '(')
					{
						left++;
						if (i == 0)
						{
							continue;
						}
						else if (input[i - 1] == '+' || input[i - 1] == '-'\
							|| input[i - 1] == '*' || input[i - 1] == '/'\
							|| input[i - 1] == '^' || input[i - 1] == '%'\
							|| input[i - 1] == '(')
						{
							continue;
						}
						else
						{
							return false;
						}
					}

					/*右括号错误,因为后面为数字*/
					if (input[i] == ')')
					{
						return false;
					}
				}
				else if (input[i] == '(')	//后面不是数字的情况
				{
					left++;
					if (i == 0)
					{
						continue;
					}
					else if (input[i - 1] == '+' || input[i - 1] == '-'\
						|| input[i - 1] == '*' || input[i - 1] == '/'\
						|| input[i - 1] == '^' || input[i - 1] == '%'\
						|| input[i - 1] == '(')
					{
						continue;
					}
					else
					{
						return false;
					}
				}
				else if (input[i] == ')')
				{
					right++;
					if (i != 0 && (input[i - 1] >= '0' && input[i - 1] <= '9' || input[i - 1] == ')' || input[i - 1] == '(') )
					{
						continue;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	
	if (left == right)
		return true;
	else
		return false;
}

void Calculator::getstr1(char input[])
{
	strcpy_s(str1,input);
}

void Calculator::trans()
{
	Operator x[N];

	if (str1[0] == '-')
		x[0].setch('0');
	for (unsigned int i = 0; i <= strlen(str1); i++)
	{
		if (str1[0] == '-')
		{
			x[i + 1].setch(str1[i]);
		}
		else
		{
			x[i].setch(str1[i]);
		}
	}
	linkStack<char> op;		//转后缀时存放运算符的栈

	int i, j;
	for (i = 0, j = 0; x[i].getch() != '\0'; i++)	//将(-(...))的情况处理为(0-(...))
	{
		if (i != 0 && x[i].getch() == '-' && x[i - 1].getch() == '(' && x[i + 1].getch() == '(')
		{
			for (j = i + 1; x[j].getch() != '\0'; j++)
			{
				
			}	//使j指向最后
			for (; j >= i; j--)
			{
				x[j + 1] = x[j];
			}

			x[i].setch('0');
		}
	}

	/*开始转换*/
	for (i = 0, j = 0; x[i].getch() != '\0'; i++)
	{
		//负号处理,在前加~
		if (x[i].getch() == '-' &&  x[i - 1].getch() == '(')
		{	
			str2[j++] = '~';
			continue;
		}

		//正号处理,略过
		if (x[i].getch() == '+' && (i == 0 || x[i - 1].getch() == '('))
		{
			continue;
		}

		//数字或小数点直接输出到后缀
		if (x[i].getch() >= '0' && x[i].getch() <= '9' || x[i].getch() == '.')
		{
			str2[j++] = x[i].getch();
			continue;
		}

		//运算符处理
		if (x[i].isOperator() == true)
		{
			if (op.empty() == true || x[i].getch() == '(')	//栈为空或左括号直接入栈
			{
				op.push(x[i].getch());
				str2[j++] = ' ';
				continue;
			}

			if (x[i].getch() == ')')		//右括号
			{
				char t;
				op.top(t);		//取得栈顶运算符

				while (t != '(')
				{
					op.pop(str2[j]);	//出栈赋值给str2
					j++;
					op.top(t);		//取得栈顶运算符
				}

				op.pop();	//删掉左括号
				continue;
			}

			char t_temp;
			op.top(t_temp);		//取得栈顶的运算符(栈已经非空)

			Operator temp;	
			temp.setch(t_temp);	//将栈顶的运算符赋给temp对象(temp与x[i]比较)

			temp.pri();		//栈顶优先级
			x[i].pri();		//当前运算符优先级

			if ( x[i].getpri() > temp.getpri() )	//当前的优先级大
			{
				op.push( x[i].getch() );
				str2[j++] = ' ';
			}
			else	//优先级小
			{
				char t;
				op.top(t);		//取得栈顶

				Operator Top;	//栈顶赋给运算符类
				Top.setch(t);
				Top.pri();

				do
				{
					op.pop(str2[j]);	//出栈赋值给str2
					j++;

					if (op.empty() != true)
					{
						op.top(t);		//取得新栈顶
						Top.setch(t);
						Top.pri();
					}
					else
					{
						break;
					}

				}while ( x[i].getpri() <= Top.getpri());	//小于等于栈顶优先级

				op.push(x[i].getch());	//压栈
				str2[j++] = ' ';
			}
		}
	}

	/*输出栈中剩余元素*/
	while (op.empty() != true)
	{
		char t;
		op.top(t);		//取得栈顶运算符

		op.pop(str2[j]);	//出栈赋值给str2
		j++;
	}

	str2[j] = '\0';
	
	//std::cout << str2 << std::endl;
}

bool Calculator::cal()
{
	linkStack<double> Num;	//存放数字的栈
	double a, b, c;			//a，b为从栈中提出的数，c为它们计算的结果
	char num[N];			//提取出数字字符串，用于转成浮点型
	double result;			//字符转成浮点型后的数字
	int sign = 1;			//符号位

	int i, j;
	for (i = 0, j = 0; str2[i] != '\0'; i++)
	{
		switch (str2[i])	//case处理负号，default处理数字
		{
		case '+':
			Num.pop(a);		//取数
			Num.pop(b);
			c = b + a;		//计算
			Num.push(c);	//压栈
			break;

		case '-':
			Num.pop(a);		//取数
			Num.pop(b);
			c = b - a;		//计算
			Num.push(c);	//压栈
			break;

		case '*':
			Num.pop(a);		//取数
			Num.pop(b);
			c = b * a;		//计算
			Num.push(c);	//压栈
			break;

		case '/':
			Num.pop(a);		//取数
			Num.pop(b);
			c = b / a;		//计算,分母不为0已在合法性判断完毕
			Num.push(c);	//压栈
			break;

		case '^':
			Num.pop(a);		//取数
			Num.pop(b);
			c = pow(b, a);	//计算
			Num.push(c);	//压栈
			break;

		case '%':
			Num.pop(a);		//取数
			Num.pop(b);
			c = fmod(b, a);	//浮点数取模
			Num.push(c);	//压栈
			break;

		case '~':	//负号处理
			sign = -1;
			break;

		case ' ':
			break;

		default:
			result = 0;		//重置结果

			int flag = 0;
			while (str2[i] >= '0' && str2[i] <= '9' || str2[i] == '.')	//将一个数合成一个字符串
			{
				num[j++] = str2[i];
				if (str2[i] == '.')
					flag++;
				i++;
			}
			num[j] = '\0';
			j = 0;			//重置数字字符串
			i--;	//避免因为i++了两次造成的bug

			if (flag <= 1)
			{
				result = strtod(num, NULL);		//字符串转浮点
			}
			else
			{
				std::cerr << "小数点过多" << std::endl;
				return false;
			}

			result *= sign;
			sign = 1;		//符号位重置

			Num.push(result);
			break;
		}
	}

	Num.top(result);
	this->result = result;

	std::cout << "计算结果为：" << this->result << std::endl;
	return true;
}

