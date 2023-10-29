// Замена нужного символа в строке на выбранный другой
#include <stdio.h>
#include <stdlib.h>

void func(char* msg, char ch, char symbol) {
	for (int i = 0; msg[i] != '\0'; i++)
	{
		if (msg[i] == symbol)
			msg[i] = ch;
	}
}

int main()
{
	char msg[30];
	char ch = 0, symbol = 0;
	
	scanf("%c", &ch); // не считивает пробел и конец строки, нужен getc // То на что хотим заменить
	getc(stdin); // символ | gets - строка
	scanf("%c", &symbol); // тот который заменим
	getc(stdin);
	
	fgets(msg, 30, stdin);
	
	func(msg, ch, symbol);
	printf("%s\n", msg);
	
	return 0;
}
