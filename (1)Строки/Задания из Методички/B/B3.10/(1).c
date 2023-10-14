/* 
1) По целому K (20 <= K <= 80) распечатывает все слова предложения "столбиком" так, чтобы все они оканчивались в К-й позиции 
строк (т.е. выравнивались по правому краю)
    
	hello 
 dkfhello
  kjhello
hello dkfhello kjhello
*/
#include <stdio.h>
#include <string.h>
#include "Header.h"

void func(char* msg) 
{
	// Проверки
	if (msg == NULL || msg[0] == '\n')
	{
		printf("No!");
		return;
	}
	int status = isvalid(msg, 20, 20);
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
	
	int K;
	scanf("%d", &K);
	getchar();
	
	int count_ident = 0;
	char identificator[20][20];
	
	if (K >= 20 || K <= 80)
		return;

	char* token = strtok(msg, " ");
	while (token != NULL) 
	{ 
		strcpy(identificator[count_ident], token);
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	for (int i = 0; i < count_ident; i++) 
	{
		for (int j = 0; j < (K - strlen(identificator[i])); j++) 
		{
			printf(" ");
		}
		printf("%s\n", identificator[i]);
	}
	/* (2) Способ без identificator
	while (token != NULL) 
	{
		int len = strlen(token);
		for (int i = 0; i < K - len; i++) 
		{
			printf(" ");
		}
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	*/
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