/*
1 3 9
2 4 5
100 2 3

6 3 3
2 2 4
1 100 6
*/
#include <stdio.h>

int func(int N, int M, int A[][], int B[][])
{
	int flag = 0, is_found = 0;
	for (int j = M - 1; j >= 0; j--) // Столбец (Сверху - Вниз)
	{
		flag = 0;
		for (int i = 0; i < N - 1; i++) // Строка
		{
			if (A[i][j] > 1 || A[i + 1][j] > 1)
			{
				if (A[i][j] > A[i + 1][j]) // Не отсортирован
				{// < (возрастает), > (убывает)
					flag = 1; // Сортировка
				}
			}
		}
		
		if (flag == 0 && is_found == 0) // Если OK
		{
			is_found = 1; // Макс. столбец
			for (int i = 0; i < N; i++)
				B[i][j] = 0;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				B[i][j] = A[i][j];
			}
		}
	}
	
	if (is_found == 0)
		printf("\nNot found:\n");
	
	printf("\n");
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
//============================================================================================
// (2) Способ с функцией
#include <stdio.h>

int check(int N, int M, int A[][], int index)
{
	if (N == 0 || N == 1)
		return 1;
	
	for (int i = 0; i < N - 1; i++) // Строка
	{
		if (A[i][index] > 1 || A[i + 1][index] > 1)
		{
			if (A[i][index] > A[i + 1][index]) // Не отсортирован
			{ // < (возрастает), > (убывает)
				return 0;
			}
		}
	}
	
	return 1;
}

int func(int N, int M, int A[][], int B[][])
{
	int flag = 0;
	for (int j = M - 1; j >= 0; j--) // Столбец (Сверху - Вниз)
	{
		if (check(N, M, A, j) && flag == 0) // Передаю индекс
		{
			flag = 1;
			for (int i = 0; i < N; i++)
			{
				B[i][j] = 0;
			}
			continue; //вместо else
		}
	
		for (int i = 0; i < N; i++) // Иначе
		{
			B[i][j] = A[i][j];
		}
	}
	
	if (flag == 0)
		printf("\nNot found:\n");
	
	printf("\n");
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
