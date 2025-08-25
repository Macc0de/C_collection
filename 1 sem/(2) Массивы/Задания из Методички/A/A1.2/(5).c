// 5) Определить кол-во цифр, расположенных в последовательности после первой буквы 'A'
// 129bvca7A834n4556A780
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int func(char A[])
{
	int index_A = 0, count = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] == 'A')
		{
			index_A = i;
			break;
		}
	}
	
	for (int i = index_A + 1; i < N; i++) // От индекса буквы 'A' до конца
	{
		if (A[i] == 'A')
		{
			break;
		}
		else if (isdigit(A[i]))
			count++;
	}
	
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
