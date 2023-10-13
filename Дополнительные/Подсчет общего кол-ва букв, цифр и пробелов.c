// Подсчет общего кол-ва букв, цифр и специальных символов(пробелы) в строке
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isalpha()

void func(char* msg)
{
	int alphabets = 0, digits = 0, special_characters = 0, i;
	
	for (i = 0; msg[i] != '\0'; i++) 
	{
		if (isalpha(msg[i])) // является ли буквой
		{
			alphabets++;
		}
		else if (isdigit(msg[i])) 
		{
			digits++;
		}
		else if (msg[i] == ' ')
			special_characters++;
	}
	
	printf("Total score: %d %d %d ", alphabets, digits, special_characters);
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	
	func(msg);
	
	return 0;
}
