/*
1) Буквы, стоящие на нечетных местах заменить на буквы, симметричные им относительно латинского алфавита
('A' на 'Z', 'B' на 'Y' и тд.). Остальные символы оставить без изменений

abcdef
zbxdwf
*/
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
		if ((i+1) % 2 == 1) // Отcчет с 1
		{
			if (isalpha(A[i]))
			{
				if (isupper(A[i]))
				{
					A[i] = 'Z' - (A[i] - 'A');
				}
				else if (islower(A[i]))
				{
					A[i] = 'z' - (A[i] - 'a');
				}
			}
		}
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
