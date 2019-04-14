#include <iostream>
#include <string.h>
#include <stack>
#include "qgsort.h"

void qgsort::insertSort(int * a, int n)
{
	if (a == nullptr || n == 0)
	{
		std::cerr << "数组为空！" << std::endl;
		return;
	}
	int i, j;
	int temp;

	for (i = 1; i < n; i++)
	{
		temp = a[i];				//保存要插入元素的值，避免后移时被覆盖
		for (j = i - 1; j >= 0; j--)	//从插入处往前遍历
		{
			if (a[j] > temp)		//大于a[i]就后移
			{
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j + 1] = temp;		//a[j] <= a[i],应在a[j+1]处插入
	}
}

void qgsort::MergeArray(int * a, int begin, int mid, int end, int * temp)
{
	int index = begin;
	int i = begin, j = mid + 1;

	//当划分的区间足够小时,begin == mid, mid + 1 == end
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])
			temp[index++] = a[i++];
		else
			temp[index++] = a[j++];
	}

	//两区间长度不同时
	while (i <= mid)			//左边区间有剩余，将左边元素复制到temp尾部
	{
		temp[index++] = a[i++];
	}
	while (j <= end)			//右边区间有剩余，将右边元素复制到temp尾部
	{
		temp[index++] = a[j++];
	}

	//将temp中的数据拷贝到原数组(不能a = temp)
	memcpy(a + begin, temp + begin, sizeof(int)*(end - begin + 1));
}

void qgsort::MergeSort(int * a, int begin, int end, int * temp)
{
	if (a == nullptr || begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	//左边排序
	MergeSort(a, begin, mid, temp);	
	//右边排序
	MergeSort(a, mid + 1, end, temp);
	//将两边合并
	MergeArray(a, begin, mid, end, temp);
}

void qgsort::QuickSort_Recursion(int * a, int begin, int end)
{
	if (begin >= end || a == nullptr)
	{
		return;
	}
	//获得枢轴
	int div = Partition(a, begin, end);
	//排列左半部分
	QuickSort_Recursion(a, begin, div - 1);
	//排列右半部分
	QuickSort_Recursion(a, div + 1, end);
}

void qgsort::QuickSort(int * a, int begin, int end)
{
	if (begin >= end || a == nullptr)
	{
		std::cerr << "数组为空！" << std::endl;
		return;
	}

	std::stack<int> s;
	s.push(begin);
	s.push(end);

	while (s.empty() != true)
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();
		int div = Partition(a, left, right);
		//将左右区间分别压栈
		if (left < div - 1) {
			s.push(left);
			s.push(div - 1);
		}
		if (right > div + 1) {
			s.push(div + 1);
			s.push(right);
		}
	}
}

int qgsort::Partition(int * a, int begin, int end)
{
	int temp;
	//选取序列的末尾作为关键字
	int key = a[end];
	//index用来记录关键字所在的下标
	int index = end;
	//保证key的左边都小于key,右边都大于key
	while (begin < end)
	{
		//从左向右寻找比key大的数
		while (begin < end && a[begin] <= key)
			begin++;
		//从右向左寻找比key小的数
		while (begin < end && a[end] >= key)
			end--;

		temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
	}
	//begin >= end时，一次排序完成，此时begin指向一个大于等于key的数，将它们交换
	temp = a[begin];
	a[begin] = a[index];
	a[index] = temp;

	return begin;	//此时begin即为枢轴，将左右两边分割
}

void qgsort::CountSort(int * a, int size)
{
	int *temp = new int[size];		//存放排序后的数组

	//计算该序列最大最小值
	int max = a[0], min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//获取数字范围并分配内存
	int len = max - min + 1;
	int *count = new int[len];		//计数数组
	for (int i = 0; i < len; i++)	//初始化
	{
		count[i] = 0;
	}
	//这样创建数组，通过实际值+-min的方式来获取下标，能解决负数问题,也减小了空间浪费

	//记录原序列每一个数字出现的次数
	for (int i = 0; i < size; i++)
	{
		//这里在存储上要在原始数组数值上减去min才得到统计的下标
		count[a[i] - min]++;
	}
	/*桶排序的写法, 这不是计数排序
	int j = 0;
	for (int i = 0; i < len; i++) 
	{
		while (temp[i]--) 
		{
			a[j++] = i + min;
		}
	}*/

	//计数
	for (int i = 1; i < len; i++)
	{
		count[i] += count[i - 1];
	}
	//从后面开始
	for (int i = size - 1; i >= 0; i--)
	{
		int pos = --count[a[i]-min];		//得到实际位置
		temp[pos] = a[i];
	}
	//将temp复制给a
	for (int i = 0; i < size; i++)
	{
		a[i] = temp[i];
	}

	delete[]count;
	delete[]temp;
	count = nullptr;
	temp = nullptr;
}

void qgsort::RadixCountSort(int * a, int size)
{
	int *temp = new int[size];
	int position = 1;	//位数，每进一位就乘10
	//计算最大值，根据最大值决定循环几次
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	while (max / position > 0)		//结束条件: max / position == 0
	{
		int count[10] = { 0 };		//计数数组
		int posDigit;
		//统计每一个数字出现的次数
		for (int i = 0; i < size; i++)
		{
			//求出该位数的数字，并统计个数
			posDigit = a[i] / position % 10;
			count[posDigit]++;
		}
		//计数
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		//从后面开始
		for (int i = size - 1; i >= 0; i--)
		{
			//位数对应的数字
			posDigit = a[i] / position % 10;
			//在count中寻找统计的结果，--count[posDigit]即为a[i]排序完后所在的位置
			temp[--count[posDigit]] = a[i];
		}
		//将temp复制给a
		for (int i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
		//进位
		position *= 10;
	}
}

void qgsort::ColorSort(int * a, int size)
{
	if (size == 0 || a == nullptr)
	{
		return;
	}

	int left = 0, right = size - 1;
	int temp;			//交换
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
		{
			//与左边交换
			temp = a[i];
			a[i] = a[left];
			a[left] = temp;
			left++;
			//如果交换过来的值为2,则与右边交换
			while (a[i] == 2)
			{
				temp = a[i];
				a[i] = a[right];
				a[right] = temp;
				right--;
			}
		}
		if (a[i] == 2)	
		{
			//与右边交换
			temp = a[i];
			a[i] = a[right];
			a[right] = temp;
			right--;
			while (a[i] != 1)
			{
				//如果交换过来的为0
				if (a[i] == 0)
				{
					temp = a[i];
					a[i] = a[left];
					a[left] = temp;
					left++;
				}
				//如果交换过来的为2
				if (a[i] == 2)
				{
					temp = a[i];
					a[i] = a[right];
					a[right] = temp;
					right--;
				}
			}
		}


		if (i >= right)
		{
			break;
		}
	}
}

void qgsort::SearchNum(int * a, int begin, int end, int k)
{
	if (begin == end && begin == k)		//防止序列只有一个元素的情况被错误检查吞掉
	{
		std::cout << "该元素为：" << a[k] << std::endl;
		return;
	}
	if (begin >= end || a == nullptr)
	{
		return;
	}

	int div = Partition(a, begin, end);
	if (div == k)
	{
		std::cout << "该元素为：" << a[k] << std::endl;
		return;
	}
	else if (div > k)
	{
		SearchNum(a, begin, div - 1, k);
	}
	else
	{
		SearchNum(a, div + 1, end, k);
	}
}
