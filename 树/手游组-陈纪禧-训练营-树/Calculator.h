#pragma once
#include <iostream>
#include "BinaryTree.h"
#define N 1000


class Calculator
{
protected:
	char str1[N];		//��׺
	char str2[N];		//ǰ׺
	double result;

public:
	//����
	Calculator();

	bool isLegal(char input[]);		//���ʽ�Ϸ����ж�
	void getstr1(char input[]);		//�õ���׺���ʽ
	void trans();					//��׺תǰ׺
	bool cal();						//����ǰ׺���ʽ
};