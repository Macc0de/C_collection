/*
Вводится размер массива и произвольная последовательность целых чисел, являющихся элементами массива.

Преобразовать массив таким образом, чтобы сначала располагались все положительные элементы, 
а потом — все отрицательные (элементы, равные 0, считать положительными).
При этом положительные элементы должны быть упорядочены по возрастанию, а отрицательные — по убыванию.

Дополнительные массивы для решения задачи использовать нельзя.

Input: 
6
1 -1 3 -3 2 -2
Output: 
1 2 3 -1 -2 -3
*/
#include <stdio.h>

void sort_arr(int arr[], int size, int option)
{
	int temp;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
			if(option == 1)
			{
				if(arr[j] < arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			else
			{
				if(arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	
	return;
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
	
	sort_arr(arr, size, 1);
	
	for(i = 0; i < size; i++)
	{
		if(arr[i] < 0)
		{
			num = i;
			break;
		}
	}
		
	sort_arr(arr, num, 2);
	
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
