// Сортировка слов по длине, не используя дополнительного массива
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
// 4444 1 22 333
int func(char* str) 
{
	int count_ident = 0; // Кол-во предложений
	char identificator[N][N] = {0};
	
	char* token = strtok(str, " ");
	while (token != NULL) 
	{
		strcpy(identificator[count_ident++], token); // Записывает token в массив как слова
		token = strtok(NULL, " ");
	} 
	int chTemp = 0;
	for (int i = 0; i < count_ident; i++)
	{
		for (int j = 0; j < (count_ident - 1); j++) 
		{
			if (strlen(identificator[j]) < strlen(identificator[j + 1])) // По убыванию
			{
				char tmpWord[N];
				strcpy(tmpWord, identificator[j]); 
				strcpy(identificator[j], identificator[j + 1]);
				strcpy(identificator[j + 1], tmpWord);
			}
		}
	}
	for (int i = 0; i < count_ident; i++)
		printf("%s ", identificator[i]);
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
