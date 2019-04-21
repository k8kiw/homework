#pragma once
#include <iostream>
#include "BinaryTree.h"
#define N 1000


class Calculator
{
protected:
	char str1[N];		//中缀
	char str2[N];		//前缀
	double result;

public:
	//构造
	Calculator();

	bool isLegal(char input[]);		//表达式合法性判断
	void getstr1(char input[]);		//得到中缀表达式
	void trans();					//中缀转前缀
	bool cal();						//计算前缀表达式
};