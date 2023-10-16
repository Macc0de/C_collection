/*
4) Разбить последовательность на группы по 5 символов(в последней группе сколько останется)
и выдать каждую последовательность в обратном порядке

abcdefghjkltyuiop
*/
#include <stdio.h>
#include <string.h> //strcspn
#define N 100

int func(char A[N])
{
	for (int i = 0; A[i]; i++)
	{
		if ((i + 1) % 5 == 0) // < 5 символов - не выводится
		{
			for (int j = i; j > i - 5; j--) // Обратный порядок
			{ // i - 5 (предыдущие 5 элементов)
				printf("%c", A[j]);
			}
			printf(" "); // Разделитель между группами слов
		}
		else if (i + 4 > strlen(A)) // Оставшиеся
		{
			for (int j = strlen(A); j >= i; j--)
			{
				printf("%c", A[j]);
			}
			break;
		}
	}
	
	return 0;
}

int main() 
{
	int i;
	char A[N] = {};
	
	fgets(A, N, stdin); 
	//A[strcspn(A, "\n")] = '\0'; // убираем новую строку
	
	func(A);
	
	return 0;
}
