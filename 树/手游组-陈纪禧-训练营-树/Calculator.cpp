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

	int left = 0, right = 0;		//�ж���������

	for (unsigned int i = 0; i < strlen(input); i++)		//����
	{
		if (input[i] >= '0' && input[i] <= '9')	//��������
		{
			continue;
		}
		else
		{
			Operator x;
			x.setch(input[i]);
			if (x.isOperator() == true)
			{
				/*����Ϊ���ֵ������*/
				if (i != strlen(input) - 1 && (input[i + 1] >= '0' && input[i + 1] <= '9' || input[i + 1] == '('))
				{
					/*�Ӽ�*/
					if (input[i] == '+' || input[i] == '-')
					{
						if (i == 0 || input[i - 1] >= '0' && input[i - 1] <= '9')	//�����Ż������
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

					/*�˳���ģ*/
					if (input[i] == '*' || input[i] == '/' && input[i + 1] != '0'\
						|| input[i] == '^' || input[i] == '%' && input[i + 1] != '0')
					{
						if (i != 0 && input[i - 1] >= '0' && input[i - 1] <= '9')	//ǰ��������
						{
							continue;
						}
						else if (input[i - 1] == ')')	//����
						{
							continue;
						}
						else
						{
							return false;
						}
					}

					/*�㣬ǰ��Ϊ����*/
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

					/*������*/
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

					/*�����Ŵ���,��Ϊ����Ϊ����*/
					if (input[i] == ')')
					{
						return false;
					}
				}
				else if (input[i] == '(')	//���治�����ֵ����
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
	std::stack<char> stk; // ������ջ
	int j = 0;	//str2�±�
	for (int i = (int)strlen(str1) - 1; i >= 0; --i) // ���ҵ���ɨ��
	{
		Operator x;
		x.setch(str1[i]);
		if (str1[i] >= '0' && str1[i] <= '9' || str1[i] == '.') // ���������
		{
			str2[j++] = str1[i];
		}
		else // ����ǲ�����
		{
			if (str1[i - 1] >= '0' && str1[i - 1] <= '9')
				str2[j++] = ' ';
			if (str1[i] == ')') // ����������ţ���ֱ����ջ
			{
				stk.push(str1[i]);
			}
			else if (str1[i] == '(') // �����������
			{
				// ���ε���ջ�еĲ�������ֱ������������
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
			else // ���������������
			{
				if (stk.empty())
				{
					stk.push(str1[i]);
					continue;
				}

				Operator temp;		//ջ���뵱ǰ�����
				Operator x;
				temp.setch(stk.top());
				x.setch(str1[i]);
				temp.pri();
				x.pri();

				while (!stk.empty() && stk.top() != ')' && temp.getpri() > x.getpri()) // ջ�����������ȼ����ڵ�ǰ���������ȼ�
				{
					str2[j++] = stk.top();
					stk.pop();
				}
				// ����ǰ��������ջ
				stk.push(str1[i]);
			}
		}
	}

	// ��������ջ�Ƿ�Ϊ��
	while (!stk.empty())
	{
		str2[j++] = stk.top();
		stk.pop();
	}
	str2[j] = '\0';

	// ��str2��ת
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
	std::stack<double> Num;	//������ֵ�ջ
	double a, b, c;			//a��bΪ��ջ�����������cΪ���Ǽ���Ľ��
	char num[N];			//��ȡ�������ַ���������ת�ɸ�����
	double result;			//�ַ�ת�ɸ����ͺ������

	int i, j;
	for (i = (int)strlen(str2) - 1, j = 0; i >= 0; --i)
	{
		switch (str2[i])	
		{
		case '+':
			a = Num.top();	//ȡ��
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a + b;		//����
			Num.push(c);	//ѹջ
			break;

		case '-':
			a = Num.top();	//ȡ��
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a - b;		//����
			Num.push(c);	//ѹջ
			break;

		case '*':
			a = Num.top();	//ȡ��
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a * b;		//����
			Num.push(c);	//ѹջ
			break;

		case '/':
			a = Num.top();	//ȡ��
			Num.pop();
			b = Num.top();
			Num.pop();

			c = a / b;		//����,��ĸ��Ϊ0���ںϷ����ж����
			Num.push(c);	//ѹջ
			break;

		case '^':
			a = Num.top();	//ȡ��
			Num.pop();
			b = Num.top();
			Num.pop();

			c = pow(a, b);	//����
			Num.push(c);	//ѹջ
			break;

		case '%':
			a = Num.top();	//ȡ��
			Num.pop();
			b = Num.top();
			Num.pop();

			c = fmod(a, b);	//������ȡģ
			Num.push(c);	//ѹջ
			break;

		case ' ':
			break;

		default:
			result = 0;		//���ý��

			int flag = 0;
			while (str2[i] >= '0' && str2[i] <= '9' || str2[i] == '.')	//��һ�����ϳ�һ���ַ���
			{
				num[j++] = str2[i];
				if (str2[i] == '.')
					flag++;
				--i;
			}
			num[j] = '\0';
			i++;	//������Ϊi--��������ɵ�bug

			//��תnum
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
				result = strtod(num, NULL);		//�ַ���ת����
			}
			else
			{
				std::cerr << "С�������" << std::endl;
				return false;
			}

			Num.push(result);
			break;
		}
	}

	result = Num.top();
	this->result = result;

	std::cout << "������Ϊ��" << this->result << std::endl;
	return true;
}
