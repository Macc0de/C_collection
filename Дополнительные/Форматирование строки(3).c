// Функция принимает строку, заменяет все пробелы на _
#include <stdio.h>
#include <stdlib.h>

void func(char* msg) {
	for (int i = 0; msg[i] != '\0'; i++)
	{
		if (msg[i] == ' ')
			msg[i] = '_';
	}
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	func(msg);
	printf("%s\n", msg);
	return 0;
}
