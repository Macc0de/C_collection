#include <stdio.h>
#define N 2
#define M 2

int A[N][M]; 
int B[N][M];
int C[N][M];

void func(int a[][], int b[][], int c[][])
{
	int i, j;
	
	// Сложение
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

int main() 
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}
	
	printf("\n");
	func(A, B, C);
	
	return 0;
}