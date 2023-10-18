/* 
Транспонирование матрицы

1 1
2 2

Answer:
1 2
1 2
*/
#include <stdio.h>
#define N 2
#define M 2

int A[N][M];
int At[N][M];

int func(int A[][], int At[][])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			At[j][i] = A[i][j];
		}
	}
	
	return 0;
}

int main() 
{
	int i, j;
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	func(A, At);
	printf("\n");

	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", At[i][j]);
		}
		printf("\n");
	}

	return 0;
}