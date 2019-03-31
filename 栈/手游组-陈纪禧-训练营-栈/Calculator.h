#pragma once

#define N 1000

class Calculator
{
protected:
	char str1[N];		//中缀
	char str2[N];		//后缀
	double result;
public:
	Calculator();
	bool isLegal(char input[]);		//表达式合法性判断
	void getstr1(char input[]);	//得到中缀表达式
	void trans();				//中缀转后缀
	bool cal();					//计算后缀表达式
};