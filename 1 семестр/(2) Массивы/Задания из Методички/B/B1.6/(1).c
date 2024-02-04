/*
1) Между первым являющимся точным квадратом элементом последовательности и последним элементом, 
значение которого по модулю больше его порядкового номера

0 1 2 3 4 5 6 7 8 9
1 0 4 2 3 4 9
2 0 1 9 -2 -3 -4 -1 -7 14
*/
#include <stdio.h>
#include <math.h>
#define place 1000

int is_sqr(int num) // Проверка на квадрат(Первый элемент)
{
	for (int i = 0; i < num / 2; i++) 
	{
		if (pow(i, 2) == num)
			return 1;
	}
	
	return 0;
}

int main()
{
	int first = -1, last = -1, sum_abs = 0, num_even = 0, n, check, i, tmp, j;
	int values[place]; // Массив

	printf("Input length: ");
	if (!scanf("%d", &n)) // Ввод длины
	{
		printf("Input error\n");
		return 0;
	}
	
	if (n < 1 || n > place) // Проверки длины
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

	for (i = 0; i < n; i++) // Поиск первого элема(Квадрат)
	{
		if (is_sqr(values[i]))
		{
			first = i;
			break;
		}
	}
	
	if (first == -1)
	{
		printf("\nAnswer: %d, %d\n", sum_abs, num_even);
		return 0;
	}
	
	for (i = first + 1; i < n; i++) // Поиск второго элемента(Значение которого по модулю > его пор. номера)
	{
		tmp = abs(values[i]);
		if (tmp > i)
		{
			last = i;
			break;
		}
	}
	
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
