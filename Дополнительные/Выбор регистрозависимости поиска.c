/* 
Чувствительность к регистру символов.
Функция принимает строку, выбор регистрозависимый или регистронезависимый поиск.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // tolower|toupper

void func(char* msg, char find, char replace, int regist) 
{
	switch (regist)
	{
	case 0: //reg_zavisim - заменяет только на четко указаную маленькую или большую
		for (int i = 0; msg[i] != '\0'; i++)
		{
			if (msg[i] == find)
				msg[i] = replace;
		}
		break;
	case 1: //reg_NEzavisim - заменяет и маленькие и большие (неважно)
		for (int i = 0; msg[i] != '\0'; i++)
		{
			if (tolower(msg[i]) == tolower(find)) // преобразует в нижний регистр
				msg[i] = replace;
		}
		break;
	}
}

int main()
{
	char msg[30];
	char find, replace;
	int regist;

	scanf("%c", &find);
	getc(stdin);
	scanf("%c", &replace);
	getc(stdin);

	fgets(msg, 30, stdin);
	scanf("%d", &regist); // case
	
	func(msg, find, replace, regist);
	printf("%s\n", msg);
	return 0;
}
