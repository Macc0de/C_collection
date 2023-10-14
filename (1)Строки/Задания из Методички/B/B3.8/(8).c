// 8) Распечативает слова предложения, в соответствии с ростом доли согласных букв
// laptop car pinapple
#include <stdio.h>
#include <string.h>
#include "Header.h"

float vowel_count(char* msg) // Считает долю согласных
{
	int result = 0; // Хранит общее кол-во согласных
	int len = strlen(msg);
	const char* consonants = "bcdfghjklmnpqrstvwxyz"; // Согласные
	
	if (len == 0) 
		return 0;
	
	for (int i = 0; i < len; i++) 
	{
		for (int j = 0; consonants[j] != '\0'; j++) 
		{
			if (msg[i] == consonants[j]) 
			{
				result++;
				break;
			}
		}
	}
	return (float)result / len; // Вычетаем чтобы получить согласные
}

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
	
	int count_ident = 0;
	char identificator[30][20]; // Храним массив слов
	float mas_vowel[30] = {}; // Массив частоты гласных
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		strcpy(identificator[count_ident], token);
		float result = vowel_count(identificator[count_ident]);
		mas_vowel[count_ident] = result;
		
		printf("mas_vowel[%d] = %f\n", count_ident, result); // По соотношению кол-ва согласных
		
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	// Вывести слова в соответствии с ростом доли согласных букв(сортировка пузырьком)
	float chTemp = 0;
	for (int i = 0; i < count_ident - 1; i++) 
	{
		for (int j = i + 1; j < count_ident; j++) // j = i + 1 (не должны сортировать то что сортировали)
		{
			if (mas_vowel[i] > mas_vowel[j]) // Текущий элемент больше чем следующий - меняем местами
			{
				chTemp = mas_vowel[i];
				mas_vowel[i] = mas_vowel[j];
				mas_vowel[j] = chTemp;
				char tmpWord[20];
				strcpy(tmpWord, identificator[i]);
				strcpy(identificator[i], identificator[j]);
				strcpy(identificator[j], tmpWord);
			}
		}
	}
	
	for (int i = 0; i < count_ident; i++) // Для вывода после сортировки 
		printf("%s ", identificator[i]);
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	/*
	if (msg[len - 2] != '.' && msg[len - 2] != '!' && msg[len - 2] != '?') 
	{
		printf("No!!!");
		return 1;
	} 
	*/
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
}