/* 
1 0 3
4 2 8
0 0 0

1 1 1
2 2 2
3 3 3

0 0 1
0 2 0
0 0 0
*/
#include <stdio.h>

int func(int N, int M, int A[][])
{
	int strok[30] = {};
	int col[30] = {};
	
	int flag;
	for (int i = 0; i < N; i++) // По строкам
	{
		flag = 1;
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != 0)
			{
				flag = 0;
				break;
			}
		}
		
		strok[i] = flag; // либо 0, либо 1
	}
	
	for (int j = 0; j < M; j++) // По столбцам
	{
		flag = 1;
		for (int i = 0; i < N; i++)
		{
			if (A[i][j] != 0)
			{
				flag = 0;
				break;
			}
		}
		
		col[j] = flag;
	}
	
	int is_Ok = 0;
	for (int i = 0; i < N; i++) // Если нулевая полностью
	{
		if (strok[i] || col[i]) // (!= 0 || != 0) // (== 1 || == 1)
		{
			is_Ok = 1;
			break;
		}
	}
	
	// Если нет хотябы одной полностью нулевой строки или столбца
	if (!is_Ok)
	{
		printf("\nNULL");
		return 1;
	}
	
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		if (strok[i]) // Пропускает нулевые строки, выводим только там где у нас в массиве 0
			continue;
			
		for (int j = 0; j < M; j++)
		{
			if (col[j])
				continue;
			
			printf("%d ", A[i][j]); // Только когда в проверке false -> выводит строку или столбец ненулевые
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
	
	int A[N][M];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	func(N, M, A);
	
	return 0;
}
