// Преобразовать исходную матрицу в обратную
#include <stdio.h>
#define N 2
#define M 2

int A[N][M]; 
float A_obr[N][M];

int Det(int A[N][M]) // Определитель
{
	return A[0][0] * A[1][1] - A[1][0] * A[0][1];
}

void Transp(int A[N][M], float A_obr[N][M]) // Обратную транспонированую матрицу миноров(Результат)
{
	float Opred = Det(A);
	int i, j;
	int Minor[N][M] = {};
	int Trans[N][M] = {};
	
	if (Opred == 0)
	{
		printf("\nError determinanta, plz change!\n");
		exit();
	}
	
	Minor[0][0] = A[1][1];
	Minor[1][0] = -A[0][1];
	Minor[0][1] = -A[1][0];
	Minor[1][1] = A[0][0];
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			Trans[i][j] = Minor[j][i];
		}
	}
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			A_obr[i][j] = (float)(1 / Opred) * Trans[i][j];
		}
	}
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
	
	Transp(A, A_obr);
	printf("\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%1.1f   ", A_obr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}