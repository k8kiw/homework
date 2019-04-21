#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include "Calculator.h"
#include "BinaryTree.h"
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
					if (i != 0 && (input[i - 1] >= '0' && input[i - 1] <= '9' || input[i - 1] == ')' || input[i - 1] == '('))
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
	strcpy_s(str1, input);
}

void Calculator::trans()
{
	std::stack<char> stk; // 操作符栈
	int j = 0;	//str2下标
	for (int i = (int)strlen(str1) - 1; i >= 0; --i) // 从右到左扫描
	{
		Operator x;
		x.setch(str1[i]);
		if (str1[i] >= '0' && str1[i] <= '9' || str1[i] == '.') // 如果是数字
		{
			str2[j++] = str1[i];
		}
		else // 如果是操作符
		{
			if (str1[i - 1] >= '0' && str1[i - 1] <= '9')
				str2[j++] = ' ';
			if (str1[i] == ')') // 如果是右括号，则直接入栈
			{
				stk.push(str1[i]);
			}
			else if (str1[i] == '(') // 如果是左括号
			{
				// 依次弹出栈中的操作符，直至遇到右括号
				while (!stk.empty())
				{
					if (stk.top() == ')')
					{
						stk.pop();
						break;
					}
					else
					{
						str2[j++] = stk.top();
						stk.pop();
					}
				}
			}
			else // 如果是其他操作符
			{
				if (stk.empty())
				{
					stk.push(str1[i]);
					continue;
				}

				Operator temp;		//栈顶与当前运算符
				Operator x;
				temp.setch(stk.top());
				x.setch(str1[i]);
				temp.pri();
				x.pri();

				while (!stk.empty() && stk.top() != ')' && temp.getpri() > x.getpri()) // 栈顶操作符优先级大于当前操作符优先级
				{
					str2[j++] = stk.top();
					stk.pop();
				}
				// 将当前操作符入栈
				stk.push(str1[i]);
			}
		}
	}

	// 检测操作符栈是否为空
	while (!stk.empty())
	{
		str2[j++] = stk.top();
		stk.pop();
	}
	str2[j] = '\0';

	// 将str2翻转
	int head = 0;
	int tail = j - 1;
	char temp;
	while (head < tail)
	{
		temp = str2[head];
		str2[head] = str2[tail];
		str2[tail] = temp;
		head++;
		tail--;
	}
	
	std::cout << str2 << std::endl;
}

bool Calculator::cal()
{
	std::stack<double> Num;	//存放数字的栈
	double a, b, c;			//a，b为从栈中提出的数，c为它们计算的结果
	char num[N];			//提取出数字字符串，用于转成浮点型
	double result;			//字符转成浮点型后的数字

	int i, j;
	for (i = (int)strlen(str2) - 1, j = 0; i >= 0; --i)
	{
		switch (str2[i])	
		{
		case '+':
			a = Num.top();	//取数
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a + b;		//计算
			Num.push(c);	//压栈
			break;

		case '-':
			a = Num.top();	//取数
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a - b;		//计算
			Num.push(c);	//压栈
			break;

		case '*':
			a = Num.top();	//取数
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a * b;		//计算
			Num.push(c);	//压栈
			break;

		case '/':
			a = Num.top();	//取数
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a / b;		//计算,分母不为0已在合法性判断完毕
			Num.push(c);	//压栈
			break;

		case '^':
			a = Num.top();	//取数
			Num.pop();
			b = Num.top();
			Num.pop();

			c = pow(a, b);	//计算
			Num.push(c);	//压栈
			break;

		case '%':
			a = Num.top();	//取数
			Num.pop();
			b = Num.top();
			Num.pop();

			c = fmod(a, b);	//浮点数取模
			Num.push(c);	//压栈
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
				--i;
			}
			num[j] = '\0';
			i++;	//避免因为i--了两次造成的bug

			//反转num
			int head = 0;
			int tail = j - 1;
			char temp;
			while (head < tail)
			{
				temp = num[head];
				num[head] = num[tail];
				num[tail] = temp;
				head++;
				tail--;
			}
			j = 0;

			if (flag <= 1)
			{
				result = strtod(num, NULL);		//字符串转浮点
			}
			else
			{
				std::cerr << "小数点过多" << std::endl;
				return false;
			}

			Num.push(result);
			break;
		}
	}

	result = Num.top();
	this->result = result;

	std::cout << "计算结果为：" << this->result << std::endl;
	return true;
}
