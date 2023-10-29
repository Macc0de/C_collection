/*
2) Между первым максимальным по модулю элементом последовательности и последним элементом, 
значение которого равно квадрату его порядкового номера

1 2 -60 3 2 6 1 49
20 -100 3 22 99 5 36 90
*/
#include <stdio.h>
#include <math.h>
#define place 1000

int is_max(int values[], int n) // Первый элемент
{
	int max = 0, first = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = abs(values[i]);
		if (temp > max)
		{
			max = temp;
			first = i;
		}
	}
	
	return first;
}

int is_sqr(int num) // Последний элемент
{
	for (int i = 0; i < num; i++)
	{
		if (num == i*i)
			return 1;
	}
	
	return 0;
}

int main()
{
	int first = -1, last, sum_abs = 0, num_even = 0, n, check, i, tmp;
	int values[place];

	printf("Input length: ");
	if (!scanf("%d", &n)) // Ввод длины
	{
		printf("Input error\n");
		return 0;
	}
	
	if (n < 1 || n > place) // Проверка длины
	{
		printf("Input error\n");
		return 0;
	}
	last = n; // По умолчанию, последний элемент = n

	printf("Input values:\n");
	for (i = 0; i < n; i++) // Заполнение массива
	{
		check = scanf("%d", &values[i]);
		if (check == 0)
		{
			printf("Input error\n");
			return 0;
		}
	}
	
	printf("Your array:\n");
	for (i = 0; i < n; i++) // Вывод массива
	{
		printf("%d ", values[i]);
	}
	
	first = is_max(values, n); // надо хранить промежуточный результат
	
	if (first == -1)
	{
		printf("\nAnswer: %d, %d\n", sum_abs, num_even);
		return 0;
	}
	
	for (i = first + 1; i < n; i++) // Поиск второго элема
	{
		if (is_sqr(values[i]))
		{
			last = i;
			break;
		}
	}
	
	printf("\nfirst - %d   last - %d", first, last); // (Для проверки)
	
	for (i = first + 1; i < last; i++)
	{
		if (values[i] % 2 == 0)
			num_even++; // Кол-во четных
		else
			sum_abs += abs(values[i]); // Сумма модулей нечетных
	}

	printf("\nSumma_nechet: %d. Count_chet: %d", sum_abs, num_even);
	
	return 0;
}

