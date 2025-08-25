/*
Найти наибольшее число которое повторяется несколько раз, если повторов нет - просто вывести максимум

-1 -2 -2 3 3 6 6 7 9
Answer: 6
1 1 3 2 2
Answer: 2
-1 -4 -4 1 -1 2 3
Answer: -1
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
	int i, j, razmer, flag = 0;
	int* massiv;
	massiv = malloc(N * sizeof(int)); // sizeof(massiv)
	
	printf("Enter razmer: "); 
	scanf("%d", &razmer);
	
	for (i = 0; i < razmer; i++)
	{
		scanf("%d", &massiv[i]);
	}
	
	i = 0, j = 0;
	while ((flag == 0) && (i < razmer)) // flag != 1
	{
		i++;
		for (j = i + 1; j < razmer; j++)
		{
			if (massiv[i] == massiv[j])
				flag = 1;
		}
	}
	/* (2) Через for
	for (i = 0; (flag == 0) && (i < razmer); i++)
	{
		for (j = i + 1; j < razmer; j++)
		{
			if (massiv[i] == massiv[j])
				flag = 1;
		}
	}
	*/
	int max = massiv[0];
	if (flag == 1)
	{
		for (i = 0; i < razmer; i++)
		{
			if (massiv[i] > max)
			{
				int is_flag = 0;
				for (j = i + 1; j < razmer; j++)
				{
					if (massiv[i] == massiv[j])
					{
						is_flag = 1;
						break;
					}
				}
				
				if (is_flag == 1)
					max = massiv[i];
			}
		}
	}
	else // Если нет повторов - выводим максимум
	{
		for (i = 0; i < razmer; i++)
		{
			if (massiv[i] > max)
				max = massiv[i];
		}
	}
	
	printf("%d ", max);
	
	free(massiv);
	
	return 0;
}
