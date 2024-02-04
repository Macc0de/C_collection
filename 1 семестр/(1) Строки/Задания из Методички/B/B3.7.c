/*
Задана последовательность идентификаторов, разделенных одним или несколькими пробелами, оканчивающаяся подряд тремя символами '#'.
Каждый идентификатор содержит не более 20 символов. Длина последовательности не ограничена. Найти и напечатать все идентификаторы,
в которых буквы и цифры чередуются(первой может быть буква, так и цифра).

f2g3h5 6j7v 9l ll lome
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isvalid(const char* msg, int max_len) 
{
	char* dupl = (char*)malloc((strlen(msg) + 1) * sizeof(char));
	strcpy(dupl, msg);
	char* token = strtok(dupl, " ");
	
	while (token != NULL) 
	{
		if (strlen(token) > max_len) 
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
	int status = isvalid(msg, 20);
	if (status == 1) 
	{
		printf("Too many letters");
		return;
	}
	
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		if (strlen(token) < 2) // Проверка на длину (минимум 2)
		{
			token = strtok(NULL, " "); 
			continue;
		}
		
		int uslovie = 0;
		
		for (int j = 0; token[j] != '\0'; j++) 
		{ // Чтобы только буквы и цифры
			if (!isalpha(token[j]) && !isdigit(token[j])) 
			{
				uslovie = 1;
				break;
			}
		}
		if (uslovie) 
		{
			token = strtok(NULL, " "); // Чтобы не был бесконченый цикл
			continue;
		}
		
		int flag = isalpha(token[0]); // Предыдущий элемент
		int is_ok = 1; 
		
		for (int i = 1; token[i] != '\0'; i++) 
		{ // i = 1 (первый элем уже проверили)
			int count = isalpha(token[i]); // Возвращает если буква - 0, если цифра - 1
			if (count == flag) 
			{ // Если одинаковые, то неверно
				is_ok = 0; 
				break; 
			}
			flag = count; // При след. итерации цикла - текущий элемент станет предыдущим
		}
		if (is_ok == 1) 
		{
			printf("%s ", token);
		}
		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[9999];
	fgets(msg, 9999, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '#' || msg[len - 3] != '#' || msg[len - 4] != '#') 
	{
		printf("No!!!");
		return 1; 
	}
	msg[len - 4] = '\0';
	
	func(msg);
	
	return 0;
}