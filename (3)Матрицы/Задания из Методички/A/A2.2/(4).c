/* 
6 3 1
1 2 -10
6 7 900	
1 2 3
*/
#include <stdio.h>

int check(int arr[], int M)
{
    // Отсортирован уже
    if (M == 0 || M == 1)
        return 1;
	
    for (int i = 1; i < M; i++)
	{
		if (arr[i] % 2 == 0 || arr[i - 1] % 2 == 0)
			return 0;
		if (arr[i - 1] < arr[i]) // Не отсортирован
			return 0;
    }
	
    return 1;
}

int func(int N, int M, int A[][], int B[][])
{
	int flag = 0;
	// От последней строки находим строку подходящую и ее записываем
	for (int i = N - 1; i >= 0; i--)
	{	
		if (check(A[i], M) && flag == 0) // M - кол-во элементов в столбце
		{
			flag = 1;
			for (int j = 0; j < M; j++)
			{
				B[i][j] = 0;
			}
			continue;
		}
		
		for (int j = 0; j < M; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	
	if (flag == 0)
		printf("\nNot found:\n");
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int main() 
{
	int i, j, N, M;
	
	printf("Enter N and M: ");
	
	scanf("%d %d", &N, &M);
	if (N > 20 || M > 20)
		printf("Error");
	
	int A[N][M], B[N][M];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	func(N, M, A, B);
	
	return 0;
}
