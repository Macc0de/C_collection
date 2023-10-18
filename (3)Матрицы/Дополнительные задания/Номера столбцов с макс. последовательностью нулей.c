/*
Вывести на экран номера столбцов с максимальной последовательность нулей подряд,
если таких нет, то вывести "-1"

1 0 1 0
0 0 0 0
0 1 0 1
1 0 1 0
0 0 0 0

2 1
1 1
-1

2 1
1 0
1

0 0 0
1 0 1
0 1 0
*/
#include <stdio.h>
#include <stdlib.h>

int* findLargestInMatrix(int** arr, int n, int m, int* result_size) 
{
    int max_len, i, j, len, count;
    int* col_nums = (int*)malloc(m * sizeof(int)); // Для столбцов
	max_len = 1; // Потому что len=0 
    count = 0;

    for (j = 0; j < m; j++) 
	{
        len = 0; // Перед каждым новым столбцом
        for (i = 0; i < n; i++) 
		{
            if (arr[i][j] == 0) 
			{
                len++;
            }
            else // Элем != 0
			{// Учытивая только один столбец с макс. кол-вом 0 столбцов
                if (len > max_len)
				{
                    max_len = len;
                    col_nums[0] = j;
                    count = 1;
                }
				/* Если нашли столбец в котором максимальное кол-во нулей максимальное и если 
				предыдущий элемент массива с результатами не равен текущей строке, то добавляем 
				текущую строку в массив результатов */
                else if (len == max_len && col_nums[count-1] != j)
				{
                    col_nums[count] = j;
                    count++;
                }
                len = 0;
            }
        }
		
        if (len > max_len) // Последний столбец
		{
            max_len = len;
            col_nums[0] = j;
            count = 1; // Нашли только один столбец с максимальной последовательностью нулей
        }
        else if (len == max_len && col_nums[count-1] != j) 
		{
            col_nums[count] = j;
            count++;
        }
        //len = 0; (возможно не нужно)
    }
    if (count == 0) // Если не нашли ни одного нуля
	{
        col_nums[0] = -1;
        count = 1;
    }
	
    *result_size = count;
	
    return col_nums;
}

int main() 
{
    int n, m, i, j, max_len, len, col_num;
	
    scanf("%d %d", &n, &m);
	
    int** arr = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) // Почему n?
        arr[i] = (int*)malloc(m * sizeof(int));
	
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < m; j++) 
		{
            scanf("%d", &arr[i][j]);
        }
    }

    int result_size = 0; // Кол-во столбцов
    int* cols = findLargestInMatrix(arr, n, m, &result_size); // Номера столбцов
	
    for (i = 0; i < result_size; i++) 
	{
        if (i == (result_size - 1)) // От пробела в последнем элементе
            printf("%d", cols[i]);
        else 
            printf("%d ", cols[i]);
    }

    for (i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    free(cols);
	
    return 0;
}
