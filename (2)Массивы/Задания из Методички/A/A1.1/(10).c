/*
10) Между первым элементом последовательности, значение которого равно его порядковому номеру, 
и последним неположительным элементом

15 1 3 9 -1
*/
#include <stdio.h>
#include <math.h>
#define N 5

int func(int A[])
{
	int i, index_value = 0, index_last = 0, result = 0, count = 0, flag = 0;
	for (i = 0; i < N; i++)
	{
		if (A[i] == i)
		{
			index_value = i;
			break;
		}
	}
	
	for (i = N; i > index_value; i--)
	{
		if (A[i] < 0)
		{
			index_last = i;
			flag = 1;
			break;
		}
	}
	
	if (!flag)
		index_last = N;
	
	for (i = index_value + 1; i < index_last; i++)
	{
		result += A[i];
		count++;
	}
	
	printf("Summa:%d. Count:%d", result, count);
	
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
