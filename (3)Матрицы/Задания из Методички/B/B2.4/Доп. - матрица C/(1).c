/*
Дополнение к (6):
(1) C=(A+E)*B

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

int func(int N, int A[][])
{
	int i, j, k;
	int B[N][N], E[N][N], Summa[N][N], C[N][N];
	
	printf("\n");
	for (i = 0; i < N; i++) // E
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
				E[i][j] = 1;
			else
				E[i][j] = 0;
		}
	}
	
	printf("Matrix B:\n");
	
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
	
	printf("\n(A+E):\n");
	
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
	
	printf("\n(A+E)*B:\n");
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			C[i][j] = 0; // Важно
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
