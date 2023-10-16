// 9) Определить, является ли последовательность идентификатором языка Си
#include <stdio.h>
#include <string.h>
#define N 100

int func(char A[])
{
	// Словарь ключевых слов языка
	char* language[] = {"auto","break","case","char","continue","do","default","const","double","else","enum",
	"extern","for","if","goto","float","int","long","register","return","signed","static","sizeof","short",
	"struct","switch","typedef","union","void","while","volatile","unsigned"};
	
	int flag = 0;
	for (int i = 0; i < 32; i++) // Нужно указывать кол-во слов(32)
	{
		if (strcmp(A, language[i]) == 0)
		{
			flag = 1;
			break;
		}
	}
	
	if (flag)
	{
		printf("Yes");
		return 1;
	}
	else
		printf("No");
	
	return 0;
}

int main() 
{
	char A[N] = {};
	
	fgets(A, N, stdin);
	A[strcspn(A, "\n")] = '\0';
	
	func(A);
	
	return 0;
}
