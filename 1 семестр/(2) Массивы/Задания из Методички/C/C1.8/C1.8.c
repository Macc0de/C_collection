/*
Сначала делаем массив для точек(предложения), потом другой массив куда заносим 
этот массив + заносим слова(для длины)

ahsladl dog. hiw2 me worldo. jh78.#
me hiw2 worldo. dog ahsladl. jh78.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int compare_qsort(const void* a, const void* b) // Функция для qsort
{
    int fa = strlen((const char *)a); // size_t
    int fb = strlen((const char *)b);
	
    return (fa > fb) - (fa < fb);
}

int func(char* str) 
{
	int count_ident = 0; // Кол-во предложений
	int count_size = 0; // Индекс в массиве size для кол-ва слов
	int size[30] = {}; // Массив для кол-ва слов в каждом предложении
	
	char identificator[N][N] = {};
	int count_words = 0; // Кол-во слов
	
	char* token = strtok(str, " ");
	while (token != NULL) 
	{
		int len = strlen(token);
		if (count_words != 0) // От пробела в начале
			strcat(identificator[count_ident], " "); // Добавили пробел между словами в двум. массиве
			
		strcat(identificator[count_ident], token); // Записывает token в массив как слова
		count_words++;
		
		if (token[len - 1] == '.') // Предложение
		{
			count_ident++; 
			size[count_size++] = count_words; 
			/* Записываем кол-во слов в каждом предложении для будущей 
			сортировки кол-ва слов в предложении */
			
			count_words = 0; // Для след. итерации
		}
		
		// В двумерном массиве есть предложения по точкам(со словами через пробел)
		token = strtok(NULL, " ");
	} 
	
	// Сортировка слов в предложениях по кол-ву слов
	int chTemp = 0;
	for (int i = 0; i < count_ident; i++) // По каждому предложению
	{
		for (int j = 0; j < (count_ident - 1); j++) 
		{
			if (size[j] < size[j + 1]) // По убыванию
			{
				chTemp = size[j]; 
				size[j] = size[j + 1]; 
				size[j + 1] = chTemp;
				
				char tmpWord[N];
				strcpy(tmpWord, identificator[j]); 
				strcpy(identificator[j], identificator[j + 1]);
				strcpy(identificator[j + 1], tmpWord);
			}
		}
	}
	
	/* for (int i = 0; i < count_ident; i++) // Только если отсортировать по кол-ву слов(убывание)
		printf("%s ", identificator[i]); */
	
	for (int i = 0; i < count_ident; i++)
	{
		char massiv[N][N] = {}; // Массив слов текущего предложения
		int index_massiv = 0;
		token = strtok(identificator[i], " ");
		
		while (token != NULL)
		{
			strcpy(massiv[index_massiv++], token); // Копируем token в новый массив
			token = strtok(NULL, " ");
		}
		
		qsort(massiv, index_massiv, N, compare_qsort); // Отсортировали все слова в предложении по длине
		for (int j = 0; j < index_massiv; j++) // Проходимся по новому массиву(по всем словам)
		{// Все для того если вдруг последнее слово в предложении после сортировки уйдет со своего места с точкой
			int dlina = strlen(massiv[j]); // Длина текущего слова в предложении
			if (massiv[j][dlina - 1] == '.' && j != (index_massiv - 1)) // [номер слова в предложении][символ текущего слова]
			{ // 2)Слово не является последним?(если последнее слово - не надо убирать точку)
				massiv[j][dlina - 1] = '\0';
			}
			else if (j == (index_massiv - 1) && (massiv[j][dlina - 1] != '.'))
			{// 1)Находимся на последнем слове в предложении? 2)Последнее слово без точки?
				strcat(massiv[j], "."); // Если нет точки, то добавляем
			}
			
			printf("%s ", massiv[j]); // Вывод текущего слова
		}
	}
	
	return 0;
}

int main() 
{
	char msg[256];
	fgets(msg, 256, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '#') // Учитываем \n
	{
		printf("No!");
		return 1;
	}
	msg[len - 2] = '\0';
	
	func(msg);
	
	return 0;
} 
