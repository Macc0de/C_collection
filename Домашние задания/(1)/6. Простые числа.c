/*
Вводится натуральное число n.
Если введено не число или число, не являющееся натуральным, программа должна вывести ERROR и завершить работу.

Написать программу, которая выводит на печать первые n простых чисел, включая 1.

Например:
Если введено число 5, то выводятся первые 5 простых чисел: 1 2 3 5 7
Input:
3
Output:
1 2 3
*/
#include <stdio.h>

int main()
{
	int n;
	if(!scanf("%d", &n))
	{
		printf("ERROR");
		return 1;
	}
	else
	{
		if(n > 0)
		{
			int flag, sequence = 1;
			for(int i = 0; i < n; sequence++)
			{
				flag = 1;
				for(int j = 2; j < sequence; j++) // j * j <= sequence ?
				{
					if(sequence % j == 0)
					{
						flag = 0;
						break;
					}	
				}
				if(flag == 1)
				{
					printf("%d ", sequence);
					i++;
				}
			}
		}
		else
			printf("ERROR");
	}
	
	return 0;
}
