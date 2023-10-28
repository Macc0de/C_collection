/*
Вводится натуральное число.
Если введено не число или число, не являющееся натуральным, программа должна вывести ERROR и завершить работу.

Написать программу, определяющую, является ли введенное число простым.

Число называют простым, если оно делится только на единицу и на себя.
Если число простое нужно вывести YES, если нет - NO.
Input:
11
Output:
YES

Input:
a
Output:
ERROR

Input:
-3
Output:
ERROR
*/
#include <stdio.h>

int main()
{
	int num;
	if(!scanf("%d", &num))
	{
		printf("ERROR");
		return 1;
	}
	else
	{
		if(num > 0)
		{
			for (int i = 2; i < num; i++)
			{
				if (num % i == 0)
				{	
					printf("NO");
					return 1;
				}
			}
			printf("YES");
		}
		else
		{
			printf("ERROR");
			return 2;
		}
	}
	return 0;
}
