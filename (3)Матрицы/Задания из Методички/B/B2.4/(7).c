/*
1 0 2
3 4 3
6 7 8

1 2 3
5 6 7
9 10 11

11 10 9
7 6 5
3 2 1

8 7 6
3 4 3
2 0 1
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
			B[N-i-1][N-j-1] = A[i][j]; // Можно также и с A[j][i]
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
