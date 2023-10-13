// Проверка на то является ли строка палиндромом(предложение которое читается одинаково с любой стороны)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int func(char* msg) 
{
	int perviy = 0;
	int posledniy = strlen(msg) - 1; // hello - получаем o
	
	// (1) Способ(цикл for)
	for (; perviy < posledniy; perviy++, posledniy--) // Ничего не иницилизируем - ";"
	{
		if (tolower(msg[perviy]) != tolower(msg[posledniy])) // Условие полиндрома, первый элемент равен последнему элементу и так каждая последующая буква
		{ // tolower - чтобы работало с большими буквами (Только с латиницей)
			printf("\nNo\n");
			return 0;
		}
	}

	/* (2) Способ(цикл while)
	while (perviy < posledniy)
	{
		if (tolower(msg[perviy]) != tolower(msg[posledniy]))
		{
			printf("\nNo\n");
			return 0;
		}
		perviy++; // Увеличивем на 1 чтобы h e l l o (проходимся по слову от начала)
		posledniy--; // Уменьшаем на 1 чтобы o l l e h (от конца)
		// Должно увеличиваться на 1
		// Должно уменьшаться на 1
	}
	*/
	
	printf("\nYes\n");
	
	return 1;
}

int main()
{
	char msg[30];
	scanf("%s", msg);
	//fgets(msg, 30, stdin); - не работает(в конец строки добавляет перенос '\n')
	
	int p = func(msg);
	printf("%d\n", p); // Получаем результат функции и выводим результат (0 или 1)
	
	return 0;
}
