// Сортировка слов в предложениях по длине пузырьком
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
// ahsladl xz cate dog. hiw2 me worldo. jh78 vc kl.#
// 333 1 22. 1 22 4444 333. 1 333 4444 22.
// 4444 hal 1 r4. kln0 xz 5 hgd9gjd.
int func(char* str) 
{
	int count_ident = 0; // Кол-во предложений
	char identificator[N][N] = {0};
	char* token = strtok(str, " ");
	while (token != NULL) 
	{
		int len = strlen(token);
		strcat(identificator[count_ident], token);
		strcat(identificator[count_ident], " ");
		if (token[len - 1] == '.')
		{
			count_ident++;
		}
		token = strtok(NULL, " ");
	}
	for (int j = 0; j < count_ident; j++) // По каждому предложению
	{
		char massiv[N][N] = {0};
		int index_massiv = 0;
		int size[30] = {0};
		token = strtok(identificator[j], " "); // По каждому слову в предложении
		while (token != NULL)
		{
			int len = strlen(token);
			if (token[len - 1] == '.')
				token[len - 1] = '\0';
			size[index_massiv] = strlen(token); // В массив записываем
			strcpy(massiv[index_massiv], token);
			index_massiv++;
			token = strtok(NULL, " ");
		}
		//massiv[index_massiv - 1][strlen(massiv[index_massiv - 1]) - 1] = '\0'; // Убрать точку в ласт слове
		//[номер предложения][символ конкретный]
		int chTemp = 0;
		for (int i = 0; i < index_massiv; i++) // Отсортировали слова в предложениях(в новом массиве)
		{
			for (int k = 0; k < (index_massiv - 1); k++) 
			{
				if (size[k] > size[k + 1] )
				{
					chTemp = size[k]; 
					size[k] = size[k + 1]; 
					size[k + 1] = chTemp;
					char tmpWord[N];
					strcpy(tmpWord, massiv[k]); 
					strcpy(massiv[k], massiv[k + 1]);
					strcpy(massiv[k + 1], tmpWord);
				}
			}
		}
		for (int i = 0; i < index_massiv; i++)
		{
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
