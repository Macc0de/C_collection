/*
B2.4 (3 - 3)
Задана матрица A вещественных чисел размера NxN(N≤20). Построить по ней матрицу B того же размера, элементы которой
получаются: 3)Симметричным отражением элементов м-цы A относительно побочной диагонали.
И вычислить м-цу C: C = A*(B+E)+E

E - м-ца размера NxN, элементы которой, лежащие на главной диагонали, равны единице, остальные равны нулю.
На печать следует выдать м-цы A, B, C. Разрешается использовать не более трех массивов.

1 2
3 4

9.00 6.00
18.00 15.00
//////////////
4 -5 1
3 8 2
-5 -2 -3

1.00 -62.00 34.00
29.00 64.00 -27.00
-16.00 -2.00 -9.00
//////////////
1.23 3
4.11 8.86

16.07 10.38
45.58 33.09
//////////////
5.23 1.12 7.89
1.2 0 4.39
4 2 12.1

66.49 16.45 91.67
25.04 7.61 36.82
75.72 21.00 110.18
//////////////
6.16 2.01 5.13
7.18 4.67 1.51
3.25 9.89 8.99

76.21 60.61 72.37
89.85 52.75 57.03
123.50 127.16 101.92
//////////////
3.12 11.03 2.65 4.55
4.76 7.08 12.01 8.91
1.23 4.34 -2.49 6.66
7.13 13.24 1.74 -55.11

102.06 140.63 183.81 91.40
131.61 173.79 237.10 209.60
70.15 46.02 67.97 17.07
-298.40 125.39 -70.36 -139.33
*/
//#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int is_array_allocation(float** array) // Проверка массива на NULL
{
	if(array == NULL)
	{
		printf("Memory allocation error!");
		return 1;
	}	
	return 0;
}

int is_element_allocation(float* element) // Проверка элемента массива на NULL
{
	if(element == NULL)
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
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
			if(B[N-1-j][N-1-i] != B[i][j])
				B[N-1-j][N-1-i] = B[i][j];
        }
    }
	return;
}

void add_Matrix_E(int N, float** array) // Сложение исходной матрицы с единичной
{
	for(int i = 0; i < N; i++)
		array[i][i] += 1.0;
	return;
}

void mutiply_matrix(int N, float** A, float** B, float** C) // Умножение двух матриц
{
	int i, j, k;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for(k = 0; k < N; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return;
}

void print_matrix(int N, float** Matrix) // Вывод матрицы
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%.2f ", Matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

int main()
{
	int N, i, j; // Блок объявления переменных
	
	// Ввод размера массива + Проверка на его правильность
	printf("Enter size of array:\n");
	scanf("%d", &N);
	if(N > 20 || N < 1)
	{
		printf("Invalid N");
		return 0;
	}
	
	// Создание матрицы A + Проверки на выделение памяти
	float** A = (float**)malloc(N * sizeof(float*));
	if(is_array_allocation(A))
		return 0;
	
	for(i = 0; i < N; i++)
	{
		A[i] = (float*)malloc(N * sizeof(float));
		if(is_element_allocation(A[i]))
			return 0;
	}
	
	// Заполнение матрицы A + Проверка на правильность ввода
	printf("Enter elements of array:\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(!scanf("%f", &A[i][j]))
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
	if(is_array_allocation(B))
		return 0;
	
	for(i = 0; i < N; i++)
	{
		B[i] = (float*)malloc(N * sizeof(float));
		if(is_element_allocation(B[i]))
			return 0;
	}
	
	// Построение м-цы B, элементы которой - это симметричное отражение элементов м-цы A относительно побочной диагонали
	fillSymmetricMatrix(N, A, B);
	
	// Вывод матрицы B
	printf("Matrix B:\n");
	print_matrix(N, B);
	
	// (1) Действие(B + E), Сложение матрицы B с единичной
	add_Matrix_E(N, B);
	
	// Создание результирующей матрицы C + Проверки на выделение памяти
	float** C = (float**)malloc(N * sizeof(float*));
	if(is_array_allocation(C))
		return 0;
	
	for(i = 0; i < N; i++)
	{
		C[i] = (float*)malloc(N * sizeof(float));
		if(is_element_allocation(C[i]))
			return 0;
	}
	
	// (2) Действие(A x (B + E)) и запись результата в м-цу C
    // Умножение суммы с матрицей A
	mutiply_matrix(N, A, B, C);
	
	// (3) Действие (A x (B + E) + E) и запись результата в м-цу C
	// Сложение обновленных элементов м-цы C с единичной матрицей
	add_Matrix_E(N, C);
	
	// Вывод матрицы C
	printf("Result Matrix C by (C=A*(B+E)+E):\n");
	print_matrix(N, C);
	
	// Освобождение памяти
	for(i = 0; i < N; i++)
		free(C[i]);
	free(C);
	for(i = 0; i < N; i++)
		free(B[i]);
	free(B);
	for(i = 0; i < N; i++)
		free(A[i]);
	free(A);
	
	return 0;
}
