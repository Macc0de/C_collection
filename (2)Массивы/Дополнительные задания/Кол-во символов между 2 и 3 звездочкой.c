/*
Между 2 и 3 '*'

*123*maxim*
1234*mas*maxym*
123321*mas*janjh*12*bcbv*
*/
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int count = 0, flag = 0, index_symbol = 0;
	
	for (int i = 0; i < N; i++) // Поиск самой первой '*'
	{
		if (flag == 0 && A[i] == '*')
		{
			flag = 1;
		}
		else if (flag && A[i] == '*')
		{
			index_symbol = i;
			break;
		}
	}
	
	for (int i = index_symbol + 1; i < N && A[i] != '*'; i++)
		count++;
	
	printf("%d", count);
	
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
//====================================================================
// (2) Способ
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int count = 0, index_symbol = 0, index_last = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (A[i] == '*')
		{
			index_symbol = i;
			break;
		}
	}
	
	for (int i = index_symbol + 1; i < N; i++)
	{
		if (A[i] == '*')
		{
			index_last = i;
			break;
		}
	}
	
	for (int i = index_last + 1; i < N && A[i] != '*'; i++)
		A[i] = 'X';
		
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

//====================================================================
// Между 4 и 5 '*'
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int count = 0, index_symbol = 0, index_last = 0, flag = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (flag == 0 && A[i] == '*') // 1-2
		{
			flag = 1;
		}
		else if (flag == 1 && A[i] == '*') // 2-3
		{
			index_symbol = i;
			break;
		}
	}
	
	int fla = 0;
	for (int i = index_symbol + 1; i < N; i++)
	{
		if (fla == 0 && A[i] == '*') // 3-4
		{
			fla = 1;
		}
		else if (fla == 1 && A[i] == '*') // 4-5
		{
			index_last = i;
			break;
		}
	}
	
	for (int i = index_last + 1; i < N && A[i] != '*'; i++) //От второй до третьей
		A[i] = 'X';
		
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
