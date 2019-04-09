#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;
typedef int elemtype;

void InitMatrix(elemtype **& Matrix, int n, int m);
void DisplayMatrix(elemtype **& Matrix, int n, int m);
void Transpose(elemtype **& Matrix, int n, int m, elemtype **& returnMatrix);
void MatrixAdd(elemtype **& Matrix1, elemtype **& Matrix2, int n, int m);
void MatrixSub(elemtype **& Matrix1, elemtype **& Matrix2, int n, int m);
void MatrixMul(elemtype **& Matrix1, elemtype **& Matrix2, int n, int m);

int main()
{
	int n = 5;
	int m = 3;
	elemtype ** Matrix1 = new int *[n];
	elemtype ** Matrix2 = new int *[n];
	elemtype ** returnMatrix;
	InitMatrix(Matrix1, n, m);
	InitMatrix(Matrix2, n, m);
	DisplayMatrix(Matrix1, n, m);
	DisplayMatrix(Matrix2, n, m);
	//Transpose(Matrix1, n, m, returnMatrix);
	//DisplayMatrix(returnMatrix, m, n);
	//MatrixAdd(Matrix1, Matrix2, n, m);
	//DisplayMatrix(returnMatrix, n, m);

	delete []Matrix1;
	delete []Matrix2;
	//delete []returnMatrix;

	return 0;
}

void InitMatrix(elemtype **& Matrix, int n, int m)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i ++)
	{
		Matrix[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Matrix[i][j] = rand() % 10;
		}
	}
}

void DisplayMatrix(elemtype **& Matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << Matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Transpose(elemtype **& Matrix, int n, int m, elemtype **& returnMatrix)
{
	returnMatrix = new int * [m];
	for (int i = 0; i < m; i ++)
	{
		returnMatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			returnMatrix[i][j] = Matrix[j][i];
		}
	}
}

void MatrixAdd(elemtype **& Matrix1, elemtype **& Matrix2, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Matrix1[i][j] += Matrix2[i][j];
		}
	}
}