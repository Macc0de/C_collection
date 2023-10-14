// По заданному слову P определяет, встречается ли это слово в предложении не менее двух раз
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
	
	char P[20];
	scanf("%s", P);
	
	int counter = 0;
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		if (strcmp(token, P) == 0)
		{
			counter++;
		}
		token = strtok(NULL, " ");
	}
	printf("Meet %d times", counter);
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