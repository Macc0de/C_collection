// 2) Между первым положительным элементом последовательности и последним элементом, значение которого больше его порядкового номера
//  0 1 2 3 4
// -2 0 2 3 5
#include <stdio.h>
#include <math.h>
#define N 5

int func(int A[])
{
	int i, index_plus = 0, index_last = 0, result = 0, count = 0, flag = 0;
	for (i = 0; i < N; i++)
	{
		if (A[i] >= 0) // Тут 0 тоже положительное число
		{
			index_plus = i;
			break;
		}
	}
	
	for (i = N; i > index_plus; i--)
	{
		if (A[i] > i)
		{
			index_last = i;
			flag = 1;
			break;
		}
	}
	
	if (!flag)
		index_last = N;
	
	for (i = index_plus + 1; i < index_last; i++)
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
