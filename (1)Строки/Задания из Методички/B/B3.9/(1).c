// 1) Распечативает все слова, которые встречаются в каждом из двух предложений
#include <stdio.h>
#include <string.h>
#include "Header.h"

void func(char* msg, char* str) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg, 10, 40);
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
	
	int count_ident = 0, count_ident1 = 0;
	char identificator[40][10]; // Храним массив слов
	char identificator1[40][10];

	char* token = strtok(msg, " ");
	while (token != NULL) // Для первой строки
	{
		strcpy(identificator[count_ident], token);
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	token = strtok(str, " ");
	while (token != NULL) // Для второй строки
	{ 
		strcpy(identificator1[count_ident1], token);
		count_ident1++;
		token = strtok(NULL, " ");
	}
	
	for (int i = 0; i < count_ident; i++) 
	{
		char* word = identificator[i]; // Текущее слово в первой строке
		int flag = 0;
		for (int j = 0; j < count_ident1; j++) 
		{
			if (strcmp(word, identificator1[j]) == 0) // 0 если одинаковые
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			printf("%s ", word);
	}
}

int main()
{
	char msg[600];
	char str[600];
	fgets(msg, 600, stdin);
	fgets(str, 600, stdin);
	
	int len = strlen(msg);
	int len1 = strlen(str);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') 
	{
		printf("No!!!");
		return 1;
	}
	if (str[len1 - 2] != '.' && str[len1 - 2] != '!' && str[len1 - 2] != '?') 
	{
		printf("No!!!");
		return 1;
	} 
	*/
	msg[len - 1] = '\0';
	str[len1 - 1] = '\0';
	
	func(msg, str);
	
	return 0;
}