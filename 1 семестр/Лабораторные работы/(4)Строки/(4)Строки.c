/* B3.9(1) Посимвольный ввод(!)
Длина слова не более 10, кол-во слов не более 40. Предложение оканчивается '.', '!' или '?'.
Написать программу, читающую два заданных предложения, контролирующую их правильность и
выполняющую функцию, которая:
1) Распечатывает все слова, которые встречаются в каждом из двух предложений.

mama Mila mila Ramy ram ma.
mhj RAM Ramy MIla mila jk?

apple pop pill Gnome friend!
gnome gnome Pop pop free.

one max two max min MaX opp one!
onE one one max max Opp two?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE_SENTENCE 440 // Размер предложения
#define MAX_WORDS 40 // Макс. кол-во слов
#define MAX_LEN 11 // Макс. длина слова
#define SIZE_NUMBER 7 // Размер для массива с номером предложения

int clean_spaces(char input, char* number_sentence) // Обработка значений input после while(Удаление лишних пробелов)
{
	if (input == '\n') // Проверка на завершающий символ
	{
		printf("%s sentence must be terminated with '.', '!' or '?'", number_sentence);
		return 1;
	}
	else if (!((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') // Проверка допустимых символов
		|| (input == ' ') || (input == '.' || input == '!' || input == '?')))
	{
		printf("%s sentence: You entered invalid symbol!", number_sentence);
		return 1;
	}

	return 0;
}

int input_sentence(char sentence[][MAX_LEN], int option) // Ввод предложения
{
	int count_symbols = 0, len_word = 0, count_words = 1, index_word = 0;
	char input, number_sentence[SIZE_NUMBER]; // Номер предложения

	if (option == 1) // Первое предложение
		strcpy(number_sentence, "First");
	else // Второе предложение
		strcpy(number_sentence, "Second");

	while (scanf("%c", &input)) // Ввод
	{
		if (input == '\n') // Проверка на завершающий символ
		{
			printf("%s sentence must be terminated with '.', '!' or '?'", number_sentence);
			return 0;
		}

		// Все допустимые символы
		if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')
			|| (input == ' ') || (input == '.' || input == '!' || input == '?'))
		{	
			if (input == ' ' && count_symbols != 0) // + чтобы пробел не записывало как слово
			{
				index_word++; // Индексация слов
				len_word = 0; // Начало слова
				count_words++; // Счётчик кол-ва слов
			}

			if (count_words > MAX_WORDS) // Проверка на кол-во слов
			{
				printf("%s Sentence: count of words exceeds %d!", number_sentence, MAX_WORDS);
				return 0;
			}

			while (input == ' ') // Обработка лишних пробелов
			{
				scanf("%c", &input);
			}
			if (clean_spaces(input, number_sentence) == 1) // Проверки значения input после while
				return 0;

			if (input == '.' || input == '!' || input == '?') // Завершающий символ
			{
				sentence[index_word][len_word] = '\0';
				break;
			}
			
			sentence[index_word][len_word] = input; // Запись в двумерный массив

			count_symbols++; // Кол-во символов в предложении
			len_word++; // Счётчик длины слов

			if (len_word > MAX_LEN - 1) // Проверка длины слова
			{
				printf("%s Sentence: word length exceeds %d!", number_sentence, MAX_LEN - 1);
				return 0;
			}

			if (count_symbols > SIZE_SENTENCE - 1) // Проверка на переполнение массива
			{
				printf("%s sentence: You entered too many symbols!", number_sentence);
				return 0;
			}
		}
		else // Если введен иной символ
		{
			printf("%s sentence: You entered invalid symbol!", number_sentence);
			return 0;
		}
	}
	
	if (count_symbols == 0) // Если строка пустая
	{
		printf("%s sentence is NULL!", number_sentence);
		return 0;
	}

	return count_words;
}

// Поиск и вывод слов, которые встречаются в каждом из двух предложений
int search_matching_words(char first_sentence[][MAX_LEN], char second_sentence[][MAX_LEN], int count_first, int count_second)
{
	int i, j, k, checked, flag = 0;
	for (i = 0; i < count_first; i++)
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

		for (j = 0; j < count_second; j++)
		{
			if (strcmp(first_sentence[i], second_sentence[j]) == 0) // Одинаковые слова?
			{
				printf("%s ", first_sentence[i]);
				flag = 1;
				break;
			}
		}
	}

	if (!flag) // Нет совпадающих слов
		return 1;

	return 0;
}

int main()
{
	int one = 1, two = 2, res1 = 0, res2 = 0, res3;

	char first_sentence[MAX_WORDS][MAX_LEN] = {0}; // Первое предложение
	char second_sentence[MAX_WORDS][MAX_LEN] = {0}; // Второе предложение

	printf("Enter the first sentence: ");
	res1 = input_sentence(first_sentence, one); // Кол-во слов
	if (res1 == 0)
		return 0;

	while (getchar() != '\n') // Очистка буфера
	{	}
	
	printf("Enter the second sentence: ");
	res2 = input_sentence(second_sentence, two); // Кол-во слов
	if (res2 == 0)
		return 0;
	
	printf("\n");
	
	// Поиск одинаковых слов в двух предложениях, используя массивы слов
	res3 = search_matching_words(first_sentence, second_sentence, res1, res2);
	if (res3)
		printf("No matches found!");

	return 0;
}
