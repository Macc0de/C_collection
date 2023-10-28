/*
Вводится размер квадратной матрицы и её элементы - целые числа.
Найти и вывести такие значения k, что k-я строка матрицы совпадает с k-м столбцом.
(Совпадает столбец k со строкой k).
Если таких совпадений нет, выведите -1.

При решении задачи дополнительные массивы использовать нельзя.

Input:
4
1 2 3 4
2 6 9 0
3 9 3 2
4 -8 2 -5
Output: 
0 2

Input: 
3
1 2 3
3 6 6
0 1 6
Output: 
-1

Input:
3
0 1 0
1 1 1
0 1 0
Output:
0 1 2
*/
#include <stdio.h>

int main()
{
	int N;
	if(!scanf("%d", &N))
		return 0;
	
	int A[N][N];
	int i, j;
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(!scanf("%d", &A[i][j]))
				return 0;
		}
	}
	
	int k, flag, check, not_found = 0;
	for (i = 0; i < N; i++) 
	{
        flag = 0;
        for (j = i; j < N; j++) 
		{
            check = 1;
            for (k = 0; k < N; k++) 
			{
                if (A[i][k] != A[k][j]) 
				{
                    check = 0;
                    break;
                }
            }
            if (check) 
			{
                flag = 1;
            }
			break;
        }
        if (flag) 
		{
			not_found = 1;
            printf("%d ", i);
        }
    }
	if(!not_found)
		printf("-1");

	return 0;
}
