#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void CountingSourt(int * data, int len);//普通计数排序(只能排正数)
void NegativeCountingSourt(int * data, int len, int min);//可以排负数的计数排序
void Display(int * data, int len);

int main()
{
	int len = 7;
	int i = 0;
	int * data = new int[len];
	int min = 50;//测试数据最小值
	//随机生成-50~50的数据
	srand((unsigned)time(NULL));
	for (i = 0; i < len; i++)
	{
		data[i] = rand() % 100;
	}
	/*
	cout << "普通计数排序(只有正数)" << endl;
	Display(data, len);
	CountingSourt(data, len);
	cout << "计数排序后:" << endl;
	Display(data, len);

	*/
	//随机生成-50~50的数据
	srand((unsigned)time(NULL));
	for (i = 0; i < len; i++)
	{
		data[i] = rand() % 100 - min;
	}
	Display(data, len);
	cout << "有负数的计数排序: " << endl;
	NegativeCountingSourt(data, len, min);
	cout << "计数排序后:" << endl;
	Display(data, len);


	return 0;
}

void NegativeCountingSourt(int * data, int len, int min)
{
	int max = data[0] + min;
	for (int i = 0; i < len; i++)
	{
		if (data[i] > max)
		{
			max = data[i] + min;
		}
	}
	
	int * count = new int[max + 1];
	int * supData = new int[len];

	//初始化count
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	//统计元素个数
	for (int i = 0; i < len; i++)
	{
		count[data[i] + 50] = count[data[i] + min] + 1;
	}
	//分配位置
	for (int i = 1; i <= max; i++)
	{
		count[i] = count[i - 1] + count[i];
	}

	for (int i = len - 1; i >= 0; i--)
	{
		supData[count[data[i] + min] - 1] = data[i] + min;
		count[data[i] + min] = count[data[i] + min] - 1;
	}

	for (int i = 0; i < len; i++)
	{
		data[i] = supData[i] - min;
	}

	delete supData;
	delete count;
}

void CountingSourt(int * data, int len)
{
	int max = data[0];
	for (int i = 0; i < len; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	
	int * count = new int[max + 1];
	int * supData = new int[len];

	//初始化count
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	//统计元素个数
	for (int i = 0; i < len; i++)
	{
		count[data[i]] = count[data[i]] + 1;
	}
	//分配位置
	for (int i = 1; i <= max; i++)
	{
		count[i] = count[i - 1] + count[i];
	}

	for (int i = len - 1; i >= 0; i--)
	{
		supData[count[data[i]] - 1] = data[i];
		count[data[i]] = count[data[i]] - 1;
	}

	for (int i = 0; i < len; i++)
	{
		data[i] = supData[i];
	}

	delete supData;
	delete count;
}

void Display(int * data, int len)
{
	cout << "======================" << endl << "index:";
	for (int i = 0; i < len; i++)
	{
		cout <<  setw(3) << i << " ";
	}
	cout << endl << "data :";
	for (int i = 0; i < len; i++)
	{
		cout <<  setw(3) << data[i] << " ";
	}
	cout << endl;
	cout << "======================" << endl;
}