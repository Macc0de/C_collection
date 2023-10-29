/*
Задана последовательность идентификаторов, разделенных одним или несколькими пробелами, оканчивающаяся ',' сразу за последним
идентификтором. Каждый индентификатор содержит не более 20 символов. Длина последовательности не более 35 идентификторов.
Найти и напечатать все идентификаторы, не содержащие цифр.
*/
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
	int status = isvalid(msg, 20, 35);
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
	
	// msg - одна строка
	// identificator - массив из слов(слово как элемент через запятые)
	char identificator[35][20]; // [кол-во слов][длина слова]
	int count_ident = 0;
	
	char* token = strtok(msg, ","); // Переменная переменная где хранится слово
	while (token != NULL) // Для разделения слов по запятым
	{
		strcpy(identificator[count_ident], token); // Копируем в identificator
		count_ident++;
		token = strtok(NULL, ","); // Для работы с результатом вызванной функции
	}
	
	for (int i = 0; i < count_ident; i++) // count_ident - хранится кол-во слов
	{
		int is_digits = 0; // Локальная переменая для цикла
		int len = strlen(identificator[i]);
		for (int j = 0; j < len; j++) 
		{
			if (isdigit(identificator[i][j])) // Явл. ли цифрой
			{
				is_digits = 1;
				break;
			}
		}
		if (is_digits == 0 && len > 0) 
		{ 
			printf("%s ", identificator[i]);
		}
	}
}

int main()
{
	char msg[700];
	fgets(msg, 700, stdin);
	
	func(msg);
	
	return 0;
}
