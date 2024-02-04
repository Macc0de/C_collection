/* B3.9(1) Без посимвольного ввода(!)
Длина слова не более 10, кол-во слов не более 40. Предложение оканчивается '.', '!' или '?'.
Написать программу, читающую два заданных предложениях, контролирующую их правильность и
выполняющую функцию, которая:
1) Распечатывает все слова, которые встречаются в каждом из двух предложений.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Проверки предложений на пустоту и завершающий символ
int check_end(char* first_sentence, char* second_sentence)
{
	// Подсчёт длины строк
	int i, first_len = strlen(first_sentence), second_len = strlen(second_sentence);
	
	// Проверка строк на пустоту
	if(first_len == 0 || second_len == 0)
	{
		printf("Empty sentence!");
		return 1;
	}
	
	// Удаление из строк '\n'
	first_sentence[first_len - 1] = '\0'; 
	second_sentence[second_len - 1] = '\0';
	
	// Проверка предложений на символ завершения
	if(first_sentence[first_len - 2] != '.' 
	&& first_sentence[first_len - 2] != '!' 
	&& first_sentence[first_len - 2] != '?')
	{
		printf("First sentence must be terminated with '.', '!' or '?'");
		return 1;
	}
	if(second_sentence[second_len - 2] != '.' 
	&& second_sentence[second_len - 2] != '!' 
	&& second_sentence[second_len - 2] != '?')
	{
		printf("Second sentence must be terminated with '.', '!' or '?'");
		return 1;
	}
	
	// Удаление заверщающего символа
	first_sentence[first_len - 2] = '\0'; 
	second_sentence[second_len - 2] = '\0';
	
	return 0;
}

// Проверка предложений на соответствие латинскому алфавиту
int check_letters(char* first_sentence, char* second_sentence)
{
	int i;
	for(i = 0; first_sentence[i]; i++)
	{
		if(first_sentence[i] == ' ') // Пробел пропускаем
			continue;
		
		if(!isalpha(first_sentence[i])) // Проверка на латиницу
		{
			printf("First sentence contains Invalid Symbol!");
			return 1;
		}
	}
	for(i = 0; second_sentence[i]; i++)
	{
		if(second_sentence[i] == ' ') // Пробел пропускаем
			continue;
			
		if(!isalpha(second_sentence[i])) // Проверка на латиницу
		{
			printf("Second sentence contains Invalid Symbol!");
			return 1;
		}
	}
	
	return 0;
}

// Проверка на длину слов и кол-во слов + Получение кол-ва слов в предложении
int check_sentence(char* sentence, char (*array_words)[10], int option)
{
	int max_len = 10, max_count = 40, count_words = 0;
	char number_sentence[7]; // Номер предложения
	
	if(option == 1) // Первое предложение
		strcpy(number_sentence, "First");
	else // Второе предложение
		strcpy(number_sentence, "Second");
	
	// Деление предложения на слова
	char* token = strtok(sentence, " ");
	while(token)
	{
		if(strlen(token) > max_len) // Проверка длины слова
		{
			printf("%s Sentence: word length exceeds 10!", number_sentence);
			return 1;
		}
		
		// Запись слова в массив
		strcpy(array_words[count_words], token);
		
		count_words++; // Подсчёт кол-ва слов
		token = strtok(NULL, " ");
	}
	
	if(count_words > max_count) // Проверка на кол-во слов
	{
		printf("%s Sentence: count of words exceeds 40!", number_sentence);
		return 1;
	}
	
	return count_words; // Кол-во слов
}

// Поиск и вывод слов, которые встречаются в каждом из двух предложений
int search_matching_words(char first_sentence[][10], char second_sentence[][10], int count_first, int count_second)
{
	int i, j, k, flag = 0, checked;
	for(i = 0; i < count_first; i++)
	{
		// Чтобы не выводило дубликаты из первого предложения
		checked = 0;
		for (k = 0; k < i; k++)
		{
			if (strcmp(first_sentence[i], first_sentence[k]) == 0)
			{
				checked = 1;
				break;
			}
		}

		if (checked)
			continue; // Пропустит повтор первого предложения
		
		for(j = 0; j < count_second; j++)
		{
			if(strcmp(first_sentence[i], second_sentence[j]) == 0) // Одинаковые слова?
			{
				printf("%s ", first_sentence[i]);
				flag = 1;
				break;
			}
		}
	}
	
	if(!flag) // Нет совпадающих слов
		return 1;
	
	return 0;
}

int main()
{
	int size_sentence = 440, count_words = 40, len_word = 11;
	char first_sentence[size_sentence];
	char second_sentence[size_sentence];
	
	printf("Enter the first sentence: ");
	fgets(first_sentence, size_sentence, stdin);
	printf("Enter the second sentence: ");
	fgets(second_sentence, size_sentence, stdin);
	
	// Проверка предложений на завершающий символ
	int res1 = check_end(first_sentence, second_sentence);
	if(res1)
		return 0;
	
	// Проверка предложений на латинский алфавит
	int res2 = check_letters(first_sentence, second_sentence);
	if(res2)
		return 0;
	
	char first_words[count_words][len_word]; // Массив слов первого предложения
	char second_words[count_words][len_word]; // Массив слов второго предложения
	
	// Проверка длины и кол-ва слов в предложениях + Заполнение массивов слов + Получение кол-ва слов
	res1 = check_sentence(first_sentence, first_words, 1);
	if(!res1)
		return 0;
	res2 = check_sentence(second_sentence, second_words, 2);
	if(!res2)
		return 0;
	
	// Поиск одинаковых слов
	int res3 = search_matching_words(first_words, second_words, res1, res2); // Передача массивов слов
	if(res3)
		printf("No matches found!");
	
	return 0;
}
