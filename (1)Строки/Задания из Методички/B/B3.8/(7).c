// 7) Определить, является ли предложение палиндромом(пробелы при этом игнорировать)
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
	
	int len = strlen(msg);
	int perviy = 0, posledniy = len - 1;
	
	while (perviy < posledniy) 
	{
		while (perviy < posledniy && isspace(msg[perviy])) // Пропуск пробелов
			perviy++;	
		while (perviy < posledniy && isspace(msg[posledniy])) // Пропуск пробелов
			posledniy--;
			
		// Перенос строки тоже считается как пробел - пропуск
		if (tolower(msg[perviy]) != tolower(msg[posledniy])) 
		{
			printf("No!!!");
			return;
		}
		
		perviy++; // Слева направо
		posledniy--; // Справа налево
	}
	printf("Yes");
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