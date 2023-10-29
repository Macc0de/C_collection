/*
Задана последовательность идентификаторов, разделенных ',', оканчивающаяся '*' сразу за последним идентификатором.
Каждый идентификатор содержит не более 15 символов. Длина последовательности не более 15 идентификаторов.
Найти и напечатать все идентификаторы, состоящие из четного кол-ва символов.
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
	int status = isvalid(msg, 15, 15);
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
	
	char identificator[15][15];
	int count_ident = 0;
	char* token = strtok(msg, ",");
	
	while (token != NULL) 
	{
		strcpy(identificator[count_ident], token);
		count_ident++;
		token = strtok(NULL, ",");
	}
	
	for (int i = 0; i < count_ident; i++) 
	{
		if (strlen(identificator[i]) % 2 == 0) // msg[i] - искомая строка	
			printf("%s ", identificator[i]);
	}
}

int main()
{
	char msg[225];
	fgets(msg, 225, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '*') 
	{ 
		printf("No!");
		return 1; 
	}
	msg[len - 2] = '\0';
	
	func(msg);
	
	return 0;
}