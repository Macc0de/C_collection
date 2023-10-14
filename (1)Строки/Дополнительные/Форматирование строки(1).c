// Вывод строки в обратном порядке
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char* msg)
{
	for (int i = strlen(msg); i >= 0; i--)
	{
		printf("%c ", msg[i]);
	}
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	func(msg);
	return 0;
}
