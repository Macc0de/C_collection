/*
8) Определить, сколько раз в последовательности встречаются пары одинаковых символов 

AA gg g2 44 12
AAAA    22  ggg hh mm 00
aa  23   4
*/
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int count = 0;
	for (int i = 0; A[i]; i++)
	{
		if (A[i] == A[i+1])
		{
			count++;
			i++; // Если два одинаковых элементов -> идем дальше по строке
			printf("\n%c", A[i]);
		}
	}
	
	printf("\nResult: %d", count);
	
	return 0;
}

int main() 
{
	int i;
	char A[N] = {};
	
	fgets(A, N, stdin);
	A[strcspn(A, "\n")] = '\0';
	
	func(A);
	
	return 0;
}
