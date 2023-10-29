// Из рисунка (6)
// 0.5
#include <stdio.h>
#include <math.h>

float is_pow(float num, int stepen)
{
	float pow = 1.0;
	for (int i = 1; i <= stepen; i++)
		pow *= num;
	
	return pow;
}  

int main()
{
	float x = 0.0, e = 0.0;
	float summa = 0.0, temp = 0.0, posledniy = 0.0;
	int sign = 1;
	
	printf("x: ");
	scanf("%f", &x); // Ввод: 0.5
	printf("e: ");
	scanf("%f", &e); // Ввод: 8
	
	if (x < -1 || x > 1) // Область сходимости - можно от -1 до 1
	{
		printf("Incorrect x!");
		return 1;
	}
	if (e < 0)
	{
		printf("Incorrect e!");
		return 1;
	}
	
	float function = 0.0;
	function = log(x + (pow((pow(x,2) + 1), 0.5)));
	
	for (int i = 1; i < e; i += 2, sign *= (-1))
	{
		float chislitel = 1.0;
		float znamenatel = 1.0;
		for (int j = 1; j < i; j += 2) // Сверху
		{
			chislitel *= j;
		}
		for (int k = 2; k < i; k += 2) // Снизу
		{
			znamenatel *= k;
		}
		
		temp = ((float)(chislitel * is_pow(x, i)) / (float)(znamenatel * i)) * sign; // float
		summa += temp;
		posledniy = temp;
		printf("%f", temp); // Delete
	}
	
	// Основной вывод
	printf("\n\nx: %.2f, e: %.2f", x, e);
	printf("\nSumma ryada: %.2lf", summa);
	printf("\nFunction: %f", function);
	printf("\nPosledniy chlen ryada: %.2f", fabs(posledniy));
	printf("\nRaznost': %.2f\n", summa - function);
	
	return 0;
}
