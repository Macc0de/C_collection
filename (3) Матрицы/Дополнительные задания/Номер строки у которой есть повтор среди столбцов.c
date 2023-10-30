/*
Вывод индексов строк у которых есть хотя бы один повтор среди столбцов.

Input: 
3
1 2 1
3 4 2
5 6 1
Output: 
0

Input: 
3
1 2 3
3 6 6
0 1 6
Output: 
1
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
	
	int k, flag, check, not_found = 0;
	for (i = 0; i < N; i++) 
	{
        flag = 0;
        for (j = 0; j < N; j++) 
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
                break;
            }
        }
        if (flag) 
		{
			not_found = 1;
            printf("%d ", i);
        }
    }
    
	if(!not_found) // Если ни один повтор не найден
		printf("-1");

	return 0;
}
