/* 
(1) Минимум. Для 2 рисунка

1 2 3 4 5 3 1
8 9 0 3 -1 4 -2000
-300 2 5 6 7 -178 -400
6 6 -600 6 2 -200 1
-10 -12 0 3 4 -1000 2
0 0 0 1 2 3 4
0 0 0 0 0 0 1
Answer: -2000
*/
#include <stdio.h>
#include <math.h> 

int is_func_valid(int i, int j) // Проверка на рисунок 2
{
	return j >= 5 && j <= 9 && i <= 3;
}

int func(int N, float A[][], float B[][])
{
	float min = 0.0;
	for (int i = 0; i < N; i++) // Минимум
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				min = A[i][j];
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j)) // Рисунок
			{
				if (A[i][j] < min)
					min = A[i][j];
			}
		}
	}
	
	printf("\nMin: %.1f\n\n", min);
	
	for (int i = 0; i < N; i++) // Результирующая
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = min;
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
