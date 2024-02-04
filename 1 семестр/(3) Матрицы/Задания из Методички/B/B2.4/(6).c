/*
1 0 2
3 4 3
6 7 8

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4

6 3 1
7 4 0
8 3 2
*/
#include <stdio.h>

int func(int N, int A[][])
{
	int i, j;	
	int B[N][N];
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			B[i][N-j-1] = A[j][i];
			//B[N-i-1][j] = A[j][i] - против часовой
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
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
	func(N, A);
	
	return 0;
}
