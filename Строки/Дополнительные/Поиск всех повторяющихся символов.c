// Поиск и вывод всех повторяющихся символов в строке
// Большие буквы не считивает как маленькие - Я != я
#include <stdio.h>
#include <string.h> // strlen()

void func(char* msg) 
{
	int flag = 0;
	int dlina = strlen(msg); // вся длина строки, не считивает '\0'
	for (int i = 0; i < dlina; i++)
	{
		for (int j = i + 1; j < dlina; j++) // исп. второй цикл для следующего символа
		{
			if (msg[i] == msg[j] && msg[i] != ' ')
			{
				printf("Found repeated! - %c\n", msg[i]);
				flag = 1; // true
			}
		}
	}
	if (!flag) // false, if (flag == 0)
	{
		printf("Not found!!!");
	}
}

int main()
{
	char msg[30];
	//scanf("%s", msg); Нет в конце строки '\n' и не считивает пробел
	fgets(msg, 30, stdin);
	func(msg); // нельзя присвоить функцию void
	return 0;
}
