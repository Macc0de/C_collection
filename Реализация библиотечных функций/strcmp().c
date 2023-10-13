// Реализация функции strcmp() - сравнивает две строки, возвращает 0 если 2 строки одианаковые, иначе 1
#include <stdio.h>

int func(char* msg, char* ssg)
{
	int flag = 0;
	while (*msg != '\0' || *ssg != '\0') 
	{
		if (*msg == *ssg) 
		{ // Разыменовуем указатели для получения значений, которые хранятся в памяти
			msg++; // Арифметика указателей
			ssg++;
		}
		else if ((*msg != '\0' && *ssg == '\0') || (*msg == '\0' && *ssg != '\0') || (*msg != *ssg)) // 1,2 проверки - про длину строк
		{
			flag = 1; // Не одинаковые строки
			break;
		}
	}
	return flag;
}

int main()
{
	char msg[30];
	char ssg[30];
	
	fgets(msg, 30, stdin);
	fgets(ssg, 30, stdin);
	
	printf("%d", func(msg, ssg));
	
	return 0;
}
