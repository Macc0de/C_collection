// 1) Определяет, упорядочены ли слова в предложении в лексикографическом порядке по возрастанию
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
	
	char* token = strtok(msg, " ");
	int flag = 1; // Отсортирован - 1, 0 - нет 
	char* pred_slovo = token; // Если вдруг изначально упорядочены || проходимся по каждому слову - сравниваем с предыдущим
	
	while (token != NULL) 
	{
		token = strtok(NULL, " "); // Надо сравнивать - тут строка полностью токенизирована(разбита)
		if (token != NULL && strcmp(pred_slovo, token) >= 0) // По возрастанию - слева направо(>=)
		{ // По убыванию - справа налево (<=) 
			// Все верно - strcmp возвращает число с (-), плохо или (+) или 0
			flag = 0;                      
			break;
		}
		pred_slovo = token;
	}
	
	if (flag == 0) 
		printf("Not sorted");
	else
		printf("Ok");
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