/*
1 2 3
4 5 4
0 9 0
Вниз
0 9 0
1 2 3
4 5 4
Вверх
4 5 4
0 9 0
1 2 3
*/
#include <stdio.h>

int func(int regim, int N, int M, int A[][])
{
	int i, j;
	if (regim == 1) // Вниз
	{
		printf("Vniz stroki:\n");
		for (j = 0; j < M; j++)
		{
			int temp = A[N-1][j];
			for (i = N-1; i > 0; i--)
			{
				A[i][j] = A[i-1][j];
			}
			
			A[0][j] = temp;
		}
	}
	else if (regim == 2) // Вверх
	{
		printf("Vverh stroki:\n");
		for (j = 0; j < M; j++)
		{
			int temp = A[0][j];
			for (i = 0; i < N-1; i++)
			{
				A[i][j] = A[i+1][j];
			}
			
			A[N-1][j] = temp;
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

int main() 
{
	int i, j, N, M, choose;
	
	printf("Enter N and M: ");
	
	scanf("%d %d", &N, &M); 
	if (N > 20 || M > 20)
		printf("Error"); 
	
	int A[N][M];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Enter regim(1 or 2) : ");
	scanf("%d", &choose);
	
	if (choose != 1 && choose != 2)
	{
		printf("Incorrect value.");
		return 1;
	}
	
	func(choose, N, M, A);
	
	return 0;
}
