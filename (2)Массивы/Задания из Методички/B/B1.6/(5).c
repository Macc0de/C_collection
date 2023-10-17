/*
5) Между первым максимальным отрицательным элементом последовательности и последним элементом, 
значение которого по модулю меньше его порядкового номера

5 -7 -8 4 5 6 3 5
-4 -2 -10 5 6 7 -4 5 
*/
#include <stdio.h>
#include <math.h>
#define place 1000

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
	
	int max = 0;
	for (i = 0; i < n; i++) // Поиск первого отрицательного элемента
	{
		if (values[i] < 0)
		{
			max = values[i];
			first = i;
			break;
		}
	}
	
	for (i = first; i < n; i++) // Поиск первого элемента(максимальный отрицательный)
	{
		if (values[i] < 0 && values[i] > max)
		{
			max = values[i];
			first = i;
		}
	}
	
	if (first == -1)
	{
		printf("\nAnswer: %d, %d\n", sum_abs, num_even);
		return 0;
	}
	
	for (i = first + 1; i < n; i++) // Поиск последнего элемента(значение по модулю < его порядкового номера)
	{
		tmp = abs(values[i]);
		if (tmp < i)
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
