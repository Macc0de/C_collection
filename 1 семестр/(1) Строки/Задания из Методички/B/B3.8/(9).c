// Распечатывает слова предложения, упорядочивая их по длине, начиная с минимального
// jjkjjl ty popo x
// x ty popo jjkjjl
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
	
	char identificator[30][20]; // Массив для хранения слов
	int size[30] = {}; // Массив длин
	int count_ident = 0;
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		size[count_ident] = strlen(token); // Для текущего слова записываем его индекс
		strcpy(identificator[count_ident], token); // Можно прописать тут и count_ident++
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	// Сортировка пузырьком
	int chTemp = 0;
	for (int i = 0; i < count_ident; i++)
	{
		for (int j = 0; j < (count_ident - 1); j++) 
		{
			if (size[j] > size[j + 1]) 
			{
				// Сортировка длин слов
				chTemp = size[j]; 
				size[j] = size[j + 1]; 
				size[j + 1] = chTemp;
				
				// Сортировка самих слов
				char tmpWord[20];
				strcpy(tmpWord, identificator[j]); 
				strcpy(identificator[j], identificator[j + 1]);
				strcpy(identificator[j + 1], tmpWord);
			}
		}
	}
	
	for (int i = 0; i < count_ident; i++) 
		printf("%s ", identificator[i]);
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