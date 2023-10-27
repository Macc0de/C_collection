/*
A1.1 (6)
Между первым не принадлежащим диапазону от -5 до 7 элементом последовательности и
последним элементом послед., значение которого < его порядокового номера.

В случае, если не существует такого первого элемента, значения искомых сумм полагаются равными
нулю, в случае отсутствия описанного последнего элемента суммирование производится до конца последовательности.


3: -6 3 1
COUNT: 1. SUM:  3.
6: -10 0 1 2 3 8
COUNT: 3. SUM:  3.
7: -5 -3 1 0 -8 9 0
COUNT: 1. SUM:  9.
6: -5 -6 4 5 1 7
COUNT: 2. SUM:  9.
7: 0 1 2 3 -5 -4 4 (Если не нашли первый элемент)
COUNT: 0. SUM:  0.
9: -5 -4 -3 -8 8 9 10 11 15 (Если не нашли последний элемент, то считаем до конца)
COUNT: 5. SUM:  53.
11: -4 0 1 -12 8 9 10 13 14 2 90
COUNT: 5. SUM:  54.
*/
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int first_element, last_element, N = 0, i = 0, flag = 0, sum = 0, count = 0, low_border = -5, up_border = 7; // Блок описания переменных

	// (1) Ввод размера массива
	printf("Enter array size:\n");
	if (!scanf("%d", &N) || N < 0) // Проверка на правильность ввода
	{
		printf("Incorrect value of N!");
		return 0;
	}

	// (2) Заполнение массива
	if (N == 0)
	{
		printf("No elements\n");
	}
	else
		printf("Enter array elements:\n");

	//int array[N], last_element = N;
	last_element = N;
	int* array = (int*)malloc(N * sizeof(int));
	if (array == NULL)
	{
		printf("Memory error!");
		return 0;
	}

	while (i < N)
	{
		if (!scanf("%d", &array[i])) // Проверка на правильность ввода
		{
			printf("Incorrect value of element!");
			return 0;
		}
		i++;
	}

	// (3) Поиск первого элемента, не принадлежащий диапазону от -5 до 7
	for (i = 0; i < N; i++)
	{
		if (array[i] < low_border || array[i] > up_border)
		{
			first_element = i;
			flag = 1;
			break;
		}
	}
	// Если не нашли первый элемент
	if (!flag)
	{
		printf("Count of elements:  %d\nSum of elements:  %d", count, sum);
		return 0;
	}
	//printf("FIRST:  %d", first_element);

	// (4) Поиск последнего элемента, значение которого меньше его порядкового номера
	for (i = first_element + 1; i < N; i++)
	{
		if (array[i] < i)
		{
			last_element = i;
		}
	}
	//printf("\nLAST:  %d\n", last_element);

	// (5) Подсчёт суммы и кол-ва элементов между первым и последним
	for (i = first_element + 1; i < last_element; i++)
	{
		sum += array[i];
		count++;
	}

	printf("Count of elements:  %d\nSum of elements:  %d", count, sum);

	free(array);

	return 0;
}
