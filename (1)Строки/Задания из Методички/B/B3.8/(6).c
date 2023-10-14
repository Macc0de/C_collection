// 6) Распечатывает все слова предложения, у которых доля гласных букв максимальна 
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
	
	int count_ident = 0, max = 0;
	const char* str_vowels = "aeouyi"; // Гласные
	int len1 = strlen(str_vowels);
	char identificator[30][20];
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		int vowels = 0; // Чтобы с каждой итерацией обновлялась(надо для цикла)
		strcpy(identificator[count_ident], token); // Копируем слова и второй раз по ним проходимся вне цикла while
		
		for (int i = 0; token[i] != '\0'; i++) 
		{
			for (int j = 0; j < len1; j++) 
			{
				if (tolower(token[i]) == str_vowels[j]) // Дважды проверяем кол-во гласных
				{
					vowels++;
					break;
				}
			} 
		}
		
		if (vowels > max) // max каждый раз перезаписуем на значение больше предыдущего
			max = vowels;
			
		count_ident++; // Для for
		token = strtok(NULL, " ");
	}
	
	for (int k = 0; k < count_ident; k++) // k - номер индекса слова в предложении
	{
		vowels = 0;
		for (int i = 0; identificator[k][i] != '\0'; i++) // k - token
		{
			for (int j = 0; j < len1; j++) 
			{
				if (tolower(identificator[k][i]) == str_vowels[j]) // i текущая буква
				{
					vowels++;
					break;
				}
			}
		}
		if (vowels == max)
			printf("%s ", identificator[k]); // Текущее слово
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