// Поиск наиболее часто встречающегося слова в строке
#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h> // strlen ()
#include <ctype.h> // tolower()
#define N 30

char* stroka(const char* s) // Вместо strdup
{
	char* d = (char*)malloc(strlen(s) + 1); // +1 из за '\0'  
	if (d == NULL) // Проверка на память
		return NULL;     
		
	strcpy(d, s); // d - буфер назначения, туда копируем s
	
	return d;      
}

void func(char* msg) 
{ 
	int i, j ;
	char* words[N];
	int count[N] = {0}; // Счетчик
	char* token = strtok(msg, ","); // Разбиение строки на части по указанному разделителю
	
	while (token != NULL) 
	{
		for (i = 0; i < strlen(token); i++)
			token[i] = tolower(token[i]); // Переводим в нижний регистр
		
		words[j] = stroka(token); // strdup - копирует строку
		j++; // Увеличиваем кол-во слов, которые добавили words[j]
		
		token = strtok(NULL, ","); 
	}
	
	for (i = 0; i < j; i++) // Встречающиеся слова
	{
		for (j = 0; j < N; j++)
		{
			if (strcmp(words[i], words[j]) == 0) // Сравнение строк. Если одинаковые возвращает 0
			{ // words[i] имеет нулевое значение для сравнения с тем где есть
				count[j]++; 
				break;
			}
		}
	}
	
	int max_count = 0;
	int max_index = 0;
	for (i = 0; i < N; i++)
	{
		if (count[i] > max_count)
		{
			max_count = count[i];
			max_index = i; // Будет выводить по индексу слова которые повтор.
		}
	}
	
	printf("%s ", words[max_index]); // strawberry,banana,apple,apple
	printf("%d ", max_count); // Кол-во потвор слов
}

int main()
{
	char msg[N];
	fgets(msg, N, stdin);
	
	func(msg);
	
	return 0;
}
