#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char* msg)
{
	int i, j, len;
	int chTemp, min;
	len = strlen(msg);
	if (msg[len - 1] == '\n') { // Удаляем лишний перенос строки (НЕОБЯЗАТЕЛЬНО)
		msg[len - 1] = '\0';
		len--; // уменьшаем длину строки
	} 
	for (i = 0; i < len - 1; i++) // чтобы не выйти за границы массива
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (msg[min] > msg[j]) // descending order - (<) // Если текущий элемент больше чем следующий
			{
				min = j;
			}
		}
		chTemp = msg[min]; // временный элемент для хранения chTemp
		msg[min] = msg[i]; // меняем местами два элемента
		msg[i] = chTemp; // меняем местами два элемента
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
