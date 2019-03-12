//��C��C++ʵ��˳������㷨�����ֲ����㷨�������ϲ��㷨�����л����㷨�����������㷨�͹鲢�����㷨��
#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

int seqSearch(elemtype * arr, elemtype x, int len); //˳�����
int binarySearch(elemtype * arr, elemtype x, int len); //���ֲ���
elemtype * merge(elemtype * arr1, elemtype arry2); //�����ϲ�
int partition(elemtype * arr, int index, int head, int tail); //���л���
int mergeSort(elemtype * arr); //�鲢����
int quickSort(elemtype * arr, int head, int tail); //��������
void display(elemtype * arr, int len);

int main()
{
	elemtype arr[10] = {5, 3, 6, 1, 8, 6, 2, 0, 4, 7};
	elemtype seqArr[10] = {1, 3, 4, 6, 9, 11, 20, 30, 33, 40};
	//˳�����
	int len =  sizeof(arr) / sizeof(elemtype);
	int x = 8;
	int index = seqSearch(arr, x, len);
	printf("seqSearch: %d in index: %d...\n", x, index);


	//���ֲ���
	x = 40;
	len =  sizeof(seqArr) / sizeof(elemtype);
	index = binarySearch(seqArr, x, len);
	printf("binarySearch: %d in index: %d...\n", x, index);

	partition(arr, 0, 0, 9);
	display(arr, 10);

	quickSort(arr, 0, 9);
	display(arr, 10);

	return 0;
}

int seqSearch(elemtype * arr, elemtype x, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

int binarySearch(elemtype * arr, elemtype x, int len)
{
	int mid = len / 2;
	int head = 0;
	int tail = len - 1;
	while (head <= tail)
	{
		if (x > arr[mid])
		{
			head = mid + 1;
			mid = (tail + head) / 2;
		}
		else if(x < arr[mid])
		{
			tail = mid - 1;
			mid = (tail + head) / 2;
		}
		else if(x == arr[mid])
		{
			return mid;
		}
	}

	return -1;
}

int partition(elemtype * arr, int index, int head, int tail)
{
	elemtype x = arr[index];

	while (head < tail)
	{
		while (head < tail && arr[tail] > x)
		{
			//���ҿ�ʼ�ұ�xС��
				tail--;
		}
		if (head < tail)
		{
			arr[head] = arr[tail];
		}
		while (head < tail && arr[head] < x)
		{
			// ����ʼ�ұ�x���
				head++;
		}
		if (head < tail)
		{
			arr[tail] = arr[head];
		}
	}
	arr[head] = x;
	

	return head;
}

void display(elemtype * arr, int len)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int quickSort(elemtype * arr, int head, int tail)
{
	if (head < tail)
	{
		int p = partition(arr, 0, head, tail);
		quickSort(arr, head, p - 1);
		quickSort(arr, p + 1, head);
	}
	else
	{
		return 0;
	}
}