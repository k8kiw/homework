#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>		//ʱ���
#include "qgsort.h"


int main()
{
	//������
	int *arr1w = new int[10000];
	int *arr5w = new int[50000];
	int *arr20w = new int[200000];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		arr1w[i] = rand() % 1000000000;		//������10λ����
	}
	for (int i = 0; i < 50000; i++)
	{
		arr5w[i] = rand() % 1000000000;
	}
	for (int i = 0; i < 200000; i++)
	{
		arr20w[i] = rand() % 1000000000;
	}
	//����С����,��ά
	int (*arr100)[100] = new int[100000][100];
	for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			arr100[i][j] = rand() % 1000000000;
		}
	}

	clock_t start, diff;
	qgsort sort;

	int f;
	do
	{
		std::cout << "1.ʱ�����\t2.�ֶ�����" << std::endl;
		std::cin >> f;
	} while (f != 1 && f != 2);

	if (f == 1)
	{
		int F;
		do
		{
			std::cout << "1.�����ݲ���\t2.���С���ݲ���" << std::endl;
			std::cin >> F;
		} while (F != 1 && F != 2);
		//�����ݲ���
		if (F == 1)
		{
			int flag;
			do
			{
				std::cout << "1.��������\t2.�鲢����\t3.��������" << std::endl;
				std::cout << "4.�ݹ����\t5.��������\t6.��������" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 6);

			int *temp = new int[10000];
			switch (flag)
			{
			case 1:
				start = clock();
				sort.insertSort(arr1w, 10000);
				diff = clock() - start;
				std::cout << "��������1w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.insertSort(arr5w, 50000);
				diff = clock() - start;
				std::cout << "��������5w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.insertSort(arr20w, 200000);
				diff = clock() - start;
				std::cout << "��������20w������	t=" << diff << "ms" << std::endl;

				break;
			case 2:
				start = clock();
				sort.MergeSort(arr1w, 0, 9999, temp);
				diff = clock() - start;
				std::cout << "�鲢����1w������	t=" << diff << "ms" << std::endl;
				delete[]temp;

				temp = new int[50000];
				start = clock();
				sort.MergeSort(arr5w, 0, 49999, temp);
				diff = clock() - start;
				std::cout << "�鲢����5w������	t=" << diff << "ms" << std::endl;
				delete[]temp;

				temp = new int[200000];
				start = clock();
				sort.MergeSort(arr20w, 0, 199999, temp);
				diff = clock() - start;
				std::cout << "�鲢����20w������	t=" << diff << "ms" << std::endl;
				delete[]temp;

				break;
			case 3:
				start = clock();
				sort.CountSort(arr1w, 10000);
				diff = clock() - start;
				std::cout << "��������1w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.CountSort(arr5w, 50000);
				diff = clock() - start;
				std::cout << "��������5w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.CountSort(arr20w, 200000);
				diff = clock() - start;
				std::cout << "��������20w������	t=" << diff << "ms" << std::endl;

				break;
			case 4:
				start = clock();
				sort.QuickSort_Recursion(arr1w, 0, 9999);
				diff = clock() - start;
				std::cout << "�ݹ���ţ�1w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort_Recursion(arr5w, 0, 49999);
				diff = clock() - start;
				std::cout << "�ݹ���ţ�5w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort_Recursion(arr20w, 0, 199999);
				diff = clock() - start;
				std::cout << "�ݹ���ţ�20w������	t=" << diff << "ms" << std::endl;

				break;
			case 5:
				start = clock();
				sort.QuickSort(arr1w, 0, 9999);
				diff = clock() - start;
				std::cout << "�������ţ�1w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort(arr5w, 0, 49999);
				diff = clock() - start;
				std::cout << "�������ţ�5w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort(arr20w, 0, 199999);
				diff = clock() - start;
				std::cout << "�������ţ�20w������	t=" << diff << "ms" << std::endl;

				break;
			case 6:
				start = clock();
				sort.RadixCountSort(arr1w, 10000);
				diff = clock() - start;
				std::cout << "��������1w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.RadixCountSort(arr5w, 50000);
				diff = clock() - start;
				std::cout << "��������5w������	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.RadixCountSort(arr20w, 200000);
				diff = clock() - start;
				std::cout << "��������20w������	t=" << diff << "ms" << std::endl;

				break;
			}
			temp = nullptr;
		}
		//���С���ݲ���
		if (F == 2)
		{
			int flag;
			do
			{
				std::cout << "1.��������\t2.�鲢����\t3.��������" << std::endl;
				std::cout << "4.�ݹ����\t5.��������\t6.��������" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 6);
			
			int(*temp)[100] = new int[100000][100];
			switch (flag)
			{
			case 1:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.insertSort(arr100[i], 100);
				}
				diff = clock() - start;
				std::cout << "��������100*100k������	t=" << diff << "ms" << std::endl;

				break;
			case 2:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.MergeSort(arr100[i], 0, 99, temp[i]);
				}
				diff = clock() - start;
				std::cout << "�鲢����100*100k������	t=" << diff << "ms" << std::endl;

				break;
			case 3:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.CountSort(arr100[i], 100);
				}
				diff = clock() - start;
				std::cout << "��������100*100k������	t=" << diff << "ms" << std::endl;

				break;
			case 4:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.QuickSort_Recursion(arr100[i], 0, 99);
				}
				diff = clock() - start;
				std::cout << "�ݹ���ţ�100*100k������	t=" << diff << "ms" << std::endl;

				break;
			case 5:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.QuickSort(arr100[i], 0, 99);
				}
				diff = clock() - start;
				std::cout << "�������ţ�100*100k������	t=" << diff << "ms" << std::endl;

				break;
			case 6:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.RadixCountSort(arr100[i], 100);
				}
				diff = clock() - start;
				std::cout << "��������100*100k������	t=" << diff << "ms" << std::endl;

				break;
			}
		}
	}
	if (f == 2)
	{
		int F;
		do
		{
			std::cout << "1.�������\t2.�ļ�����" << std::endl;
			std::cin >> F;
		} while (F != 1 && F != 2);

		int n;
		do
		{
			std::cout << "������������ָ�����";
			std::cin >> n;
		} while (n <= 0);
		int *a = new int[n];

		//�������
		if (F == 1)
		{
			std::cout << "����Ҫ���������(�ո�ָ�)��" << std::endl;
			for (int i = 0; i < n; i++)
			{
				std::cin >> a[i];
			}

			int flag;
			do
			{
				std::cout << "1.��������\t2.�鲢����\t3.��������" << std::endl;
				std::cout << "4.�ݹ����\t5.��������\t6.��������" << std::endl;
				std::cout << "7.��ɫ����(����Ϊ0 1 2)\t8.������kС������" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 8);

			int *temp = new int[n];		//���ڹ鲢����
			int k = 0;					//��������
			switch (flag)
			{
			case 1:
				sort.insertSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 2:
				sort.MergeSort(a, 0, n - 1, temp);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 3:
				sort.CountSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 4:
				sort.QuickSort_Recursion(a, 0, n - 1);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 5:
				sort.QuickSort(a, 0, n - 1);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 6:
				sort.RadixCountSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 7:
				sort.ColorSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 8:
				std::cout << "����Ҫ�����ڼ�С�����֣�";
				std::cin >> k;
				sort.SearchNum(a, 0, n - 1, k - 1);

				break;
			}
			delete[]temp;
			temp = nullptr;
		}
		if (F == 2)
		{
			//�����������
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 1000000000;
			}
			//д�뵽1.txt
			std::ofstream out("1.txt");
			if (out.is_open())
			{
				for (int i = 0; i < n; i++)
				{
					out << a[i] << "  ";
				}
				std::cout << "������д��1.txt��" << std::endl;
				out.close();
			}

			int flag;
			do
			{
				std::cout << "1.��������\t2.�鲢����\t3.��������" << std::endl;
				std::cout << "4.�ݹ����\t5.��������\t6.��������" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 6);

			
			out.open("2.txt");
			int *temp = new int[n];		//���ڹ鲢����
			int k = 0;					//��������
			switch (flag)
			{
			case 1:
				sort.insertSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//�����2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "������д��2.txt��" << std::endl;
				}

				break;
			case 2:
				sort.MergeSort(a, 0, n - 1, temp);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//�����2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "�ļ���д��2.txt��" << std::endl;
				}

				break;
			case 3:
				sort.CountSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//�����2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "�ļ���д��2.txt��" << std::endl;
				}

				break;
			case 4:
				sort.QuickSort_Recursion(a, 0, n - 1);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//�����2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "�ļ���д��2.txt��" << std::endl;
				}

				break;
			case 5:
				sort.QuickSort(a, 0, n - 1);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//�����2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "�ļ���д��2.txt��" << std::endl;
				}

				break;
			case 6:
				sort.RadixCountSort(a, n);
				std::cout << "������Ľ��Ϊ��" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//�����2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "�ļ���д��2.txt��" << std::endl;
				}

				break;
			}
			out.close();
			delete[]temp;
			temp = nullptr;
		}
	}




	//sort.insertSort(a, sizeof(a) / sizeof(int));
	/*int *temp = new int[sizeof(a) / sizeof(int)];
	sort.MergeSort(a, 0, sizeof(a) / sizeof(int) - 1, temp);
	delete[]temp;
	temp = nullptr;*/
	//sort.QuickSort_Recursion(a, 0, sizeof(a) / sizeof(int) - 1);
	//sort.QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	//sort.CountSort(a, sizeof(a) / sizeof(int));
	//sort.RadixCountSort(a, sizeof(a) / sizeof(int));	//Ҫ��Ǹ���
	//sort.ColorSort(a, sizeof(a) / sizeof(int));
	/*int k = 4;
	sort.SearchNum(a, 0, sizeof(a) / sizeof(int) - 1, k - 1);*/

	/*for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		std::cout << a[i] << std::endl;
	}*/

	system("pause");
	return 0;
}