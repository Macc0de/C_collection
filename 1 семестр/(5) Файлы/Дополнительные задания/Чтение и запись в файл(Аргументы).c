/* 
Нужно чтобы существовал файл для чтения(read.txt), где записан текст.

Пример запуска в консоли: 
gcc main.c
./a.exe read.txt write.txt
*/
#include <stdio.h>

FILE *FA, *FB;

int main(int count, char* parms[])
{
	char c;
	FA = fopen(parms[1], "rt");
	FB = fopen(parms[2], "wt");
	
	c = fgetc(FA);
	
	while(c != EOF)
	{
		fputc(c, FB);
		c = fgetc(FA);
	}
	
	fclose(FB);
	fclose(FA);
	
	return 0;
}
