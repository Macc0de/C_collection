// 3) Заменить все строчные латинские буквы на соответствующие им прописные
// maXym89 Na(bvc7
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int check_string(char A[])
{
	for (int i = 0; A[i]; i++)
	{
		if (!isdigit(A[i]) && !isalpha(A[i]))
		{
			A[i] = '\0';
			break;
		}
	} 
	
	return 0;
}

int func(char A[])
{
	for (int i = 0; A[i]; i++)
	{
		if (islower(A[i]))
			A[i] = toupper(A[i]);
		else
			continue;
	}
	
	printf("%s", A);
	
	return 0;
}

int main() 
{
	char A[N] = {};
	
	fgets(A, N, stdin);
	A[strcspn(A, "\n")] = '\0';
	
	check_string(A);
	func(A);
	
	return 0;
}
