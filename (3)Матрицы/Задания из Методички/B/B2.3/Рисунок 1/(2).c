/*
(2) Сумма

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
0 0 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0
1 1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 1 0
Answer: Sum - 24
*/
#include <stdio.h>

float matrix[10][10] =
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
};

int is_func_valid(int index, int jindex) // Проверка на рисунок
{
	return matrix[index][jindex];
}

int func(int N, float A[][], float B[][])
{
	float sum = 0.0;
	for (int i = 0; i < N; i++) // Минимум
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				sum += A[i][j];
			}
		}
	}
	
	printf("\nSumma: %.1f\n\n", sum);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (is_func_valid(i, j))
			{
				B[i][j] = sum;
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
