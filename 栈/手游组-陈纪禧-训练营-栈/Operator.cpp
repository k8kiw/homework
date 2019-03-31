#include "Operator.h"

void Operator::setch(char c)
{
	ch = c;
}

char Operator::getch()
{
	return ch;
}

void Operator::pri()
{
	if (isOperator() == true)
	{
		switch (ch)
		{
		case '.':
			priority = 5;
			break;
		case '^':
			priority = 4;
			break;
		case '*':
		case '/':
		case '%':
			priority = 3;
			break;
		case '+':
		case '-':
			priority = 2;
			break;
		case '(':
			priority = 1;
			break;
		default:
			priority = 0;
			break;
		}
	}
}

int Operator::getpri()
{
	return priority;
}

bool Operator::isOperator()
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' \
		|| ch == '.' || ch == '(' || ch == ')')
	{
		return true;
	}
	else
	{
		return false;
	}
}
