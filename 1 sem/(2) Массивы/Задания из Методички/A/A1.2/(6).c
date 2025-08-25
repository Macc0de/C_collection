// 6) Определить кол-во символов между первыми двумя звездочками('*')
// 123 4*asd***123as
// *123***
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int index_symbol = 0, index_last = 0, count = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] == '*')
		{
			index_symbol = i;
			break;
		}
	}
	
	for (int i = index_symbol; i < N; i++)
	{
		if (A[i + 1] == '*')
		{
			index_last = i;
			break;
		}
	}
	
	for (int i = index_symbol; i < index_last; i++)
		count++;
		
	printf("Count: %d", count);
	
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
//=====================================================
// (2) Способ(лучше)
// 1234*mas*maxym*
// *123*** 
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	int index_symbol = 0, count = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] == '*')
		{
			index_symbol = i;
			break;
		}
	}
	
	for (int i = index_symbol + 1; i < N && A[i] != '*'; i++)
		count++;
	
	printf("Count: %d", count);
	
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
