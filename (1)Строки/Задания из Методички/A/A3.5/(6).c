// По слову печатает кол-во вхождений его буквы в предложение(повторно встречающиеся в слове буквы игнорировать)
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
	
	char word[20];
	scanf("%s", word);
	
	for (int i = 0; word[i] != '\0'; i++) { // По каждому символу строки
		int flag = 0;
		for (int j = 0; j < i; j++) 
		{ 	// Если word[i] == word[j] то пропустим; 
			if (word[i] == word[j]) // Чтобы не дублировались буквы
			{
				flag = 1; 
				break; // Ничего дальше не проверяем
			}
		}
		if (flag)
			continue;
		int counter = 0; // msg[k]
		for (int k = 0; msg[k] != '\0'; k++) 
		{
			if (msg[k] == word[i]) // Текущий символ = текущему слову во всем предложении которое получили
				counter++;
		}
		printf("%c %d\n", word[i], counter);
	}
	// с 27 по 36 строку - Валидация данных(проверка текущей буквы чтобы не было повторов в слове)
	// с 37 по 43 строку - Поиск совпадений буквы word[i] во всем предложении
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