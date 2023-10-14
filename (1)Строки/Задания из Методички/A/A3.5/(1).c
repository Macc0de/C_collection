/*
1) По заданной букве дает кол-во слов, начинающихся с этой буквы, и печатает эти слова

kalop Kent Keller poker popkar
*/
#include <stdio.h>
#include <string.h>

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
	
	char p = 'K'; // Заданная буква
	char identificator[30][20];
	int count_ident = 0;
	char* token = strtok(msg, " ");
	while (token != NULL) 
	{
		strcpy(identificator[count_ident], token);
		count_ident++;
		token = strtok(NULL, " ");
	}
	
	int count = 0;
	printf("\n");
	
	for (int i = 0; i < count_ident; i++) 
	{
		int is_digits = 0;
		int len = strlen(identificator[i]);
		for (int j = 0; j < len; j++) 
		{ 
			if (identificator[i][0] == p) 
			{ // [слово номер i][символ слова]
				count++;
				is_digits = 1;
				break;
			}
		}
		if (is_digits == 1 && len > 0) 
		{
			printf("%s ", identificator[i]); // Слова
		}
	}
	printf("\n%d", count); // Кол-во слов
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	func(msg);
	
	return 0;
}
