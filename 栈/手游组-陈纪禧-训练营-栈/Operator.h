#pragma once

/*
�������
*/
class Operator	
{
protected:
	char ch;		//�����
	int priority;	//���ȼ�
public:
	void setch(char c);	
	char getch();
	void pri();			//�������ȼ�
	int getpri();		//�������ȼ�
	bool isOperator();	//�ַ��Ϸ��ж�
};