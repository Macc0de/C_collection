// По букве и целому K заменяет K-ю от конца букву каждого слова предложения на заданную букву и все измененные слова распечатывает
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
	scanf("%d", &K); // Номер буквы в слове
	getchar();
	scanf("%c", &P); 

	char* token = strtok(msg, " ");
	while (token != NULL) 
	{
		int len = strlen(token);
		token[len - K] = P; // Конкретный символ слова
		printf("%s ", token);
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
