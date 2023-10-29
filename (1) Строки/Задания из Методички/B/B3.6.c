/*
Задана последовательность идентификаторов, разделенных одним или несколькими пробелами, оканчивающаяся подряд тремя символами '*'.
Каждый идентификатор содержит не более 15 символов. Длина последовательности не ограничена. Найти и напечатать все идентификаторы,
в точности совпадающие с предыдущим идентификатором.

asdf asdf apple banana banana***
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

// Измененная функция для проверки на длину слова
int isvalid(const char* msg, int len_maxword) // Макс. длина слова
{
	char* dupl = (char*)malloc((strlen(msg) + 1) * sizeof(char));
	strcpy(dupl, msg);
	
	char* token = strtok(dupl, " ");
	while (token != NULL) 
	{
		if (strlen(token) > len_maxword) 
		{
			free(dupl);
			return 1;
		}
		token = strtok(NULL, " ");
	}
	
	free(dupl);
	
	return 0;
}

void func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg, 15);
	if (status == 1) 
	{
		printf("Too many letters");
		return;
	}
	
	char* token = strtok(msg, " "); 
	char* pred_slovo = NULL;
	while (token != NULL) 
	{
		if (pred_slovo != NULL && strcmp(token, pred_slovo) == 0) 
		{
			printf("%s ", token);
		}
		pred_slovo = token;
		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[9999]; // 15 символов, длина последовательности не ограничена
	fgets(msg, 9999, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '*' || msg[len - 3] != '*' || msg[len - 4] != '*') { // *** | изначально (-2) - два лишних элемента: ('\n', '\0')
		printf("No!!!"); 
		return 1;
	}
	msg[len - 4] = '\0';
	
	func(msg);
	
	return 0;
}
