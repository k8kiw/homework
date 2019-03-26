#pragma once
/**
* ����ʱ��: 2019��3��22��20:34:46
* ����:	�¼���
**/


/*
* ��������
*/
class QGForwardList {

public:
	typedef int ElemType;

protected:
	struct Node {
		ElemType data;
		struct Node *next;
	};

	Node* head;
	Node* tail;


public:

	/*
	* ��ʼ������
	*/
	QGForwardList();

	/*
	* ��������
	*/
	~QGForwardList();

	/*
	* ������ֵ
	*/
	void setList(int n);

	/*
	* ��ӡ����
	*/
	bool print();

	/*
	* ���������е�һ��Ԫ�ص�����
	*/
	bool front(ElemType& e);

	/*
	* �������������һ��Ԫ�ص�����
	*/
	bool back(ElemType& e);

	/*
	* �������һ��Ԫ��ǰ���Ԫ��e
	*/
	bool push_front(ElemType& e);

	/*
	* ɾ�������һ��Ԫ��
	*/
	bool pop_front();

	/*
	* ���������һ��Ԫ�غ����Ԫ��e
	*/
	bool push_back(ElemType& e);

	/*
	* ɾ���������һ��Ԫ��
	*/
	bool pop_back();

	/*
	* ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	*/
	bool insert(unsigned int index, ElemType& e);

	/*
	* ɾ������λ��Ԫ��
	*/
	bool erase(unsigned int index);

	/*
	* �������
	*/
	bool clear();

	/*
	* ����Ԫ���Ƿ����
	*/
	bool contain(ElemType& e);

	/*
	* ����������Ԫ�ص�����
	*/
	unsigned int size();

	/*
	* ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	*/
	bool traverse(void(*visit)(ElemType& e));

	/*
	* ��ת����1234��ת����4321
	*/
	bool reverse();

	/*
	* �����л�
	*/
	bool isLoop();

	/*
	* ż�ڵ㷴ת��1234��ת����2143
	*/
	bool reverseEven();

	/*
	* �����м�ڵ�
	*/
	bool middleElem(ElemType& e);
};


