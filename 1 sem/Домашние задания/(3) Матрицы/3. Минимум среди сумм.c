/*
Вводится размер матрицы(количество строк и столбцов) и ее элементы - целые числа.
Найти и вывести на печать номера столбцов, в которых сумма элементов минимальна.

При решении задачи дополнительные массивы использовать нельзя.

Input:
4 3
1 7 3
0 4 5
6 7 8
9 2 0
Output:
0 2
*/
#include <stdio.h>

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	int A[N][M];
	int i, j;
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	// Сумма элементов самого первого столбца
	int sum = 0;
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			sum += A[j][i];
		}
		break;
	}
	
	// Поиск еще более меньшей суммы, если есть
	int find_sum;
	for(i = 0; i < M; i++)
	{
		find_sum = 0;
		for(j = 0; j < N; j++)
		{
			find_sum += A[j][i];
		}
		if(find_sum < sum)
			sum = find_sum;
	}
	
	// Проверка на то есть ли несколько самых минимальных столбцов + Вывод
	for(i = 0; i < M; i++)
	{
		find_sum = 0;
		for(j = 0; j < N; j++)
		{
			find_sum += A[j][i];
		}
		if(find_sum == sum)
			printf("%d ", i);
	}
	
	return 0;
}
