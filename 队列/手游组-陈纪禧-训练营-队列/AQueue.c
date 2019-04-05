#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>

extern int T;

void InitAQueue(AQueue * Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;	
}

void DestoryAQueue(AQueue * Q)
{
	ClearAQueue(Q);
}

Status IsFullAQueue(const AQueue * Q)
{
	if (Q->length == MAXQUEUE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status IsEmptyAQueue(const AQueue * Q)
{
	if (Q->length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status GetHeadAQueue(AQueue * Q, void * e)
{
	if ( IsEmptyAQueue(Q) )
	{
		return FALSE;
	}
	else
	{
		e = *(Q->data + Q->front);
		return TRUE;
	}
}

int LengthAQueue(AQueue * Q)
{
	return Q->length;
}

Status EnAQueue(AQueue * Q, void * data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列已满!\n");
		return FALSE;
	}
	else
	{
		*(Q->data + Q->rear) = data;

		Q->rear = (Q->rear + 1) % MAXQUEUE;
		Q->length++;
		return TRUE;
	}
}

Status DeAQueue(AQueue * Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXQUEUE;
		Q->length--;
		return TRUE;
	}
}

void ClearAQueue(AQueue * Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
	{
		free( *(Q->data + i) );
	}
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
}

Status TraverseAQueue(const AQueue * Q, void(*foo)(void *q))
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	int i = Q->front;
	void *p = *(Q->data + i);	//队首
	while (i != Q->rear)
	{
		(*foo)(p);
		
		p = *(Q->data + (++i));
	}

	return TRUE;
}

void APrint(void * q)
{
	switch (T)
	{
	case 1:
		printf("%d\n", *((int *)q));
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
