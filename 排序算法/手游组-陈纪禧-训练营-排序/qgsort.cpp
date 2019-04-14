#include <iostream>
#include <string.h>
#include <stack>
#include "qgsort.h"

void qgsort::insertSort(int * a, int n)
{
	if (a == nullptr || n == 0)
	{
		std::cerr << "����Ϊ�գ�" << std::endl;
		return;
	}
	int i, j;
	int temp;

	for (i = 1; i < n; i++)
	{
		temp = a[i];				//����Ҫ����Ԫ�ص�ֵ���������ʱ������
		for (j = i - 1; j >= 0; j--)	//�Ӳ��봦��ǰ����
		{
			if (a[j] > temp)		//����a[i]�ͺ���
			{
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j + 1] = temp;		//a[j] <= a[i],Ӧ��a[j+1]������
	}
}

void qgsort::MergeArray(int * a, int begin, int mid, int end, int * temp)
{
	int index = begin;
	int i = begin, j = mid + 1;

	//�����ֵ������㹻Сʱ,begin == mid, mid + 1 == end
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])
			temp[index++] = a[i++];
		else
			temp[index++] = a[j++];
	}

	//�����䳤�Ȳ�ͬʱ
	while (i <= mid)			//���������ʣ�࣬�����Ԫ�ظ��Ƶ�tempβ��
	{
		temp[index++] = a[i++];
	}
	while (j <= end)			//�ұ�������ʣ�࣬���ұ�Ԫ�ظ��Ƶ�tempβ��
	{
		temp[index++] = a[j++];
	}

	//��temp�е����ݿ�����ԭ����(����a = temp)
	memcpy(a + begin, temp + begin, sizeof(int)*(end - begin + 1));
}

void qgsort::MergeSort(int * a, int begin, int end, int * temp)
{
	if (a == nullptr || begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	//�������
	MergeSort(a, begin, mid, temp);	
	//�ұ�����
	MergeSort(a, mid + 1, end, temp);
	//�����ߺϲ�
	MergeArray(a, begin, mid, end, temp);
}

void qgsort::QuickSort_Recursion(int * a, int begin, int end)
{
	if (begin >= end || a == nullptr)
	{
		return;
	}
	//�������
	int div = Partition(a, begin, end);
	//������벿��
	QuickSort_Recursion(a, begin, div - 1);
	//�����Ұ벿��
	QuickSort_Recursion(a, div + 1, end);
}

void qgsort::QuickSort(int * a, int begin, int end)
{
	if (begin >= end || a == nullptr)
	{
		std::cerr << "����Ϊ�գ�" << std::endl;
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
		//����������ֱ�ѹջ
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
	//ѡȡ���е�ĩβ��Ϊ�ؼ���
	int key = a[end];
	//index������¼�ؼ������ڵ��±�
	int index = end;
	//��֤key����߶�С��key,�ұ߶�����key
	while (begin < end)
	{
		//��������Ѱ�ұ�key�����
		while (begin < end && a[begin] <= key)
			begin++;
		//��������Ѱ�ұ�keyС����
		while (begin < end && a[end] >= key)
			end--;

		temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
	}
	//begin >= endʱ��һ��������ɣ���ʱbeginָ��һ�����ڵ���key�����������ǽ���
	temp = a[begin];
	a[begin] = a[index];
	a[index] = temp;

	return begin;	//��ʱbegin��Ϊ���ᣬ���������߷ָ�
}

void qgsort::CountSort(int * a, int size)
{
	int *temp = new int[size];		//�������������

	//��������������Сֵ
	int max = a[0], min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//��ȡ���ַ�Χ�������ڴ�
	int len = max - min + 1;
	int *count = new int[len];		//��������
	for (int i = 0; i < len; i++)	//��ʼ��
	{
		count[i] = 0;
	}
	//�����������飬ͨ��ʵ��ֵ+-min�ķ�ʽ����ȡ�±꣬�ܽ����������,Ҳ��С�˿ռ��˷�

	//��¼ԭ����ÿһ�����ֳ��ֵĴ���
	for (int i = 0; i < size; i++)
	{
		//�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�ŵõ�ͳ�Ƶ��±�
		count[a[i] - min]++;
	}
	/*Ͱ�����д��, �ⲻ�Ǽ�������
	int j = 0;
	for (int i = 0; i < len; i++) 
	{
		while (temp[i]--) 
		{
			a[j++] = i + min;
		}
	}*/

	//����
	for (int i = 1; i < len; i++)
	{
		count[i] += count[i - 1];
	}
	//�Ӻ��濪ʼ
	for (int i = size - 1; i >= 0; i--)
	{
		int pos = --count[a[i]-min];		//�õ�ʵ��λ��
		temp[pos] = a[i];
	}
	//��temp���Ƹ�a
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
	int position = 1;	//λ����ÿ��һλ�ͳ�10
	//�������ֵ���������ֵ����ѭ������
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	while (max / position > 0)		//��������: max / position == 0
	{
		int count[10] = { 0 };		//��������
		int posDigit;
		//ͳ��ÿһ�����ֳ��ֵĴ���
		for (int i = 0; i < size; i++)
		{
			//�����λ�������֣���ͳ�Ƹ���
			posDigit = a[i] / position % 10;
			count[posDigit]++;
		}
		//����
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		//�Ӻ��濪ʼ
		for (int i = size - 1; i >= 0; i--)
		{
			//λ����Ӧ������
			posDigit = a[i] / position % 10;
			//��count��Ѱ��ͳ�ƵĽ����--count[posDigit]��Ϊa[i]����������ڵ�λ��
			temp[--count[posDigit]] = a[i];
		}
		//��temp���Ƹ�a
		for (int i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
		//��λ
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
	int temp;			//����
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
		{
			//����߽���
			temp = a[i];
			a[i] = a[left];
			a[left] = temp;
			left++;
			//�������������ֵΪ2,�����ұ߽���
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
			//���ұ߽���
			temp = a[i];
			a[i] = a[right];
			a[right] = temp;
			right--;
			while (a[i] != 1)
			{
				//�������������Ϊ0
				if (a[i] == 0)
				{
					temp = a[i];
					a[i] = a[left];
					a[left] = temp;
					left++;
				}
				//�������������Ϊ2
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
	if (begin == end && begin == k)		//��ֹ����ֻ��һ��Ԫ�ص�������������̵�
	{
		std::cout << "��Ԫ��Ϊ��" << a[k] << std::endl;
		return;
	}
	if (begin >= end || a == nullptr)
	{
		return;
	}

	int div = Partition(a, begin, end);
	if (div == k)
	{
		std::cout << "��Ԫ��Ϊ��" << a[k] << std::endl;
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
