// Проверка на то является ли матрица симметричной относительно главной диагонали
#include <stdio.h>
#define N 2

int a[N][N];

int symmetry(int a[][])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (a[i][j] != a[j][i])
			{
				printf("No");
				return 1;
			}
		}
	}
	
	printf("Yes");
	
	return 1;
}
int main()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
	}
	
	symmetry(a);
	
	return 0;
}
//================================================================================
/* 
Проверка на то является ли матрица симметричной относительно побочной диагонали

Симметричные:
1 3 0
4 5 3
7 4 1

1 2 5
8 -7 2
0 8 1

Несимметричные:
1 2 3
4 5 6
7 8 9

1 2 3
2 5 7
3 7 1
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	
	printf("Enter size of array:\n");
	scanf("%d", &N);

	int** A = malloc(N * sizeof(int*));
	for(int i = 0; i < N; i++)
	{
		A[i] = malloc(N * sizeof(int));
	}
	
	printf("Enter elements of array:\n");
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	// Проверка
	int sim = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] != A[N-1-j][N-1-i]) // Текущий элемент и элемент в конце
            {
				printf("[%d][%d] - ", i, j); // Элементы которые не симметричны
                sim = 0;
                break;
            }
        }
		
        if (!sim)
            break;
    }
	
	if(sim)
		printf("Symmetric - %d", sim);
	else
		printf("Not symmetric - %d", sim);
	
	for(int i = 0; i < N; i++)
		free(A[i]);
	free(A);
	
	return 0;
}
