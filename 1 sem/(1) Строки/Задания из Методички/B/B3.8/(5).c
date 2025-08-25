// 5) Определяет, сколько раз каждое слово встречается в предложении
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
	
	char identificator[30][20]; // Массив слов
	char* token = strtok(msg, " ");
	int counter[30] = {}; // Массив счетчик
	int count_ident = 0;
	
	while (token != NULL)
	{
		strcpy(identificator[count_ident++], token);
		token = strtok(NULL, " ");
	}
	
	for (int i = 0; i < count_ident; i++) 
	{
		for (int j = 0; j < count_ident; j++) 
		{
			if (strcmp(identificator[i], identificator[j]) == 0)
				counter[i]++; // Увеличиваем значение по индексу для каждого слова, если есть повтор.
		}
	}
	
	for (int k = 0; k < count_ident; k++) 
	{
		int flag = 0;
		for (int m = 0; m < k; m++) 
		{ // Проходимся от начала и до текущего символа(проверяем не встречали ли его раньше)
			if (strcmp(identificator[k], identificator[m]) == 0)
				flag = 1;
		}
		if (flag == 0)
			printf("%s:%d\n", identificator[k], counter[k]);
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