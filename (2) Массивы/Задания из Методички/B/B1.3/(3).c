// Из рисунка (3)
#include <stdio.h>
#include <math.h>

int is_pow(int num, int stepen)
{
	int pow = 1;
	for (int i = 1; i <= stepen; i++)
		pow *= num;
	
	return pow;
}

int factorial(int number)    
{    
	int i, fact = 1;         
	for(i = 1; i <= number; i++)
	{    
		fact = fact * i;    
	}     
	
	return fact;  
}   

int main()
{
	float x = 0.0, e = 0.0;
	float summa = 0.0, temp = 0.0, posledniy = 0.0;
	int sign = 1;
	
	printf("x: ");
	scanf("%f", &x); // Ввод: 2
	printf("e: ");
	scanf("%f", &e); // Ввод: 8
	
	if (e < 0)
	{
		printf("Incorrect input!");
		return 1;
	}
	
	float function = 0.0;
	function = cos(x);
	for (int i = 0; i < e; i+=2, sign*=(-1)) // temp < e - возможно
	{
		temp = ((float)abs(is_pow(x, i)) / (float)abs(factorial(i))) * sign;
		summa += temp;
		posledniy = temp;
		printf("%f", temp); // Delete
	}
	
	// Основной вывод
	printf("\n\nx: %.2f, e: %.2f", x, e);
	printf("\nSumma ryada: %.2lf", summa);
	printf("\nFunction cos(x): %f", function);
	printf("\nPosledniy chlen ryada: %.2f", fabs(posledniy));
	printf("\nRaznost': %.2f\n", summa - function);
	
	return 0;
}
