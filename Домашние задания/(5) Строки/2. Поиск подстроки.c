/*
Вводится предложение, содержащее слова, разделенные пробелами. Слова состоят из строчных букв латинского алфавита. 
Первое слово в предложении начинается с большой буквы. Ввод предложения заканчивается точкой.
Далее вводится слово - подстрока для поиска, состоящая из строчных букв латинского алфавита.

Написать программу, выводящую на печать номера слов, в которых встречается подстрока, заданная пользователем.
Если таких слов нет, вывести Not found.

При поиске подстроки регистр букв не учитывается

Input:
Mama mila ramy.
am
Output:
1 3
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void low_reg(char* word) // Перевод в нижний регистр
{
	while(*word)
	{
		*word = tolower(*word);
		word++;
	}
}

void remove_symbol(char* str, char symbol) // Удаление точки
{
	for(int i = 0; str[i]; i++)
		if(str[i] == symbol)
			str[i] = '\0';
}

int main()
{
	const int n = 1000;
	char sentence[n];
	
	fgets(sentence, n, stdin);
	remove_symbol(sentence, '.');
	
	char word[n];
	fgets(word, n, stdin);
	word[strcspn(word, "\n")] = '\0';
	
	int len_word = strlen(word);
	low_reg(word);
	
	int i, j, count = 1, flag = 0, check;
	char* token = strtok(sentence, " ");
	while(token)
	{
		low_reg(token);
		check = 0;
		
		for(i = 0, j = 0; token[i]; i++)
		{
			if(token[i] == word[j] && (j == 0 || check == 1)) // Поиск подстроки
			{
				check = 1;
				j++;
				if(j == len_word)
				{
					printf("%d ", count);
					flag = 1; // Найдена
					break;
				}
			}
			else
				check = 0;
		}
		count++;
		token = strtok(NULL, " ");
	}
	
	if(!flag)
		printf("Not found");
	
	return 0;
}
