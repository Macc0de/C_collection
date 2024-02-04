// 4) Определить максимальную длину подпоследовательности, состоящей только из цифр
// la458f
// 458
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

int func(char A[], char B[])
{
	int flag = 0;
	for (int i = 0; B[i]; i++)
	{
		if (!isdigit(B[i]))
		{
			flag = 1;
			break;
		}
	}
	
	if (flag)
	{
		printf("Invalid!");
		return 1;
	}
	
	int count = 0;
	if (strstr(A, B)) // B входит в A
	{
		for (int i = 0; B[i]; i++)
		{
			count++;
		}
	}
	
	printf("Count: %d", count);
	
	return 0;
}

int main() 
{
	char A[N] = {};
	char B[N] = {};
	
	fgets(A, N, stdin);
	fgets(B, N, stdin); // ADD
	
	A[strcspn(A, "\n")] = '\0';
	B[strcspn(B, "\n")] = '\0';
	
	check_string(A);
	check_string(B);
	func(A, B);
	
	return 0;
}
