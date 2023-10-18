/*
(5) Разность между максимумом и минимумом

1 2 1 1 5
1 1 0 30 -1
0 -25 0 1 70
1 2 0 0 200
1 2 50 0 4
Answer: 75

1 2 1 1 5 
1 1 2 30 -1
2 25 3 1 70
1 2 1 2 200
1 2 50 4 4
Answer: 49
*/
#include <stdio.h>
#include <math.h> 

int is_func_valid(int i, int j) // Проверка на рисунок
{
	return j <= 3 && i <= 6;
}

float minimum(int N, float A[][]) // Минимум
{
	float min = 0.0;
	for (int i = 0; i < N; i++)
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
			if (is_func_valid(i, j))
			{
				if (A[i][j] < min)
					min = A[i][j];
			}
		}
	}
	
	return min;
}

float maximum(int N, float A[][]) // Максимум
{
	float max = 0.0;
	for (int i = 0; i < N; i++)
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
	
	return max;
}

int func(int N, float A[][], float B[][])
{
	float min = minimum(N, A);
	float max = maximum(N, A);

	printf("\nMax: %.1f, Min: %.1f\n\n", max, min);
	
	float result = (max - min);
	for (int i = 0; i < N; i++) // Результирующая
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = result;
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
