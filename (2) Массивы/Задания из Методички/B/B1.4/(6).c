// Из рисунка (6)
#include <stdio.h>
#include <math.h>

int main()
{
	float x = 0.0;
	float summa = 0.0, temp = 0.0, posledniy = 0.0;
	int sign = 1, n = 0;
	
	printf("x: ");
	scanf("%f", &x); // Ввод: 0.5
	printf("n: ");
	scanf("%d", &n); // Ввод: 8
	
	if (x <= -1 || x >= 1) // Область сходимости
	{
		printf("Incorrect x!");
		return 1;
	}
	if (n < 0)
	{
		printf("Incorrect n!");
		return 1;
	}
	
	float function = 0.0;
	function = pow((1 - pow(x, 2)), -0.5);
	
	for (int i = 0; i < n; i += 2)
	{
		int chislitel = 1, znamenatel = 1;
		for (int j = 1; j < i; j += 2) // Вверх
		{
			chislitel *= j;
		}
		for (int k = 2; k <= i; k += 2) // Вниз
		{
			znamenatel *= k;
		}
		
		temp = ((float)(chislitel * pow(x, i)) / (float)znamenatel);
		summa += temp;
		posledniy = temp;
		printf("%f", temp); // Delete
	}
	
	// Основной вывод
	printf("\n\nx: %.2f, n: %d", x, n);
	printf("\nSumma ryada: %.2lf", summa);
	printf("\nFunction: %f", function);
	printf("\nPosledniy chlen ryada: %f", fabs(posledniy));
	printf("\nRaznost': %f\n", summa - function);
	// Отрицательный ноль возможен
	
	return 0;
}
