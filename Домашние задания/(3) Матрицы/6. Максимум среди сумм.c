/*
Вводится размер квадратной матрицы и её элементы - целые числа.

Найти и вывести максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы.
Угловые элементы должны рассматриваться, как диагонали.

При решении задачи не допускается использование дополнительных массивов

Input:
3
1 2 3
4 5 6
7 8 9
Output:
12
*/
#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

	int i, j;
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            scanf("%d", &matrix[i][j]);
        }
    }

    int max_sum = matrix[0][0];
    int sum, k;

    for (i = 1; i < n; i++) 
	{
        sum = 0;
		for(j = 0, k = i; k < n; k++, j++)
		{
            sum += matrix[k][j];
        }
        if (sum > max_sum) 
		{
            max_sum = sum;
        }
    }

    for (i = 1; i < n; i++) 
	{
        sum = 0;
        for(k = 0, j = i; j < n; k++, j++)
		{
            sum += matrix[k][j];
        }
        if (sum > max_sum) 
		{
            max_sum = sum;
        }
    }

    printf("%d", max_sum);

    return 0;
}
