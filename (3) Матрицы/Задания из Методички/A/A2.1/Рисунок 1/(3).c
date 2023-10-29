/* 
(3) Максимум

2 3 4 4 5 800
11 1 0 100 -1 890
90 0 0 81 7 50
1 12 101 91 2 0 
1 13 0 105 4 1000
0 0 0 8 9 7
Answer: 105
*/
#include <stdio.h>
#include <math.h>

int is_func_valid(int i, int j) // Проверка на рисунок
{
	return j <= 3 && i <= 6;
}

int func(int N, float A[][], float B[][])
{
	float max = 0.0;
	for (int i = 0; i < N; i++) // Максимум
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				max = A[i][j];
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				if (A[i][j] > max)
					max = A[i][j];
			}
		}
	}
	
	printf("\nMax: %.1f\n\n", max);
	
	for (int i = 0; i < N; i++) // Результирующая
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = max;
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
