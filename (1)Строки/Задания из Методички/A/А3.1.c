/*
Задана последовательность идентификаторов(разделителем является ','), оканчивающаяся '.' сразу за последним идентификатором.
Каждый идентификатор содержит не более 40 символов. Длина последовательности не более 30 идентификаторов.
Найти и напечатать все идентификаторы с четным числом цифр в них.

1,2,3,22,444.
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
	int status = isvalid(msg, 40, 30);
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
	
	char identificator[30][40]; // [кол-во слов][длина слова]
	int count_ident = 0;
	
	char* token = strtok(msg, ","); // Времення переменная где хранится слово
	while (token != NULL) 
	{
		strcpy(identificator[count_ident], token);
		count_ident++;
		token = strtok(NULL, ","); 
	}
	
	for (int i = 0; i < count_ident; i++) 
	{ // count_ident - хранится кол-во слов
		if (strlen(identificator[i]) % 2 == 0) // msg[i] - искомая строка	
			printf("%s ", identificator[i]);
	}
}

int main()
{
	char msg[1200]; // 40 x 30
	fgets(msg, 1200, stdin);
	
	func(msg);
	
	return 0;
}