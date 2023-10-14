// Функция, которая подключается к заданиям, где требуется определенная длина и кол-во слов
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isvalid(const char* msg, int len_maxword, int count_maxword) // Макс. длина слова, кол-во слов
{
	if (msg == NULL) 
		return 3;
	
	char* dupl = (char*)malloc((strlen(msg) + 1) * sizeof(char));
	strcpy(dupl, msg);
	
	int counter = 0;
	char* token = strtok(dupl, " ");
	while (token != NULL) 
	{
		if (strlen(token) > len_maxword) 
		{
			free(dupl);
			return 1;
		}
		counter++;
		token = strtok(NULL, " ");
	}
	
	if (counter > count_maxword) 
	{
		free(dupl);
		return 2;
	}
	
	free(dupl);
	
	return 0;
}
