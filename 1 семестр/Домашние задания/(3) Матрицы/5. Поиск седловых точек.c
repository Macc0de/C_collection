/*
Вводится размер матрицы (количество строк и столбцов) и её элементы - целые числа.
Найти и вывести количество седловых точек в заданной матрице.

Матрица А имеет седловую точку Аij, если Аij является минимальным элементом в i-й строке и максимальным в j-м столбце.
Если матрица состоит из одинаковых элементов, число седловых точек равно числу элементов в матрице.

При решении задачи дополнительные массивы использовать нельзя.

Input: 
3 4
1 0 3 5
3 2 4 3
0 1 -1 4
Output:
1
*/
#include <stdio.h>
#include <stdlib.h>

// Проверка на самый минимальный элемент в строке
int check_row(int N, int M, int** mat, int element, int row)
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		if(mat[row][i] < element)
			return 0;
	}
	
	return 1; 
}

// Проверка на самый максимальный элемент в столбце
int check_col(int M, int N, int** mat, int element, int col)
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		if(mat[i][col] > element)
			return 0;
	}
	
	return 1;
}

int main() 
{
    int N, M;
    if(!scanf("%d %d", &N, &M))
		return 0;

    int** matrix = (int**)malloc(N * sizeof(int*));
	int i, j;
	for (i = 0; i < N; i++) 
	{
        matrix[i] = (int*)malloc(M * sizeof(int));
    }
	
    for (i = 0; i < N; i++) 
	{
        for (j = 0; j < M; j++) 
		{
            if(!scanf("%d", &matrix[i][j]))
				return 0;
        }
    }

	int count = 0;
    for (i = 0; i < N; i++) 
	{
		for(j = 0; j < M; j++)
		{
            if((check_row(N, M, matrix, matrix[i][j], i)) && (check_col(M, N, matrix, matrix[i][j], j)))
			{
				count++;
			}
        }
    }
	printf("%d", count);

    return 0;
}
