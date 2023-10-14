// Выдает вектор длин слов в предложении
// (1)
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
	
	int len = 0;
	char* token = strtok(msg, " "); 
	
	while (token != NULL) 
	{ 
		len = strlen(token); 
		printf("%d ", len);
		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') {
		printf("No!!!");
		return 1;
	} */
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}
//===============================================================================
// (2) С возвращением через массив
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int* func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return NULL; // int* функция
	}
	int status = isvalid(msg, 20, 30);
	if (status == 1) 
	{
		printf("Too many letters");
		return NULL;
	}
	else if (status == 2) 
	{
		printf("Too many words");
		return NULL;
	}
	
	int* result = (int*)malloc(30 * sizeof(int));
	int counter = 0;
	int len = 0;
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		len = strlen(token);
		result[counter++] = len; // номер элемента массива
		token = strtok(NULL, " ");
	}
	
	return result;
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') {
		printf("No!!!");
		return 1;
	} */
	msg[len - 1] = '\0';
	
	int* res = func(msg);
	if (res == NULL) // Проверка указателя
	{
		printf("NO");
		return 1;
	}
	
	// Вывод через массив вектора длин
	for (int i = 0; res[i] != 0; i++) 
	{
		printf("%d ", res[i]);
	}
	
	free(res);
	
	return 0;
}
