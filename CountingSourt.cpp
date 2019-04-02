#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void CountingSourt(int * data, int len);//��ͨ��������(ֻ��������)
void NegativeCountingSourt(int * data, int len, int min);//�����Ÿ����ļ�������
void Display(int * data, int len);

int main()
{
	int len = 7;
	int i = 0;
	int * data = new int[len];
	int min = 50;//����������Сֵ
	//�������-50~50������
	srand((unsigned)time(NULL));
	for (i = 0; i < len; i++)
	{
		data[i] = rand() % 100;
	}
	/*
	cout << "��ͨ��������(ֻ������)" << endl;
	Display(data, len);
	CountingSourt(data, len);
	cout << "���������:" << endl;
	Display(data, len);

	*/
	//�������-50~50������
	srand((unsigned)time(NULL));
	for (i = 0; i < len; i++)
	{
		data[i] = rand() % 100 - min;
	}
	Display(data, len);
	cout << "�и����ļ�������: " << endl;
	NegativeCountingSourt(data, len, min);
	cout << "���������:" << endl;
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

	//��ʼ��count
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	//ͳ��Ԫ�ظ���
	for (int i = 0; i < len; i++)
	{
		count[data[i] + 50] = count[data[i] + min] + 1;
	}
	//����λ��
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

	//��ʼ��count
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	//ͳ��Ԫ�ظ���
	for (int i = 0; i < len; i++)
	{
		count[data[i]] = count[data[i]] + 1;
	}
	//����λ��
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