// Распечатывает каждое слово предложения, меняя его первую букву на прописную, если необходимо
// apple. energy. golf
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
	
	char* token = strtok(msg, " ");
	char* pred_slovo = NULL; // char* храним предыдущую строку
	int len_pred = 0;
	int count_ident = 0;
	
	while (token != NULL) 
	{
		if (pred_slovo != NULL) // Есть ли пред. слово
		{
			len_pred = strlen(pred_slovo);
		}
		
		if (islower(token[0]) && ((count_ident == 0) || (pred_slovo != NULL && pred_slovo[len_pred - 1] == '.'))) 
		{ // Проверка на строчную букву
			token[0] = toupper(token[0]); // Замена на прописную
		}
		
		int len = strlen(token);
		for (int i = 1; i < len; i++) 
		{
			if (isupper(token[i])) // Является ли буква большой
			{ // Каждый символ проверяет 
				token[i] = tolower(token[i]);
			}
		}
		count_ident++;
		
		printf("%s ", token); // Вывод
		pred_slovo = token; // Для следующей итерации
		token = strtok(NULL, " ");
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