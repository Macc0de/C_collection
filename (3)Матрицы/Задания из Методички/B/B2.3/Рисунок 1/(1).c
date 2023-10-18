/*
(1) Минимум

1 2 3 4 5 1 2
1 2 3 4 5 2 3
1 2 3 4 5 4 5
1 2 3 4 53 8 9 
0 0 2 1 5 4 1
2 4 10 14 1 100 3
7 8 9 10 100 110 90
*/
#include <stdio.h>

float matrix[10][10] = // Глобальная
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
}; // Явно указываем

int is_func_valid(int index, int jindex) // Проверка на рисунок
{
	return matrix[index][jindex];
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
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				B[i][j] = min;
			}
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
	
	printf("Enter N: ");
	
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
