// 2) Распечатывает слова с четными номерами в обратном порядке
// Первый вариант: 1 2 3 4 5 6
// hello dlrow how -> hello (world) how
#include <stdio.h>
#include <string.h>
#include "Header.h"

void func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg, 20, 20);
	if (status == 1) 
	{
		printf("Too many letters");
		return;
	}
	else if (status == 2) 
	{
		printf("Too many words");
		return;
	}
	
	int count_ident = 1; // Для нумерации с 1
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		int len = strlen(token);
		if (count_ident % 2 == 0) // Только со словами с четным индексом
		{
			for (int i = len; i >= 0; i--) // Обратный порядок (i >= 0 - по индексу с нуля)
			{
				printf("%c", token[i]);
			}
			printf(" ");
		}
		else
			printf("%s ", token);
		
		count_ident++;
		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') 
	{
		printf("No!!!");
		return 1;
	} 
	*/
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}

//==================================================================================
// Второй вариант: 1 2 3 4 5 6 -> 1 6 3 4 5 2
#include <stdio.h>
#include <string.h>
#include "Header.h"

void func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg, 20, 20);
	if (status == 1) 
	{
		printf("Too many letters");
		return;
	}
	else if (status == 2) 
	{
		printf("Too many words");
		return;
	}
	
	char identificator[20][20] = {}; // Четные
	int index[15] = {};
	int count_ident = 0;
	int count_index = 0; // Четные
	char* token = strtok(msg, " ");
	
	while (token != NULL)
	{
		count_ident++; // Слова с 1 отсчет
		if (count_ident % 2 == 0) // Если текущий индекс четный
		{
			index[count_index++] = count_ident - 1; // Заносим в массив четных текущее слово (-1 - отсчет с нуля)
		}
		strcpy(identificator[count_ident - 1], token);
		token = strtok(NULL, " ");
	}
	for (int i = 0; i < count_ident; i++)
	{
		if ((i + 1) % 2 == 0) // Проверка что следующий четный
		{
			printf("%s ", identificator[index[count_index - 1]]); // (-1 - отсчет с нуля)
			count_index--; // В обратном порядке
		}
		else // Для нечетных
			printf("%s ", identificator[i]);
	}
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') 
	{
		printf("No!!!");
		return 1;
	} 
	*/
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}
//==================================================================================
// Третий вариант: для другой проверки - с четного начинается
// 2 3 4 5 6 -> 6 3 4 5 2
#include <stdio.h>
#include <string.h>
#include "Header.h"

void func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg, 20, 20);
	if (status == 1) 
	{
		printf("Too many letters");
		return;
	}
	else if (status == 2) 
	{
		printf("Too many words");
		return;
	}
	
	char identificator[20][20] = {}; // Четные
	int index[15] = {};

	int count_ident = 0;
	int count_index = 0; // Четные
	char* token = strtok(msg, " ");
	
	while (token != NULL)
	{
		if (count_ident % 2 == 0) // Если текущий индекс четный
		{
			index[count_index++] = count_ident; // Заносим в массив четных текущее слово
		}
		strcpy(identificator[count_ident++], token);
		token = strtok(NULL, " ");
	}
	
	for (int i = 0; i < count_ident; i++)
	{
		if (i % 2 == 0) // Проверка что следующий четный
		{
			printf("%s ", identificator[index[count_index - 1]]); // (-1 - отсчет с нуля)
			count_index--; // В обратном порядке
		}
		else // Для нечетных
			printf("%s ", identificator[i]);
	}
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') 
	{
		printf("No!!!");
		return 1;
	} 
	*/
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}

