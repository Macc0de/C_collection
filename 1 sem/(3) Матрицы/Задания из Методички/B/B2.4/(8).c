/*
1 2 3
4 5 6
0 0 1

3 6 1
2 5 0
1 4 0
*/
#include <stdio.h>

int func(int count, int N, int A[][]) // count - кол-во поворотов на 90°
{
	int i, j, k;	
	int B[N][N];
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			B[i][N-j-1] = A[j][i];
		}
	}
	
	// Рекурсия
	if (count > 1) // Два раза выполняется
		func(count-1, N, B);
	else
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%d ", B[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}

int main() 
{
	int i, j, N;
	
	printf("Enter N: ");
	
	scanf("%d", &N); 
	if (N > 20)
		printf("Error"); 
	
	int A[N][N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("\n");
	func(3, N, A); // 3 раза по 90° = 270°
	
	return 0;
}
