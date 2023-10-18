/* Проверка на то является ли матрица b квадартом м-цы a
1 2
3 4 

Answer:
7 10
15 22
*/
#include <stdio.h>
#define N 2

int a[N][N];
int b[N][N];

int square(int a[][], int b[][])
{
	int i, j, u, k, flag = 0;
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			k = 0;
			for (u = 0; u < N; u++)
			{
				k += a[i][u] * a[u][j]; // Умножает строку и столбец одной матрицы
			}
			
			printf("%d\n", k);
			
			if (b[i][j] != k)
				flag = 1;
		}
	}
	if (flag)
		printf("no");
	else
		printf("YES");

	return 0;
}
int main()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			scanf("%d", &b[i][j]);
	}
	
	square(a, b);
}
