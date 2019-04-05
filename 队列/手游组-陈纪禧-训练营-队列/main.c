#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"
#include "LQueue.h"

int T;		//数据类型

int main()
{
	do
	{
		printf("请选择队列的数据类型：\n");
		printf("1.int\t2.double\t3.char\t4.string\n");
		scanf_s("%d", &T);
	} while (T != 1 && T != 2 && T != 3 && T != 4);

	int f;
	do
	{
		printf("请选择队列的类型：\n");
		printf("1.链式队列\t2.循环队列\n");
		scanf_s("%d", &f);
	} while (f != 1 && f != 2);

	if (f == 1)
	{
		LQueue *lq = malloc(sizeof(LQueue));
		InitLQueue(lq);
		while (1)
		{
			int i_data;
			double d_data;
			char c_data;
			char *s_data = NULL;

			int a;
			do
			{
				printf("请选择函数：\n");
				printf("1.查看队头元素\t2.判空\t3.查看长度\n");
				printf("4.入队\t5.出队\t6.遍历打印\n");
				scanf_s("%d", &a);
			} while (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6);

			switch (a)
			{
			case 1:
				printf("队首元素为：");
				if (T == 1)
				{
					GetHeadLQueue(lq, &i_data);
					printf("%d\n", i_data);
				}
				else if (T == 2)
				{
					GetHeadLQueue(lq, &d_data);
					printf("%f\n", d_data);
				}
				else if (T == 3)
				{
					GetHeadLQueue(lq, &c_data);
					printf("%c\n", c_data);
				}
				else if (T == 4)
				{
					GetHeadLQueue(lq, s_data);
					printf("%s\n", s_data);
				}
				break;
			case 2:
				if (IsEmptyLQueue(lq))
				{
					printf("队列为空！\n");
				}
				break;
			case 3:
				printf("长度为：%d\n", LengthLQueue(lq));
				break;
			case 4:
				if (T == 1)
				{
					printf("输入元素:");
					scanf_s("%d", &i_data);
					EnLQueue(lq, &i_data);
				}
				else if (T == 2)
				{
					printf("输入元素:");
					scanf_s("%lf", &d_data);
					EnLQueue(lq, &d_data);
				}
				else if (T == 3)
				{
					printf("输入元素:");
					scanf_s("%c", &c_data, 1);
					EnLQueue(lq, &c_data);
				}
				else if (T == 4)
				{
					printf("输入字符串：");
					fflush(stdin);
					gets_s(s_data, 100);
					EnLQueue(lq, s_data);
				}
				break;
			case 5:
				DeLQueue(lq);
				break;
			case 6:
				TraverseLQueue(lq, &LPrint);
				break;
			}
		}

	}
	else if (f == 2)
	{
		AQueue *aq = malloc(sizeof(AQueue));
		InitAQueue(aq);
		while (1)
		{
			int i_data;
			double d_data;
			char c_data;
			char *s_data = NULL;

			int a;
			do
			{
				printf("请选择函数：\n");
				printf("1.查看队头元素\t2.判空\t3.查看长度\n");
				printf("4.入队\t5.出队\t6.遍历打印\n");
				scanf_s("%d", &a);
			} while (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6);

			switch (a)
			{
			case 1:
				printf("队首元素为：");
				if (T == 1)
				{
					GetHeadAQueue(aq, &i_data);
					printf("%d\n", i_data);
				}
				else if (T == 2)
				{
					GetHeadAQueue(aq, &d_data);
					printf("%f\n", d_data);
				}
				else if (T == 3)
				{
					GetHeadAQueue(aq, &c_data);
					printf("%c\n", c_data);
				}
				else if (T == 4)
				{
					GetHeadAQueue(aq, s_data);
					printf("%s\n", s_data);
				}
				break;
			case 2:
				if (IsEmptyAQueue(aq))
				{
					printf("队列为空！\n");
				}
				break;
			case 3:
				printf("长度为：%d\n", LengthAQueue(aq));
				break;
			case 4:
				if (T == 1)
				{
					printf("输入元素:");
					scanf_s("%d", &i_data);
					EnAQueue(aq, &i_data);
				}
				else if (T == 2)
				{
					printf("输入元素:");
					scanf_s("%lf", &d_data);
					EnAQueue(aq, &d_data);
				}
				else if (T == 3)
				{
					printf("输入元素:");
					scanf_s("%c", &c_data, 1);
					EnAQueue(aq, &c_data);
				}
				else if (T == 4)
				{
					printf("输入字符串：");
					fflush(stdin);
					gets_s(s_data, 100);
					EnAQueue(aq, s_data);
				}
				break;
			case 5:
				DeAQueue(aq);
				break;
			case 6:
				TraverseAQueue(aq, &APrint);
				break;
			}
		}

	}
	
	

	system("pause");
	return 0;
}
