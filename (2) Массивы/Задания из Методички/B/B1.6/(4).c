// 4) Между первым минимальным положительным элементом последовательности и последним элементом, 
// значение которого по модулю больше квадрата его порядкового номера
// 5 2 1 5 12 15 -40 3
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
	
	int min = 0;
	for (i = 0; i < n; i++) // Поиск первого элема
	{
		if (values[i] > 0)
		{
			min = values[i];
			first = i; // Самый первый который нашли
			break;
		}
	}
	
	for (i = first; i < n; i++)
	{
		if (values[i] > 0 && values[i] < min)
		{
			min = values[i];
			first = i;
		}
	}
	
	if (first == -1)
	{
		printf("\nAnswer: %d, %d\n", sum_abs, num_even);
		return 0;
	}
	
	for (i = first + 1; i < n; i++) // Поиск второго элема
	{
		tmp = abs(values[i]);
		if (tmp > i * i)
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
