// Из рисунка (3)
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
	scanf("%d", &n); // Ввод: 4
	
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
	function = pow((1+x), -3);
	
	for (int i = 0; i < n; i++, sign *= (-1))
	{
		temp = (((i+1)*(i+2)*(pow(x, i+1))) / 2.0f) * sign;
		summa += temp;
		posledniy = temp;
		printf("%f", temp); // Delete
	}
	
	// Основной вывод
	printf("\n\nx: %.2f, n: %d", x, n);
	printf("\nSumma ryada: %.2lf", summa);
	printf("\nFunction: %f", function);
	printf("\nPosledniy chlen ryada: %.2f", fabs(posledniy));
	printf("\nRaznost': %.2f\n", summa - function);
	
	return 0;
}
