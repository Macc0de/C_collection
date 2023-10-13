/* Разделить каждый символ строки по пробелам
 input - helloworld
 output - h e l l o w o r l d
*/
#include <stdio.h>
#include <stdlib.h>

void func(char* msg)
{
	for (int i = 0; msg[i] != '\0'; i++)
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
