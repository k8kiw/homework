#pragma once

/*
运算符类
*/
class Operator	
{
protected:
	char ch;		//运算符
	int priority;	//优先级
public:
	void setch(char c);	
	char getch();
	void pri();			//计算优先级
	int getpri();		//返回优先级
	bool isOperator();	//字符合法判断
};