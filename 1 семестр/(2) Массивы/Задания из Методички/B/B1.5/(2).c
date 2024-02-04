// 2) Удалить из последовательности все цифры
// hfjfg48k3
#include <stdio.h>
#include <stdlib.h>
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
	int digits = 0, index_dub = 0;
	char* dub = malloc(strlen(A) * sizeof(char)); // calloc(strlen(A), sizeof(char));
	
	for (int i = 0; A[i]; i++)
	{
		if (!isdigit(A[i]))
			dub[index_dub++] = A[i]; // в новую строку записываем
		else
			digits++;
	}
	
	int len = strlen(A);
	dub[len - digits] = '\0';
	
	printf("%s", dub);
	
	free(dub);
	
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
