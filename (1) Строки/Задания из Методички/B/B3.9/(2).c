// 2) Находит самое короткое из слов первого предложения, которого нет во втором
// 99999 cat dogs crocodile
// 44444 dogs crocodile
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
	// Создаем их чтобы скопировать туда token, используем для циклов по взаимодействию с индексами слов
	char identificator[40][10]; 
	char identificator1[40][10];	

	char* token = strtok(msg, " ");
	while (token != NULL) 
	{ 
		strcpy(identificator[count_ident], token);
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	token = strtok(str, " ");
	while (token != NULL) 
	{ 
		strcpy(identificator1[count_ident1], token);
		count_ident1++;
		token = strtok(NULL, " ");
	}

	int min_len = -1;
	for (int i = 0; i < count_ident; i++) 
	{
		char* word = identificator[i];
		int flag = 0;
		
		for (int j = 0; j < count_ident1; j++) 
		{
			if (strcmp(word, identificator1[j]) == 0) 
			{
				flag = 1;
				break;
			}
		}
		
		if ((min_len == -1 && flag == 0) || (flag == 0 && strlen(word) < min_len)) 
			min_len = strlen(word); // word у нас с индексом выше
	}
	
	if (min_len == -1) // Проверка, если в первом и втором предложении все слова одинаковые
	{
		printf("No!!!");
		return;
	}
	
	for (int k = 0; k < count_ident; k++) 
	{
		int flag = 0;
		char* word = identificator[k];
		
		for (int m = 0; m < count_ident1; m++) 
		{
			if (strcmp(word, identificator1[m]) == 0) 
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0 && strlen(word) == min_len) // Значение min_len из прошлого цикла 
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