/*
4) Между первым принадлежащим диапазону от -10 до 10 элементом последовательности и последним элементом, 
значение которого равно квадрату его порядкового номера

-20 1 2 3 4 25
*/
#include <stdio.h>
#include <math.h>
#define N 6

int func(int A[])
{
	int i, index_zone = 0;
	for (i = 0; i < N; i++)
	{
		if (A[i] > -10 && A[i] < 10)
		{
			index_zone = i;
			break;
		}
	}
	
	int index_last = 0;
	int flag = 0;
	for (i = N - 1; i > index_zone; i--)
	{
		if (A[i] == pow(i, 2))
		{
			index_last = i;
			flag = 1;
			break;
		}
	}
	
	if (!flag)
		index_last = N - 1;
	
	int result = 0, count = 0;
	for (i = index_zone + 1; i < index_last; i++) 
	{
		result += A[i]; // Sum
		count++;
	}
	
	printf("\nSum: %d. Count: %d", result, count);
	
	return 0;
}

int main() 
{
	int i;
	int A[N] = {};
	for (i = 0; i < N; i++) 
	{
		scanf("%d", &A[i]);
	}
	
	func(A);
	
	return 0;
}

