#include <stdio.h>

int main()
{
	FILE* file = fopen("data.txt", "r");
	char buffer[30];

	fgets(buffer, 30, file); // Записывает в строку buffer
	printf("%s", buffer); // Выводит только 1 строку, до '\n'
	
	fclose(file);
	
	return 0;
}
