/*
(4) Сумма модулей

1 2 1 1 5
1 1 0 0 -1
0 0 0 1 7
-1 -2 0 0 2
-1 -2 0 0 4
Answer: 14
*/
#include <stdio.h>
#include <math.h> 

int is_func_valid(int i, int j) // Проверка на рисунок
{
	return j <= 3 && i <= 6;
}

int func(int N, float A[][], float B[][])
{
	float sum_mod = 0.0;
	for (int i = 0; i < N; i++) // Сумма модулей
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				sum_mod += fabs(A[i][j]);
			}
		}
	}
	
	printf("\nSumma modylei: %.1f\n\n", sum_mod);
	
	for (int i = 0; i < N; i++) // Результирующая
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = sum_mod;
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
