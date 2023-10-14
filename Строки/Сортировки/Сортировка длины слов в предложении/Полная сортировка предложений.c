/* 
Сортировка предложений по кол-ву слов и слов в предложениях по длине.
СНАЧАЛА ДЕЛАЕМ МАССИВ ДЛЯ ТОЧЕК(ПРЕДЛОЖЕНИЯ), ПОТОМ ДРУГОЙ МАССИВ КУДА ЗАНОСИМ ЭТОТ МАССИВ С ЛОГИКОЙ ТОЧЕК И ЗАНОСИМ ТУДА СЛОВА(ДЛЯ ДЛИНЫ)

ahsladl xz cate dog. me hiw2 worldo. jh78 vc kl.
333 1 22. 1 22 4444 333 55555. 1 333 4444 22.
4444 hal 1 r4. kln0 xz 5 hgd9gjd.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
/*
int is_number(char* massiv)
{
	for (int i = 0; massiv[i]; i++)
	{
		if (!isdigit(massiv[i]))
			return 0;
	}
	return 1;
}
*/
int func(char* str) 
{
	int count_ident = 0; // Кол-во предложений
	char identificator[N][N] = {0};
	
	char* token = strtok(str, " ");
	while (token != NULL) 
	{
		int len = strlen(token);
		strcat(identificator[count_ident], token); // Пробелы, слова сохраняются все на своих местах
		strcat(identificator[count_ident], " ");
		if (token[len - 1] == '.')
		{
			count_ident++;
		}
		token = strtok(NULL, " ");
	}
	/* for (int i = 0; i < count_ident; i++) // Отсортировали предложения(от наибольшего до наименьшого кол-ва слов)
	{
		for (int j = 0; j < (count_ident - 1); j++) 
		{
			if (strlen(identificator[j]) < strlen(identificator[j + 1]))
			{
				char tmpWord[N];
				strcpy(tmpWord, identificator[j]); 
				strcpy(identificator[j], identificator[j + 1]);
				strcpy(identificator[j + 1], tmpWord);
			}
		}
	} */
	for (int j = 0; j < count_ident; j++) // По каждому предложению
	{// Номер предложения - count_ident
		char massiv[N][N] = {0};
		int index_massiv = 0;
		token = strtok(identificator[j], " "); // По каждому слову в предложении
		while (token != NULL)
		{
			// Если без проверки то для чисел и букв проверки НИЖЕ:
			int len = strlen(token);
			if (token[len - 1] == '.')
				token[len - 1] = '\0';
			strcpy(massiv[index_massiv++], token);
			token = strtok(NULL, " ");
		}
		for (int i = 0; i < index_massiv; i++) // Отсортировали слова в предложениях(в новом массиве)
		{// Номер слова - index_massiv
			for (int k = 0; k < (index_massiv - 1); k++) 
			{//massiv[i] - одно предложение
				if (strlen(massiv[k]) < strlen(massiv[k+1])) // Для букв
				{//(atoi(massiv[k]) < atoi(massiv[k + 1])) // Переводит строку в число
				//(strcmp(massiv[k], massiv[k+1]) > 0) // Для цифр
//if (((is_number(massiv[k]) && is_number(massiv[k+1])) && (atoi(massiv[k]) < atoi(massiv[k + 1]))) || (strlen(massiv[k]) < strlen(massiv[k + 1])))
					char tmpWord[N];
					strcpy(tmpWord, massiv[k]); 
					strcpy(massiv[k], massiv[k + 1]);
					strcpy(massiv[k + 1], tmpWord);
				}
			}
		}
		for (int i = 0; i < index_massiv; i++) // ДЛЯ ТОЧЕК
		{// Все для того если вдруг последнее слово в предложении после сортировки уйдет со своего места с точкой
			int len = strlen(massiv[i]);
			if (massiv[i][len - 1] == '.' && i != (index_massiv - 1))
				massiv[i][len - 1] = '\0'; // char
			else if (massiv[i][len - 1] != '.' && i == (index_massiv - 1))
				strcat(massiv[i], "."); // const char*
			printf("%s ", massiv[i]);
		}
	}
	return 0;
}

int main() 
{
	char msg[256];
	fgets(msg, 256, stdin);
	int len = strlen(msg);
	msg[len - 1] = '\0';
	func(msg);
	return 0;
} 
