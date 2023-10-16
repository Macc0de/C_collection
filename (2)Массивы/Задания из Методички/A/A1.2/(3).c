/*
3) Буквы 'A', 'O', 'U', стоящие на четных местах, заменить на '*', стоящие на нечетных местах 
заменить на '1', '2', '3' соответственно. Остальные символы оставить без изменений

0123456
AoUA3oO
AOUUOA
*/
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			if (A[i] == 'A' || A[i] == 'O' || A[i] == 'U')
				A[i] = '*';
		}
		else
		{
			if (A[i] == 'A')
				A[i] = '1';
			else if (A[i] == 'O')
				A[i] = '2';
			else if (A[i] == 'U')
				A[i] = '3';
		}
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
