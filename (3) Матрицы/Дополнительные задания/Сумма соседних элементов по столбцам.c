/*
Посчитать сумму соседних элементов по столбцам матрицы

1 2 1
2 4 2
0 -1 -1
*/
#include <stdio.h>
#define N 3
#define M 3

int A[N][M];

int neighbours(int A[][]) 
{
	int i, j, count = 0;
	
	for (i = 0; i < N; i++)
	{
		for (j = 1; j < M - 1; j++) // Не берем нулевой и не берем последний
		{
			if (A[i][j] == (A[i][j-1] + A[i][j+1])) // Предыдущий и следующий столбец
				count++;
		}
	}
	
	return count;
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
	
	int ddd = neighbours(A);
	printf("%d", ddd);
	
	return 0;
}
