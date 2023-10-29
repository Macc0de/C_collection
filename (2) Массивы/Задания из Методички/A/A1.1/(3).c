// 3) Между первым кратным семи элементом последовательности и последним элементом, значение которого меньше его порядкового номера
// -2 14 4 5 2
// 21 20 20 10 1
#include <stdio.h>
#include <math.h>
#define N 5

int func(int A[])
{
	int i, index_multiple = 0, index_last = 0, result = 0, count = 0, flag = 0;
	for (i = 0; i < N; i++)
	{
		if (A[i] % 7 == 0)
		{
			index_multiple = i;
			break;
		}
	}
	
	for (i = N; i > index_multiple; i--)
	{
		if (A[i] < i)
		{
			index_last = i;
			flag = 1;
			break;
		}
	}
	
	if (!flag)
		index_last = N;
	
	for (i = index_multiple + 1; i < index_last; i++)
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
