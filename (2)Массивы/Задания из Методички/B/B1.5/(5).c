// 5) Определить, существует ли подпоследовательность, состоящая только из латинских букв, являющаяся палиндромом
// lolmanacdcal
// ACDCA
// lolmanacdCahello
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
		if (!isalpha(B[i]))
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
	
	if (strstr(A, B)) // B входит в A
	{
		int perviy = 0;
		int posledniy = strlen(B) - 1;
		
		while (perviy < posledniy)
		{
			if (tolower(B[perviy]) != tolower(B[posledniy]))
			{
				printf("No");
				return 1;
			}
			
			perviy++;
			posledniy--;
		}
		
		printf("Yes");
	}
	else
		printf("Not found!");
	
	return 0;
}

int main() 
{
	char A[N] = {};
	char B[N] = {};
	
	fgets(A, N, stdin);
	fgets(B, N, stdin);
	
	A[strcspn(A, "\n")] = '\0';
	B[strcspn(B, "\n")] = '\0';
	
	check_string(A);
	check_string(B);
	func(A, B);
	
	return 0;
}
