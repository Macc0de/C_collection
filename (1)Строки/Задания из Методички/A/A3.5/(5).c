// По заданному целому K и букве P дает кол-во вхождений буквы P в K-е слово предложения
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
	
	int K = 0;
	char P;
	int len = 0;
	scanf("%d", &K); // Номер слова
	getchar(); // Убирает перенос строки от первого scanf
	scanf("%c", &P); 
	
	char* token = strtok(msg, " ");
	int counter = 0;
	int count_ident = 0;
	
	while (token != NULL) 
	{
		if (K == count_ident) // = номеру текущего слова
		{
			for (int i = 0; token[i] != '\0'; i++) // Цикл в нужном слове
			{
 				if (token[i] == P) 
					counter++;
			}
			printf("%s %d", token, counter);
		}
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
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') {
		printf("No!!!");
		return 1;
	} */
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}