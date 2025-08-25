// 3) По заданному слову P дает минимальный порядковый номер этого слова в предложении, если оно там встречается, или 0, если его там нет
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
	
	char P[20]; // Надо char* - строка(для слов)
	scanf("%s", P); // Без &
	int current_index = 0, min_index = -1;
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		int len = strlen(token);
		if (strcmp(token, P) == 0) 
		{
			min_index = current_index;
			break; // Следующая итерация не нужна, выход из цикла
		}
		current_index++; 
		token = strtok(NULL, " ");
	}
	if (min_index == -1) 
	{
		printf("Not found");
		return;
	}
	
	printf("%d ", current_index);
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