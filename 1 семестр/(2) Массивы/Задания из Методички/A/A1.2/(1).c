/*
1) Если c(i) - буква, то заменить ее на следующую букву латинского алфавита. При этом считается, что следующей за
буквой 'Z' является буква 'A', а следующей за 'z' является 'a'

bcfAbH
*/
#include <stdio.h>
#include <string.h> //strcspn
#define N 100

int func(char A[])
{
	for (int i = 0; A[i]; i++)
	{
		if (A[i] == 'z') 
		{
			A[i] = 'a'; 
		}
		else if (A[i] == 'Z')
			A[i] = 'A';
		else
			A[i]++; // След. буква
	}
	
	printf("\n%s ", A);
	
	return 0;
}

int main() 
{
	int i;
	char A[N] = {};
	
	fgets(A, N, stdin);
	A[strcspn(A, "\n")] = '\0'; // Убираем новую строку
	
	func(A);
	
	return 0;
}
