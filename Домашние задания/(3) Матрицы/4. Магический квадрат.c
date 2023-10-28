/*
Вводится размер квадратной матрицы и ее элементы - целые числа.
Проверьте, является ли матрица "магическим квадратом". Если является, напечатайте "YES", если нет - "NO".

Магический квадрат — это квадратная матрица (таблица) чисел, сумма элементов которой по вертикали, 
горизонтали и в обеих диагоналях равна одному и тому же числу.

При решении задачи дополнительные массивы использовать нельзя.

Input: 
3
4 9 2
3 5 7
8 1 6
Output:
YES
*/
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int A[N][N];
	int i, j;
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	// Фиксированная сумма
	int sum = 0;
	for(i = 0; i < N; i++)
	{
		sum = 0;
		for(j = 0; j < N; j++)
		{
			sum += A[i][j];
		}
		break;
	}
	
	// Проверка каждой строки и столбца на сумму
	int tmp_row, tmp_col;
	for(i = 1; i < N; i++) // Первую строку не надо
	{
		tmp_row = 0;
		tmp_col = 0;
		for(j = 0; j < N; j++)
		{
			tmp_row += A[i][j];
			tmp_col += A[j][i];
		}
		if(tmp_row != sum || tmp_col != sum)
		{
			printf("NO");
			return 0;
		}
	}

	// Проверка элементов главной и побочной диагонали
	int tmp_main_diagonal = 0, tmp_side_diagonal = 0, j1;
	for(i = 0; i < N; i++)
	{
		for(j = i, j1 = N-i-1; j < N && j1 >= 0; j++, j1--)
		{
			tmp_main_diagonal += A[i][j];
			tmp_side_diagonal += A[i][j1];
			break;
		}
	}
	if(tmp_main_diagonal != sum || tmp_side_diagonal != sum)
	{
		printf("NO");
		return 0;
	}
	
	printf("YES");
	
	return 0;
}
