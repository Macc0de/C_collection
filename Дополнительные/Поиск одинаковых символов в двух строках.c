// Поиск и вывод одинаковых символов в двух строках
#include <stdio.h>
#include <string.h>
#define N 30

void func(char* msg, char* msg1)
{
	int flag = 0;
	int dlina = strlen(msg);
	int dlina1 = strlen(msg1);
	for (int i = 0; i < dlina; i++)
	{
		for (int j = 0; j < dlina1; j++) // Вторая строка
		{
			if (msg[i] == msg1[j] && msg[i] != ' ')
			{
				printf("Found repeated! - %c\n", msg[i]); // Берет элемент с первой строки и выводит его повтор. элементы со второй строки
				flag = 1;
			}
		}
	}
	if (!flag)
	{
		printf("Not found!!!");
	}
}

int main()
{
	char msg[N];
	char msg1[N];
	
	fgets(msg, N, stdin);
	msg[strlen(msg) - 1] = '\0'; // Чтобы убрать '\n'
	fgets(msg1, N, stdin);
	msg1[strlen(msg1) - 1] = '\0';
	
	func(msg, msg1);
	
	return 0;
}
