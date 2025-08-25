/*
1 2 3
4 5 4
0 9 0
Вправо
3 1 2
4 4 5
0 0 9
Влево
2 3 1
5 4 4
9 0 0
*/
#include <stdio.h>

int func(int n, int regim, int N, int M, int A[][])
{
	int i, j;
	if (regim == 1)
	{
		for (i = 0; i < N; i++) // Вправо
		{
			int temp = A[i][M-1];
			for (j = M-1; j > 0; j--)
			{
				A[i][j] = A[i][j-1];
			}
			
			A[i][0] = temp;
		}
	}
	else if (regim == 2) // Влево
	{
		for (i = 0; i < N; i++)
		{
			int temp = A[i][0];
			for (j = 0; j < M-1; j++)
			{
				A[i][j] = A[i][j+1];
			}
			
			A[i][M-1] = temp;
		}
	}
	
	// Рекурсия
	if (n > 1) // Если без n позиций - убрать это
		func(n-1, regim, N, M, A); // Функция несколько раз выполняется
	else
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}

int main() 
{
	int n, i, j, N, M, choose;
	
	printf("Enter N and M: ");
	
	scanf("%d %d", &N, &M); 
	if (N > 20 || M > 20)
		printf("Error"); 
	
	int A[N][M];
	
	printf("Enter n position: ");
	scanf("%d", &n);
	
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
	
	if (choose == 1)
		printf("Vpravo stolbtsi:\n");
	else 
		printf("Vlevo  stolbtsi:\n");
	
	func(n, choose, N, M, A);
	
	return 0;
}
