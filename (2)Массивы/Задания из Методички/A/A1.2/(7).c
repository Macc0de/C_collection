// 7) Определить, можно ли из букв, встречающихся в последовательности, составить фамилию
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100
// syav
int func(char A[])
{
	const char* surname = "Vasya";
	for (int i = 0; surname[i]; i++)
	{
		int flag = 0;
		for (int j = 0; A[j]; j++)
		{
			if (tolower(A[j]) == tolower(surname[i]))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			printf("no");
			return 1;
		}
	}
	
	printf("Ok");
	
	return 0;
}

int main() 
{
	int i;
	char A[N] = {};
	
	fgets(A, N, stdin); 
	//A[strcspn(A, "\n")] = '\0';
	
	func(A);
	
	return 0;
}
