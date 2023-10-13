// Поиск наиболее часто встречающегося символа в строке
#include <stdio.h>
#include <string.h>

void func(char* msg) 
{
	int i, j;
	int count[30] = {0};
	int len = strlen(msg);
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++) // j = i - ищем с текущего символа
		{
			if (msg[i] == msg[j])
			{
				count[i]++;
			}
		}
	}
	
	int max_count = 0;
	int max_index = 0;
	for (j = 0; j < len; j++) // Можно и i
	{
		if (count[j] > max_count)
		{
			max_count = count[j];
			max_index = j;
		}
	}
	
	printf("%c ", msg[max_index]); // Сам символ
	printf("%d ", max_count); // Кол-во потвор. символов
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	
	func(msg);
	
	return 0;
}
