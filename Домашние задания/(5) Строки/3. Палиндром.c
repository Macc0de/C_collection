/*
Вводится предложение, содержащее слова, разделенные пробелами. Слова состоят из букв латинского алфавита. 
Первое слово в предложении начинается с большой буквы. Ввод предложения заканчивается точкой.

Написать программу, которая печатает YES, если введенное предложение является палиндромом, 
и NO - в противном случае, а после выводит на печать исходное предложение.

При решении задачи пробелы и регистр букв не учитываются.

Input:
A roza upala na lapu Azora.
Output:
YES
A roza upala na lapu Azora.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void low_reg(char* word)
{
	while(*word)
	{
		*word = tolower(*word);
		word++;
	}
}

void remove_symbol(char* str, char symbol) // Удаление символа
{
	for(int i = 0; str[i]; i++)
		if(str[i] == symbol)
			str[i] = '\0';
}

int palindrome(char* str) // Проверка на палиндром
{
	int len = strlen(str);
	int first = 0, last = len - 1;
	
	while(first < last)
	{
		if (tolower(str[first]) != tolower(str[last]))
			return 0;
		
		first++;
		last--;
	}
	return 1;
}

int main()
{
	const int n = 500;
	char sentence[n];
	
	fgets(sentence, n, stdin);
	
	char cpy_sentence[n];
	strcpy(cpy_sentence, sentence); // Копия для вывода в конце

	remove_symbol(cpy_sentence, '\n');
	remove_symbol(sentence, '.');
	
	char* token = strtok(sentence, " ");
	char str[n];
	memset(str, 0, sizeof(str)); // Чтобы не было мусора в строке
	
	while(token)
	{
		low_reg(token);	
		strcat(str, token); // Слияние в одну сплошную строку
		token = strtok(NULL, " ");
	}
	
	int result = palindrome(str); // str - целая строка
	if(result)
		printf("YES\n");
	else
		printf("NO\n");
	
	printf("%s", cpy_sentence);
	
	return 0;
}
