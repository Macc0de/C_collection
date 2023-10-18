/* 
(1) Минимум. Проверка рисунка через цикл, но для цикла нужно учитывать размерность м-цы

9x9
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 -2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 3 4 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/
#include <stdio.h>

int is_func_valid(int index, int jindex)
{
	// Первая половина
	int flag;
	for (int i = 9; i >= 3; i--) // Столбцы
	{
		flag = 0;
		for (int j = i+1; j <= 9; j++) // Строки
		{
			if (i == jindex && j == index) // Индекс такой же как в цикле
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 1) // Если не найдет то пойдет искать во 2 половине
			return 1;
	}
	
	// Вторая половина
	for (int i = 2; i >= 0; i--) // Столбцы
	{
		for (int j = 9; j >= 7-i; j--) // Строки
		{
			if (i == jindex && j == index)
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 1)
			return 1;
	}
	
	return 0;
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
