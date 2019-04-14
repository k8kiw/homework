#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>		//时间库
#include "qgsort.h"


int main()
{
	//大数组
	int *arr1w = new int[10000];
	int *arr5w = new int[50000];
	int *arr20w = new int[200000];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		arr1w[i] = rand() % 1000000000;		//控制在10位以内
	}
	for (int i = 0; i < 50000; i++)
	{
		arr5w[i] = rand() % 1000000000;
	}
	for (int i = 0; i < 200000; i++)
	{
		arr20w[i] = rand() % 1000000000;
	}
	//大量小数组,二维
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
		std::cout << "1.时间测试\t2.手动测试" << std::endl;
		std::cin >> f;
	} while (f != 1 && f != 2);

	if (f == 1)
	{
		int F;
		do
		{
			std::cout << "1.大数据测试\t2.多次小数据测试" << std::endl;
			std::cin >> F;
		} while (F != 1 && F != 2);
		//大数据测试
		if (F == 1)
		{
			int flag;
			do
			{
				std::cout << "1.插入排序\t2.归并排序\t3.计数排序" << std::endl;
				std::cout << "4.递归快排\t5.迭代快排\t6.基数排序" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 6);

			int *temp = new int[10000];
			switch (flag)
			{
			case 1:
				start = clock();
				sort.insertSort(arr1w, 10000);
				diff = clock() - start;
				std::cout << "插入排序，1w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.insertSort(arr5w, 50000);
				diff = clock() - start;
				std::cout << "插入排序，5w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.insertSort(arr20w, 200000);
				diff = clock() - start;
				std::cout << "插入排序，20w数据量	t=" << diff << "ms" << std::endl;

				break;
			case 2:
				start = clock();
				sort.MergeSort(arr1w, 0, 9999, temp);
				diff = clock() - start;
				std::cout << "归并排序，1w数据量	t=" << diff << "ms" << std::endl;
				delete[]temp;

				temp = new int[50000];
				start = clock();
				sort.MergeSort(arr5w, 0, 49999, temp);
				diff = clock() - start;
				std::cout << "归并排序，5w数据量	t=" << diff << "ms" << std::endl;
				delete[]temp;

				temp = new int[200000];
				start = clock();
				sort.MergeSort(arr20w, 0, 199999, temp);
				diff = clock() - start;
				std::cout << "归并排序，20w数据量	t=" << diff << "ms" << std::endl;
				delete[]temp;

				break;
			case 3:
				start = clock();
				sort.CountSort(arr1w, 10000);
				diff = clock() - start;
				std::cout << "计数排序，1w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.CountSort(arr5w, 50000);
				diff = clock() - start;
				std::cout << "计数排序，5w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.CountSort(arr20w, 200000);
				diff = clock() - start;
				std::cout << "计数排序，20w数据量	t=" << diff << "ms" << std::endl;

				break;
			case 4:
				start = clock();
				sort.QuickSort_Recursion(arr1w, 0, 9999);
				diff = clock() - start;
				std::cout << "递归快排，1w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort_Recursion(arr5w, 0, 49999);
				diff = clock() - start;
				std::cout << "递归快排，5w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort_Recursion(arr20w, 0, 199999);
				diff = clock() - start;
				std::cout << "递归快排，20w数据量	t=" << diff << "ms" << std::endl;

				break;
			case 5:
				start = clock();
				sort.QuickSort(arr1w, 0, 9999);
				diff = clock() - start;
				std::cout << "迭代快排，1w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort(arr5w, 0, 49999);
				diff = clock() - start;
				std::cout << "迭代快排，5w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.QuickSort(arr20w, 0, 199999);
				diff = clock() - start;
				std::cout << "迭代快排，20w数据量	t=" << diff << "ms" << std::endl;

				break;
			case 6:
				start = clock();
				sort.RadixCountSort(arr1w, 10000);
				diff = clock() - start;
				std::cout << "基数排序，1w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.RadixCountSort(arr5w, 50000);
				diff = clock() - start;
				std::cout << "基数排序，5w数据量	t=" << diff << "ms" << std::endl;

				start = clock();
				sort.RadixCountSort(arr20w, 200000);
				diff = clock() - start;
				std::cout << "基数排序，20w数据量	t=" << diff << "ms" << std::endl;

				break;
			}
			temp = nullptr;
		}
		//多次小数据测试
		if (F == 2)
		{
			int flag;
			do
			{
				std::cout << "1.插入排序\t2.归并排序\t3.计数排序" << std::endl;
				std::cout << "4.递归快排\t5.迭代快排\t6.基数排序" << std::endl;
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
				std::cout << "插入排序，100*100k数据量	t=" << diff << "ms" << std::endl;

				break;
			case 2:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.MergeSort(arr100[i], 0, 99, temp[i]);
				}
				diff = clock() - start;
				std::cout << "归并排序，100*100k数据量	t=" << diff << "ms" << std::endl;

				break;
			case 3:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.CountSort(arr100[i], 100);
				}
				diff = clock() - start;
				std::cout << "计数排序，100*100k数据量	t=" << diff << "ms" << std::endl;

				break;
			case 4:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.QuickSort_Recursion(arr100[i], 0, 99);
				}
				diff = clock() - start;
				std::cout << "递归快排，100*100k数据量	t=" << diff << "ms" << std::endl;

				break;
			case 5:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.QuickSort(arr100[i], 0, 99);
				}
				diff = clock() - start;
				std::cout << "迭代快排，100*100k数据量	t=" << diff << "ms" << std::endl;

				break;
			case 6:
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					sort.RadixCountSort(arr100[i], 100);
				}
				diff = clock() - start;
				std::cout << "基数排序，100*100k数据量	t=" << diff << "ms" << std::endl;

				break;
			}
		}
	}
	if (f == 2)
	{
		int F;
		do
		{
			std::cout << "1.输入测试\t2.文件测试" << std::endl;
			std::cin >> F;
		} while (F != 1 && F != 2);

		int n;
		do
		{
			std::cout << "输入排序的数字个数：";
			std::cin >> n;
		} while (n <= 0);
		int *a = new int[n];

		//输入测试
		if (F == 1)
		{
			std::cout << "输入要排序的序列(空格分隔)：" << std::endl;
			for (int i = 0; i < n; i++)
			{
				std::cin >> a[i];
			}

			int flag;
			do
			{
				std::cout << "1.插入排序\t2.归并排序\t3.计数排序" << std::endl;
				std::cout << "4.递归快排\t5.迭代快排\t6.基数排序" << std::endl;
				std::cout << "7.颜色排序(必须为0 1 2)\t8.搜索第k小的数字" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 8);

			int *temp = new int[n];		//用于归并排序
			int k = 0;					//用于搜索
			switch (flag)
			{
			case 1:
				sort.insertSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 2:
				sort.MergeSort(a, 0, n - 1, temp);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 3:
				sort.CountSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 4:
				sort.QuickSort_Recursion(a, 0, n - 1);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 5:
				sort.QuickSort(a, 0, n - 1);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 6:
				sort.RadixCountSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 7:
				sort.ColorSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;

				break;
			case 8:
				std::cout << "输入要搜索第几小的数字：";
				std::cin >> k;
				sort.SearchNum(a, 0, n - 1, k - 1);

				break;
			}
			delete[]temp;
			temp = nullptr;
		}
		if (F == 2)
		{
			//产生随机数组
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 1000000000;
			}
			//写入到1.txt
			std::ofstream out("1.txt");
			if (out.is_open())
			{
				for (int i = 0; i < n; i++)
				{
					out << a[i] << "  ";
				}
				std::cout << "数据已写入1.txt！" << std::endl;
				out.close();
			}

			int flag;
			do
			{
				std::cout << "1.插入排序\t2.归并排序\t3.计数排序" << std::endl;
				std::cout << "4.递归快排\t5.迭代快排\t6.基数排序" << std::endl;
				std::cin >> flag;
			} while (flag < 1 || flag > 6);

			
			out.open("2.txt");
			int *temp = new int[n];		//用于归并排序
			int k = 0;					//用于搜索
			switch (flag)
			{
			case 1:
				sort.insertSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//输出到2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "数据已写入2.txt！" << std::endl;
				}

				break;
			case 2:
				sort.MergeSort(a, 0, n - 1, temp);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//输出到2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "文件已写入2.txt！" << std::endl;
				}

				break;
			case 3:
				sort.CountSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//输出到2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "文件已写入2.txt！" << std::endl;
				}

				break;
			case 4:
				sort.QuickSort_Recursion(a, 0, n - 1);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//输出到2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "文件已写入2.txt！" << std::endl;
				}

				break;
			case 5:
				sort.QuickSort(a, 0, n - 1);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//输出到2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "文件已写入2.txt！" << std::endl;
				}

				break;
			case 6:
				sort.RadixCountSort(a, n);
				std::cout << "排序完的结果为：" << std::endl;
				for (int i = 0; i < n; i++)
				{
					std::cout << a[i] << " ";
				}
				std::cout << std::endl;
				//输出到2.txt
				if (out.is_open())
				{
					for (int i = 0; i < n; i++)
					{
						out << a[i] << "  ";
					}
					std::cout << "文件已写入2.txt！" << std::endl;
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
	//sort.RadixCountSort(a, sizeof(a) / sizeof(int));	//要求非负数
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