// По букве и целому K строит вектор номеров строк, содержащих эту букву в K-й позиции
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
		return NULL;
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
	
	int K = 0;
	char P; // Буква
	scanf("%d", &K); 
	getchar(); 
	scanf("%c", &P);   
	
	int* sum = (int*)malloc(30 * sizeof(int)); 
	memset(sum, 0, 30); // Без него не работает - заполняет память нулями
	int index = 0;

	char* token = strtok(msg, " ");
	int count_ident = 0;
	while (token != NULL) 
	{
		if (token[K] == P) 
		{
			sum[index++] = count_ident;
		}
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	return sum;
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
	
	int* res = func(msg);
	
	for (int i = 0; res[i] != 0; i++) 
		printf("%d ", res[i]); // Номера слов
	
	return 0;
}
