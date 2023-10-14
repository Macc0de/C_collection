// 4) Распечатывает слова, в которых чередуются гласные и согласные буквы
// abef koli aaa iaeo ooo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Вместо "Header.h"
int isvalid(const char* msg) 
{
	char* dupl = (char*)malloc((strlen(msg) + 1) * sizeof(char));
	strcpy(dupl, msg);
	char* token = strtok(dupl, " ");
	
	while (token != NULL) 
	{
		if (strlen(token) > 20) // Только длина слова
		{
			free(dupl);
			return 1;
		}
		token = strtok(NULL, " ");
	}
	
	free(dupl);
	
	return 0;
}

int is_vowels(char c) // Гласные
{
	const char* glas = "aeoui";
	int len = strlen(glas);
	
	for (int i = 0; i < len; i++) 
	{
		if (glas[i] == tolower(c)) 
			return 1; // OK
	}
	
	return 0; // No
}

void func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg);
	if (status == 1) 
	{
		printf("Too many letters");
		return;
	}
	
	char* token = strtok(msg, " ");
	while (token != NULL) 
	{
		if (strlen(token) < 2) // Проверка на последовательность (минимум 2 буквы)
		{
			token = strtok(NULL, " ");
			continue;
		}
		
		int uslovie = 0;
		for (int j = 0; token[j] != '\0'; j++)
		{
			if (!isalpha(token[j]) || isdigit(token[j])) // Чтобы только буквы
			{
				uslovie = 1;
				break;
			}
		}
		
		if (uslovie) 
		{
			token = strtok(NULL, " "); // Чтобы не был бесконечный цикл
			continue;
		}
		
		int flag = is_vowels(token[0]); // Предыдущий элемент
		int is_ok = 1;
		
		for (int i = 1; token[i] != '\0'; i++) // i = 1 (первый элемент уже проверили)
		{
			int count = is_vowels(token[i]); 
			if (count == flag) // Если одинаковые, то неверно 
			{
				is_ok = 0;
				break;
			}
			flag = count; // При след. итерации цикла - текущий элемент станет предыдущим
		}
		
		if (is_ok == 1)
			printf("%s ", token);

		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[9999];
	fgets(msg, 9999, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '#' || msg[len - 3] != '#' || msg[len - 4] != '#') 
	{
		printf("No!!!");
		return 1;
	}
	*/
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}