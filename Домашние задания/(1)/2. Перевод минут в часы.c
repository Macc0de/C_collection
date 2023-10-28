/*
Вводится целое число - временной интервал в минутах.
Напишите программу, которая переводит заданный временной интервал в минутах в величину, выраженную в часах и минутах.
Программа должна выводить на экран полученные значения часов и минут, разделенные двоеточием.

Пример:
Введено число 150 - это 2 часа 30 мин, поэтому в результате должно быть выведено 02:30

Input: 
121
Output: 
02:01
*/
#include <stdio.h>

int main()
{
	int minutes, hours, minutes_converted;

	scanf("%d", &minutes);
	hours = minutes / 60;
	minutes_converted = minutes - (hours * 60);

	if(hours < 10 && minutes_converted < 10)
		printf("0%d:0%d", hours, minutes_converted);
	else if(hours > 9 && minutes_converted < 10)
		printf("%d:0%d", hours, minutes_converted);
	else if(hours < 10 && minutes_converted > 9)
		printf("0%d:%d", hours, minutes_converted);

	return 0;
}
