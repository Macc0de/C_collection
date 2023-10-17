/*
cat do.g. vbm. hi*
cat dog. vbm. hi*
catdog.vbm.hi*
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int func(char* str) 
{
	int len_pred = 0, count_ident = 0;
	char* pred_slovo = NULL;
	char* token = strtok(str, " ");
	
	while (token != NULL) 
	{
		if (pred_slovo != NULL) 
			len_pred = strlen(pred_slovo);
		
		// Замена первой буквы каждого предложения на прописную
		if (islower(token[0]) && ((count_ident == 0) || (pred_slovo != NULL && pred_slovo[len_pred-1] == '.')))
			token[0] = toupper(token[0]);
		
		char dot;
		for (int j = 0; token[j]; j++)
		{
			if (token[j] == '.' || token[j] == '*')
				dot = token[j];
		}
		
		// Вывод в обратном порядке
		for (int i = strlen(token) - 1; i >= 0; i--) // (Если только с точками оставить только это)
		{
			if (token[i] != dot)
				printf("%c", token[i]);
		}
		
		for (int k = 0; token[k]; k++) // Остаются на своих местах
		{
			if (token[k] == dot)
				printf("%c", dot);
		}
		
		printf(" "); // Для вывода
		
		pred_slovo = token;
		token = strtok(NULL, " ");
	}
	
	return 0;
}

int main() 
{
	char msg[256];
	fgets(msg, 256, stdin);
	
	int len = strlen(msg);
	if (msg[len - 2] != '*') 
	{
		printf("No!");
		return 1;
	}
	msg[len - 1] = '\0';
	
	func(msg);
	
	return 0;
} 
