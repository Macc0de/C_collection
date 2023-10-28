/*
Вводится размер массива и произвольная последовательность целых чисел, являющихся элементами массива.
Если массив состоит из одинаковых элементов, напечатайте YES. В противном случае напечатайте NO.

Input: 
5
1 2 3 4 5
Output: 
NO
*/
#include <stdio.h>

int is_identical(int arr[], int size)
{
	int i, j, flag = 0;
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(arr[i] != arr[j])
			{
				flag = 1;
				break;
			}
		}
	}
	
	if(flag == 0)
		return 0;
	
	return 1;
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
	
	int check = is_identical(arr, size);
	if(check == 1)
	{
		printf("NO");
		return 0;
	}
	else
	{
		printf("YES");
	}
	
	return 0;
}
