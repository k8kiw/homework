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
	linkStack<char> op;		//ת��׺ʱ����������ջ

	int i, j;
	for (i = 0, j = 0; x[i].getch() != '\0'; i++)	//��(-(...))���������Ϊ(0-(...))
	{
		if (i != 0 && x[i].getch() == '-' && x[i - 1].getch() == '(' && x[i + 1].getch() == '(')
		{
			for (j = i + 1; x[j].getch() != '\0'; j++)
			{
				
			}	//ʹjָ�����
			for (; j >= i; j--)
			{
				x[j + 1] = x[j];
			}

			x[i].setch('0');
		}
	}

	/*��ʼת��*/
	for (i = 0, j = 0; x[i].getch() != '\0'; i++)
	{
		//���Ŵ���,��ǰ��~
		if (x[i].getch() == '-' &&  x[i - 1].getch() == '(')
		{	
			str2[j++] = '~';
			continue;
		}

		//���Ŵ���,�Թ�
		if (x[i].getch() == '+' && (i == 0 || x[i - 1].getch() == '('))
		{
			continue;
		}

		//���ֻ�С����ֱ���������׺
		if (x[i].getch() >= '0' && x[i].getch() <= '9' || x[i].getch() == '.')
		{
			str2[j++] = x[i].getch();
			continue;
		}

		//���������
		if (x[i].isOperator() == true)
		{
			if (op.empty() == true || x[i].getch() == '(')	//ջΪ�ջ�������ֱ����ջ
			{
				op.push(x[i].getch());
				str2[j++] = ' ';
				continue;
			}

			if (x[i].getch() == ')')		//������
			{
				char t;
				op.top(t);		//ȡ��ջ�������

				while (t != '(')
				{
					op.pop(str2[j]);	//��ջ��ֵ��str2
					j++;
					op.top(t);		//ȡ��ջ�������
				}

				op.pop();	//ɾ��������
				continue;
			}

			char t_temp;
			op.top(t_temp);		//ȡ��ջ���������(ջ�Ѿ��ǿ�)

			Operator temp;	
			temp.setch(t_temp);	//��ջ�������������temp����(temp��x[i]�Ƚ�)

			temp.pri();		//ջ�����ȼ�
			x[i].pri();		//��ǰ��������ȼ�

			if ( x[i].getpri() > temp.getpri() )	//��ǰ�����ȼ���
			{
				op.push( x[i].getch() );
				str2[j++] = ' ';
			}
			else	//���ȼ�С
			{
				char t;
				op.top(t);		//ȡ��ջ��

				Operator Top;	//ջ�������������
				Top.setch(t);
				Top.pri();

				do
				{
					op.pop(str2[j]);	//��ջ��ֵ��str2
					j++;

					if (op.empty() != true)
					{
						op.top(t);		//ȡ����ջ��
						Top.setch(t);
						Top.pri();
					}
					else
					{
						break;
					}

				}while ( x[i].getpri() <= Top.getpri());	//С�ڵ���ջ�����ȼ�

				op.push(x[i].getch());	//ѹջ
				str2[j++] = ' ';
			}
		}
	}

	/*���ջ��ʣ��Ԫ��*/
	while (op.empty() != true)
	{
		char t;
		op.top(t);		//ȡ��ջ�������

		op.pop(str2[j]);	//��ջ��ֵ��str2
		j++;
	}

	str2[j] = '\0';
	
	//std::cout << str2 << std::endl;
}

bool Calculator::cal()
{
	linkStack<double> Num;	//������ֵ�ջ
	double a, b, c;			//a��bΪ��ջ�����������cΪ���Ǽ���Ľ��
	char num[N];			//��ȡ�������ַ���������ת�ɸ�����
	double result;			//�ַ�ת�ɸ����ͺ������
	int sign = 1;			//����λ

	int i, j;
	for (i = 0, j = 0; str2[i] != '\0'; i++)
	{
		switch (str2[i])	//case�����ţ�default��������
		{
		case '+':
			Num.pop(a);		//ȡ��
			Num.pop(b);
			c = b + a;		//����
			Num.push(c);	//ѹջ
			break;

		case '-':
			Num.pop(a);		//ȡ��
			Num.pop(b);
			c = b - a;		//����
			Num.push(c);	//ѹջ
			break;

		case '*':
			Num.pop(a);		//ȡ��
			Num.pop(b);
			c = b * a;		//����
			Num.push(c);	//ѹջ
			break;

		case '/':
			Num.pop(a);		//ȡ��
			Num.pop(b);
			c = b / a;		//����,��ĸ��Ϊ0���ںϷ����ж����
			Num.push(c);	//ѹջ
			break;

		case '^':
			Num.pop(a);		//ȡ��
			Num.pop(b);
			c = pow(b, a);	//����
			Num.push(c);	//ѹջ
			break;

		case '%':
			Num.pop(a);		//ȡ��
			Num.pop(b);
			c = fmod(b, a);	//������ȡģ
			Num.push(c);	//ѹջ
			break;

		case '~':	//���Ŵ���
			sign = -1;
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
				i++;
			}
			num[j] = '\0';
			j = 0;			//���������ַ���
			i--;	//������Ϊi++��������ɵ�bug

			if (flag <= 1)
			{
				result = strtod(num, NULL);		//�ַ���ת����
			}
			else
			{
				std::cerr << "С�������" << std::endl;
				return false;
			}

			result *= sign;
			sign = 1;		//����λ����

			Num.push(result);
			break;
		}
	}

	Num.top(result);
	this->result = result;

	std::cout << "������Ϊ��" << this->result << std::endl;
	return true;
}

