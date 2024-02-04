#include <stdio.h>
#define N 3

int main()
{
	int A[N][N] = {7, 2, 7, 2, 2, -10, 21, 5, 0};
	int i, j, flag = 0;
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", A[i][j]);
			
		printf("\n");
	}
	
	printf("\n");
	for (i = 0; i < N; i++)
	{	
		for (j = i; j < N; j++)
		{
			if (A[i] == A[j]) // Главная диагональ
				printf("[%d][%d] = %d\n", i, j, A[i][j]);	
		}
	}
	
	return 0;
}
