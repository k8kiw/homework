#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>

extern int T;	

void InitLQueue(LQueue * Q)
{
	Node *p = malloc(sizeof(Node));
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	Q->length = 0;
}

void DestoryLQueue(LQueue * Q)
{
	ClearLQueue(Q);
	Q->length = 0;

	free(Q->front);
	Q->front = NULL;
	Q->rear = NULL;
}

Status IsEmptyLQueue(const LQueue * Q)
{
	if (Q->front == Q->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status GetHeadLQueue(LQueue * Q, void * e)
{
	if (IsEmptyLQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	else
	{
		e = Q->front->next->data;
		return TRUE;
	}
}

int LengthLQueue(LQueue * Q)
{
	return Q->length;
}

Status EnLQueue(LQueue * Q, void * data)
{
	Node *p = malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("入列失败！\n");
		return FALSE;
	}
	p->next = NULL;
	p->data = data;

	//连接
	Q->rear->next = p;
	Q->rear = p;

	Q->length++;

	return TRUE;
}

Status DeLQueue(LQueue * Q)
{
	if (IsEmptyLQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	Node *p;
	p = Q->front->next;			//指向队首(要删除的)

	Q->front->next = p->next;	//原队首的下一个为新队首

	if (Q->rear == p)			//要删除的为队尾
	{
		Q->rear = Q->front;		//队尾指向头节点
	}

	free(p);
	p = NULL;
	Q->length--;

	return TRUE;
}

void ClearLQueue(LQueue * Q)
{
	Node *pre = Q->front->next;
	Node *current;
	while (pre != NULL)
	{
		current = pre->next;
		free(pre);
		pre = current;
	}
	Q->rear = Q->front;
	pre = NULL;
	current = NULL;
}

Status TraverseLQueue(const LQueue * Q, void(*foo)(void *q))
{
	if (IsEmptyLQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	Node *p = Q->front->next;

	while (p != NULL)
	{
		(*foo)(p->data);
		p = p->next;
	}

	return TRUE;
}

void LPrint(void * q)
{
	switch (T)
	{
	case 1:
		printf("%d\n",  *((int *)q));
		break;
	case 2:
		printf("%f\n", *((double *)q));
		break;
	case 3:
		printf("%c\n", *((char *)q));
		break;
	case 4:
		printf("%s\n", (char *)q);
		break;
	}
}
