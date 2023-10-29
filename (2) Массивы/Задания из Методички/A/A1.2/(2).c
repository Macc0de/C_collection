// 2) Если ci - цифра, то заменить ее на цифру 9 - ci, буквы оставить без изменения
// a b 2 n 8
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int func(char A[])
{
	for (int i = 0; A[i]; i++)
	{
		if (A[i] != '9')
		{
			if (isdigit(A[i]))
				A[i] = '9';
		}
		else
			continue;
	}
	
	printf("%s", A);
	
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
