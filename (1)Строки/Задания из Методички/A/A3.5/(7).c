// По букве дает максимальный номер слова, оканчивающегося этой буквой
#include <stdio.h>
#include <stdlib.h>
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
	
	char bukva;
	scanf("%c", &bukva);
	
	char* dub = (char*)malloc((strlen(msg) + 1) * sizeof(char)); // Из-за msg
	strcpy(dub, msg);
	
	char* token = strtok(dub, " ");
	int max_index = -1; // (-1) чтобы не было пересечения с 0
	int current_index = 0;
	
	while (token != NULL) 
	{
		int len = strlen(token);
		if (token[len - 1] == bukva) // = нужной букве
		{
			max_index = current_index; // Перезапись max_index
		}
		current_index++; // Кол-во слов
		token = strtok(NULL, " ");
	}
	if (max_index == -1) 
	{
		printf("No words with this last letter!");
		free(dub); // Поскольку тут программа закончится, то освобождаем также память
		return; 
	}

	token = strtok(msg, " ");
	current_index = 0;
	while (token != NULL) 
	{ 
		if (current_index == max_index) 
		{
			printf("%s ", token);
			break; 
		}
		current_index++;
		token = strtok(NULL, " "); // " " - char*, ' ' - char
	}
	/* Через цикл for
	for (token = strtok(msg, " " ); token != NULL; token = strtok(NULL, " ")) 
	{
		if (current_index == max_index) 
		{
			printf("%s ", token);
			break; 
		}
		current_index++;
	}
	*/
	free(dub);
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