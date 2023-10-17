/*
(2) Сумма

1 1 1 4 5
1 1 0 3 -1
1 0 0 1 7
1 1 1 1 2
1 1 0 1 4
*/
#include <stdio.h>
#include <math.h>

int is_func_valid(int i, int j) // Проверка на рисунок
{
	return j <= 3 && i <= 6;
}

int func(int N, float A[][], float B[][])
{
	float sum = 0.0;
	for (int i = 0; i < N; i++) // Сумма
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				sum += A[i][j];
			}
		}
	}
	
	printf("\nSum: %.1f\n\n", sum);
	
	for (int i = 0; i < N; i++) // Результирующая
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = sum;
		}
	}
	
	for (int i = 0; i < N; i++) 
	{
		int flag = 0;
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				flag = 1;
				printf("%.1f ", B[i][j]);
			}
		}
		
		if (flag)
			printf("\n");
	}
	
	return 0;
}

int main() 
{
	int i, j, N;
	
	scanf("%d", &N);
	if (N > 20)
		printf("Error");
	
	float A[N][N], B[N][N];
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++)
		{
			scanf("%f", &A[i][j]);
		}
	}
	
	func(N, A, B);
	
	return 0;
}
