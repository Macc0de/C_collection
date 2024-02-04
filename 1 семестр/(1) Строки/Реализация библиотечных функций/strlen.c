// Реализация функции strlen() - подсчет длины строки
#include <stdio.h>

int func(char* msg)
{
	int count = 0;
	while (msg[count] != '\0') 
	{
		count++;
	}
	/* for (int i = 0; msg[i] != '\0'; i++) // Через цикл while
		count++;
	*/
	return --count; // Префиксная, не постфиксная(count--)
}

int main()
{
	char msg[30];
	
	fgets(msg, 30, stdin);
	printf("%d", func(msg));
	
	return 0;
}
