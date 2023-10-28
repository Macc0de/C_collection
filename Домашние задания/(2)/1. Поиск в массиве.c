/*
Вводится размер массива и произвольная последовательность целых чисел, являющихся элементами массива.
Далее вводится целое число, для которого нужно определить сколько раз оно встречается в массиве.

Input: 
5
7 5 -2 6 7
7
Output: 
2
*/
#include <stdio.h>

int main()
{
	int key, size, i = 0, count = 0;
	
	scanf("%d", &size);
	int arr[size];
	
	while(i < size)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	
	scanf("%d", &key);
	
	for(int j = 0; j < size; j++)
	{
		if(arr[j] == key)
			count++;
	}
	
	printf("%d", count);
	
	return 0;
}
