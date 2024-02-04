// Подсчет кол-ва слов в строке
#include <stdio.h>

int func(char* msg) 
{
	int count = 1; // C нулем не учитывает последнее слово - нужно 1
	for (int i = 0; msg[i] != '\0'; i++)
	{
		if (msg[i] == ' ')
			count++;
	}
	return count;
}

int main()
{
	char msg[30];
	
	fgets(msg, 30, stdin);
	
	int p = func(msg); 
	printf("%d\n", p);
	
	return 0;
}
