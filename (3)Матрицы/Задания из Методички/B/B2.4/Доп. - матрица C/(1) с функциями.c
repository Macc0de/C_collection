/* С функциями для каждого действия
Дополнение к (6):
(1) C=(A+E)*B

A
1 0 2
3 4 3
6 7 8
B
6 3 1
7 4 0
8 3 2
A+E
2 0 2
3 5 3
6 7 9
(A+E)*B
28	12	6
77	38	9
157	73	24
*/
#include <stdio.h>

void Mat_E(int N, int E[][])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
				E[i][j] = 1;
			else
				E[i][j] = 0;
		}
	}
}

void Mat_B(int N, int A[][], int B[][])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			B[i][N-j-1] = A[j][i];
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
}

void Mat_Summa(int N, int Summa[][], int A[][], int E[][])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Summa[i][j] = A[i][j] + E[i][j];
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", Summa[i][j]);
		}
		printf("\n");
	}
}

void Mat_Result(int N, int C[][], int Summa[][], int B[][])
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < N; k++)
			{
				C[i][j] += Summa[i][k] * B[k][j];
			}
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}

int func(int N, int A[][])
{	
	int B[N][N], E[N][N], Summa[N][N], C[N][N];
	printf("\n");
	
	Mat_E(N, E);
	
	printf("Matrix B:\n");
	Mat_B(N, A, B);
	
	printf("\n(A+E):\n");
	Mat_Summa(N, Summa, A, E);
	
	printf("\n(A+E)*B:\n");
	Mat_Result(N, C, Summa, B);
	
	return 0;
}

int main() 
{
	int i, j, N;
	
	printf("Enter N: ");
	
	scanf("%d", &N); 
	if (N > 20)
		printf("Error"); 
	
	int A[N][N];
	
	printf("Matrix A:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	func(N, A);
	
	return 0;
}
