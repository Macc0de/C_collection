// 1) Между первым четным элементом последовательности и последним элементом, значение которого равно квадрату его порядкового номера
// 1 2 3 4 1 - sum:8, count:3
#include <stdio.h>
#include <math.h>
#define N 5

int func(int A[])
{
	int i, index_chet = 0;
	for (i = 0; i < N; i++)
	{
		if (A[i] % 2 == 0)
		{
			index_chet = i;
			break;
		}
	}
	
	int index_last = 0;
	int flag = 0;
	for (i = N; i > index_chet; i--) // С конца
	{
		if (A[i] == pow(i, 2)) // Квадрат порядкового номера
		{
			index_last = i;
			flag = 1;
			break;
		}
	}
	
	if (!flag) // Если не нашли, то считаем до конца массива
		index_last = N;
	
	int result = 0, count = 0;
	for (i = index_chet + 1; i < index_last; i++) 
	{
		result += A[i]; // Sum
		count++;
	}
	
	printf("\nSum: %d. Count: %d", result, count);
	// Кол-во (index_last-index_chet)
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
