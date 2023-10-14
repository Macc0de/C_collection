/*
2) По заданному целому K печатает все слова длинны K

app le call tree ko
*/
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
	scanf("%d", &K);
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		if (strlen(token) == K) 
		{
			printf("%s ", token); // Слова длинны K
		}
		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') {
		printf("No!!!");
		return 1;
	}
	msg[len - 2] = '\0';
	
	func(msg);
	
	return 0;
}