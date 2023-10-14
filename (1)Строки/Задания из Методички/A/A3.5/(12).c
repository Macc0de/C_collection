// Распечатывает все самые длинные слова предложения
// (1)
#include <stdio.h>
#include <stdlib.h>
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
	int status = isvalid(msg, 20, 30);
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
	
	int len = 0;
	int max_len = 0;
	char* dub = (char*)malloc((strlen(msg) + 1) * sizeof(char)); // Из-за msg
	strcpy(dub, msg);
	
	char* token = strtok(dub, " ");
	while (token != NULL)
	{ 
		len = strlen(token);
		if (len > max_len) 
		{
			max_len = len;
		}
		token = strtok(NULL, " ");
	}
	
	token = strtok(msg, " "); 
	while (token != NULL) 
	{
		if (strlen(token) == max_len) // = максимальной длине слова
		{
			printf("%s ", token);
		}
		token = strtok(NULL, " ");
	}
	free(dub);
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
// (2) Через дополнительный массив(identificator)
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
	int status = isvalid(msg, 20, 30);
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
	
	char identificator[15][15]; // [размер массива][размер строки] - [слова][буквы]
	int count_ident = 0;
	int max_len = 0;
	char* token = strtok(msg, " "); 
	
	while (token != NULL) 
	{
		strcpy(identificator[count_ident], token);
		count_ident++;

		int len = strlen(token);
		if (len > max_len) // Поиск максимальной длины
		{
			max_len = len;
		}
		token = strtok(NULL, " ");
	}

	for (int i = 0; i < count_ident; i++) 
	{ 
		int len = strlen(identificator[i]);
		if (len == max_len) 
		{
			printf("%s ", identificator[i]);
		}
	}
}

int main()
{
	char msg[225];
	fgets(msg, 225, stdin);
	
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