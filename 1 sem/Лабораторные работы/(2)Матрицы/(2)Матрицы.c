/* B2.4(3, 3)
Финальная версия с правильным отражением и оптимизированной функцией formula.

Задана матрица A вещественных чисел размера NxN(N≤20). Построить по ней матрицу B того же размера, элементы которой
получаются: 3) симметричным отражением элементов м-цы A относительно побочной диагонали
И вычислить м-цу C: C = A*(B+E)+E
1 2
3 4

12.00 6.00
27.00 15.00
//////////////
4 -5 1
3 8 2
-5 -2 -3

-2.00 -34.00 34.00
-32.00 85.00 -27.00
29.00 -37.00 -9.00
//////////////
1.23 3
4.11 8.86

25.46 10.38
76.94 33.09
//////////////
5.23 1.12 7.89
1.2 0 4.39
4 2 12.1

103.31 33.55 91.67
33.28 11.54 36.82
104.80 34.08 110.18
//////////////
6.16 2.01 5.13
7.18 4.67 1.51
3.25 9.89 8.99

99.09 57.53 72.37
122.82 49.16 57.03
159.50 125.53 101.92
//////////////
3.12 11.03 2.65 4.55
4.76 7.08 12.01 8.91
1.23 4.34 -2.49 6.66
7.13 13.24 1.74 -55.11

-81.10 21.44 203.34 91.40
-22.70 85.24 266.89 209.60
-44.49 -0.89 75.67 17.07
-732.66 -32.48 -25.72 -139.33
//////////////
*/
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int is_array_allocation(float** array) // Проверка массива на NULL
{
	if (array == NULL)
	{
		printf("Memory allocation error!");
		return 1;
	}
	return 0;
}

int is_element_allocation(float* element) // Проверка элемента массива на NULL
{
	if (element == NULL)
	{
		printf("Memory allocation error!");
		return 1;
	}
	return 0;
}

// Заполнение матрицы B элементами м-цы A так чтобы было симметричное отражение относительно побочной диагонали
void fillSymmetricMatrix(int N, float** A, float** B)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	/* (2) Способ - Нижний треугольник
	for (i = N - 1; i >= 0; i--)
		for (j = N - 1; j >= 0; j--)
	*/
	float temp;
	for (i = 0; i < N; i++) // Верхний треугольник
	{
		for (j = 0; j < N; j++) 
		{
			if(B[N - 1 - j][N - 1 - i] == B[i][j])
				break;
			
			temp = B[i][j];
			B[i][j] = B[N - 1 - j][N - 1 - i];
			B[N - 1 - j][N - 1 - i] = temp;
		}
	}
	return;
}

void formula(int N, float** A, float** B, float** C) // Формула (C = A*(B+E)+E)
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < N; k++)
			{
				if(k == j) // + Cложение E с главной диагональю B
					C[i][j] += A[i][k] * (B[k][j] + 1.0);
				else 
					C[i][j] += A[i][k] * B[k][j];
			}
		}
		C[i][i]++;
	}
	return;
}

void print_matrix(int N, float** Matrix) // Вывод матрицы
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%.2f ", Matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

int main()
{
	int N, i, j, high_border = 20, low_border = 1; // Блок объявления переменных

	// Ввод размера массива + Проверка на его правильность
	printf("Enter size of array:\n");
	scanf("%d", &N);
	if (N > high_border || N < low_border)
	{
		printf("Invalid N!");
		return 0;
	}

	// Создание матрицы A + Проверки на выделение памяти
	float** A = (float**)malloc(N * sizeof(float*));
	if (is_array_allocation(A))
		return 0;

	for (i = 0; i < N; i++)
	{
		A[i] = (float*)malloc(N * sizeof(float));
		if (is_element_allocation(A[i]))
			return 0;
	}

	// Заполнение матрицы A + Проверка на правильность ввода
	printf("Enter elements of array:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!scanf("%f", &A[i][j]))
			{
				printf("Incorrect value of element!");
				return 0;
			}
		}
	}

	// Вывод матрицы A
	printf("\nMatrix A:\n");
	print_matrix(N, A);

	// Создание матрицы B + Проверки на выделение памяти
	float** B = (float**)malloc(N * sizeof(float*));
	if (is_array_allocation(B))
		return 0;

	for (i = 0; i < N; i++)
	{
		B[i] = (float*)malloc(N * sizeof(float));
		if (is_element_allocation(B[i]))
			return 0;
	}

	// Построение м-цы B, элементы которой - это симметричное отражение элементов м-цы A относительно побочной диагонали
	fillSymmetricMatrix(N, A, B);
	
	// Вывод матрицы B
	printf("Matrix B:\n");
	print_matrix(N, B);

	// Создание результирующей матрицы C + Проверки на выделение памяти
	float** C = (float**)malloc(N * sizeof(float*));
	if (is_array_allocation(C))
		return 0;

	for (i = 0; i < N; i++)
	{
		C[i] = (float*)malloc(N * sizeof(float));
		if (is_element_allocation(C[i]))
			return 0;
	}

	// Заполнение м-цы C элементами, полученными через формулу (С = A*(B + E)+E)
	formula(N, A, B, C);

	// Вывод матрицы C
	printf("Result Matrix C by (C = A*(B+E)+E):\n");
	print_matrix(N, C);

	// Освобождение памяти
	for (i = 0; i < N; i++)
		free(C[i]);
	free(C);
	for (i = 0; i < N; i++)
		free(B[i]);
	free(B);
	for (i = 0; i < N; i++)
		free(A[i]);
	free(A);

	return 0;
}
