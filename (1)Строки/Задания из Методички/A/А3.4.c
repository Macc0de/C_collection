/*
Задана последовательность идентификаторов, разделенных одним или несколькими пробелами, оканчивающася '.' сразу за последним идентификатором.
Каждый идентификатор содержит не более 12 символов. Длина последовательности не более 36 идентификаторов.
Найти и напечатать все идентификаторы, состоящие из заглавных букв.

asdf Asdsf ASDSAD fghLjjk.
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
	int status = isvalid(msg, 12, 36);
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
	
	char identificator[36][12];
	int count_ident = 0;
	char* token = strtok(msg, " ");
	
	while (token != NULL) // Для разделения слов по пробелам
	{
		strcpy(identificator[count_ident], token); // Копируем в identificator
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	for (int i = 0; i < count_ident; i++) 
	{ 
		int is_digits = 0;
		int len = strlen(identificator[i]);
		for (int j = 0; j < len; j++) 
		{
			if (islower(identificator[i][j])) 
			{ // Либо исп. (identificator[i][j] <= 'Z' && identificator[i][j] >= 'A') - если нужно вывести слова хотябы с одной заглавной буквой
				is_digits = 1;
				break;
			}
		}
		if (is_digits == 0 && len > 0)
			printf("%s ", identificator[i]);
	}
}

int main()
{
	char msg[432];
	fgets(msg, 432, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '.') { // (-2) потому что fgets делает в конце перенос строки
		printf("No!!!");
		return 1;
	}
	msg[len - 2] = '\0'; // если последнее слово полностью заглавными чтобы . не выводило
	
	func(msg);
	
	return 0;
}