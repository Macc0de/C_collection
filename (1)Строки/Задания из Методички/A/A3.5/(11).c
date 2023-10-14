// Распечативает все слова, состоящие из одинаковых букв и содержащие не менее двух символов
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	
	char* token = strtok(msg, " ");
	while (token != NULL) 
	{
		int len = strlen(token);
		int flag = 0; // Если = 0, то отсортирован
		for (int i = 1; token[i] != '\0'; i++) { // Проходимся от первого символа до последнего
			// Сравниваем текущий символ с предыдущим потому начинаем отсчет i с 1
			if (tolower(token[i]) != tolower(token[i - 1])) // i - 1 (предыдущий символ)
			{
				flag = 1; // Не отсортирован
				break;
			}
		}
		if (flag == 0 && len > 2) // Длина слова > 2
		{
			printf("%s ", token);
		}
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