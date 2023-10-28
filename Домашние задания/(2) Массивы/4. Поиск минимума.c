/*
Вводится размер массива и произвольная последовательность целых чисел, являющихся элементами массива.
Написать программу, которая ищет минимум среди элементов, стоящих на нечетных местах.

Если минимум не найден, программа должна выводить not found.

Input: 
5
-1 2 1 4 -5
Output: 
2
*/
#include <stdio.h>

int search_min(int arr[], int size)
{
	int i, j, flag = 0;
	int min = 0;
	
	for(i = 1; i < size; i += 2)
	{
		if(flag == 0 || arr[i] < min)
		{
			min = arr[i];
			flag = 1;
		}
	}

	if (flag) 
        printf("%d", min);
	else 
        printf("not found");
	
	return 0;
}

int main()
{
	int size, i = 0, num;
	
	scanf("%d", &size);
	int arr[size];
	
	while(i < size)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	
	search_min(arr, size);
	
	return 0;
}
