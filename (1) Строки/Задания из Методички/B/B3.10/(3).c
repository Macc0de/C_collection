// 3) Распечатывает слова, которые состоят из букв, содержащихся в предыдущем слове
// string ignrst
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
	
	int count_ident = 0;
	char* pred_slovo = NULL;
	char* token = strtok(msg, " ");
	
	while (token != NULL) 
	{
		if (pred_slovo == NULL)
		{
			printf("%s ", token);
			
			pred_slovo = token;
			token = strtok(NULL, " ");
			continue; // Перейдет к следующему слову и будет проверять его
		}
		
		int flag = 0;
		for (int i = 0; token[i]; i++) 
		{
			flag = 0;
			for (int j = 0; pred_slovo[j]; j++)
			{
				if (token[i] == pred_slovo[j])
				{
					flag = 1; 
					break;
				}
			}
			
			if (!flag) // Если хотя бы одну букву не нашли
				break;
		}
		
		if (flag)
			printf("%s ", token);
		
		pred_slovo = token;
		token = strtok(NULL, " ");
	}
}

int main()
{
	char msg[600];
	fgets(msg, 600, stdin);
	
	int len = strlen(msg);
	msg[len - 1] = '\0';
	
	func(msg);

	return 0;
}
