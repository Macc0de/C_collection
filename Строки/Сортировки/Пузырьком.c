// Самая медленная сортировка
// Сортировка: пузирьком (1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char* msg)
{
	int i, j, len;
	int chTemp;
	len = strlen(msg);
	if (msg[len - 1] == '\n') { // Удаляем лишний перенос строки (НЕОБЯЗАТЕЛЬНО)
		msg[len - 1] = '\0';
		len--; // уменьшаем длину строки
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < (len - 1); j++) // len - 1 - чтобы не выйти за границы массива
		{
			if (msg[j] > msg[j + 1]) // descending order - (<) // Если текущий элемент больше чем следующий
			{
				chTemp = msg[j]; // временный элемент для хранения chTemp
				msg[j] = msg[j + 1]; // меняем местами два элемента
				msg[j + 1] = chTemp; // меняем местами два элемента
			}
		}
	}
	printf("%s ", msg); // пробелы тоже сортирует - у пробела свой символ
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	func(msg);
	return 0;
}
//=================================================================================================
// Сортировка: пузирьком (ОПТИМИЗИРОВАННЫЙ) (2)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

void func(char* msg)
{
	int i, j, b;
	int chTemp;
	int len = strlen(msg);
	for (i = len - 1; i >= 0; i--)
	{
		int noSwap = 1;
		for (j = 0; j < i; j++)
		{
			if (msg[j] > msg[j + 1])
			{
				chTemp = msg[j];
				msg[j] = msg[j + 1];
				msg[j + 1] = chTemp;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
		{
			break;
		}
	}
	printf("%s ", msg);
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	func(msg);
	return 0;
}
