// Вывести цифры которые повторяются, если нету - вывести массив
// 1 1 1 2 2
#include <stdio.h>
int main()
{
	int mas[30] = {};
	int povtor[30] = {};
	int i, j, k = 0;
	
	i = 0;
	while (i < 5)
	{
		scanf("%d", &mas[i]);
		i++;
	}
	printf("\n");
	
	int check = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (mas[i] == mas[j])
				check = 1;
		}
	}
	
	if (check == 0) // Вообще нет повторов
	{// Написал, потому что если повторов нет - программа ничего не выводит ранее
		for (i = 0; i < 5; i++)
		{
			printf("%d ", mas[i]);
		}
	}
	
	for (i = 0; i < 5; i++)
	{
		int flag = 0;
		for (j = 0; j < 5; j++)
		{
			if (mas[i] == mas[j])
			{
				flag++; // flag = 1(нет повторов)
			}
		}
		
		if (flag > 1) // Есть ли вообще повторы
		{
			int is_ok = 0;
			for (int m = 0; m < k; m++)
			{
				if (povtor[m] == mas[i]) // Для вывода уже - повтор элементы не нужны
				// (повторы уже известны, просто выводим цифры 1 раз)
				{
					is_ok = 1;
					break;
				}
			}
			
			if (is_ok == 0) // Выводим 1 раз
			{
				printf("%d ", mas[i]);
				povtor[k++] = mas[i];
			}
		}
	}
	
	return 0;
}
