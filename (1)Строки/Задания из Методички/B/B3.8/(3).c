/*
3) По целым K и N находит и меняет в предложении слова с номерами K и N

jk cvncn jl 80 tyuiiy
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
	
	char* identificator[30]; // Только для слов
	char* token = strtok(msg, " ");
	int count_ident = 0, K = 0, N = 0;
	
	scanf("%d", &K);
	getchar();
	scanf("%d", &N);
	
	while (token != NULL) 
	{
		identificator[count_ident++] = token;
		token = strtok(NULL, " ");
	}
	
	if (K < 0 || K > 30 || N < 0 || N > 30) 
	{
		printf("Invalid!!!");
		return;
	}
	
	char* tmp = identificator[N]; // слово которое хотим поменять
	identificator[N] = identificator[K]; // [N - 1] если нужно начало счета с 1
	identificator[K] = tmp;
	for (int i = 0; i < count_ident; i++) 
	{
		printf("%s ", identificator[i]); // Полный вывод предложения
	}  
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