// Из рисунка (1)
#include <stdio.h>
#include <math.h>

int is_pow(int num, int stepen)
{
	int pow = 1;
	for (int i = 1; i <= stepen; i++)
		pow *= num;
	
	return pow;
}  

int main()
{
	float x = 0.0;
	float summa = 0.0, temp = 0.0, posledniy = 0.0;
	int sign = 1, n = 0;
	
	printf("x: ");
	scanf("%f", &x); // Ввод: 1
	printf("n: ");
	scanf("%d", &n); // Ввод: 8
	
	if (x < -1 || x > 1) // Область сходимости от -1 до 1
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
	function = atan(x);
	
	for (int i = 1; i < n; i += 2, sign *= (-1))
	{
		temp = ((float)(is_pow(x, i)) / (float)i) * sign;
		summa += temp;
		posledniy = temp;
		printf("%f", temp); // Delete
	}
	
	// Основной вывод
	printf("\n\nx: %.2f, n: %d", x, n);
	printf("\nSumma ryada: %.2lf", summa);
	printf("\nFunction Arctg(x): %f", function);
	printf("\nPosledniy chlen ryada: %.2f", fabs(posledniy));
	printf("\nRaznost': %.2f\n", summa - function);
	
	return 0;
}
