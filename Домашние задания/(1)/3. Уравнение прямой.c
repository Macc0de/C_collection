/*
Вводятся координаты двух точек - четыре вещественных числа.
Напишите программу, которая выводит на экран уравнение прямой в виде y=kx+b, проходящей через эти точки.

Если введены координаты (3,2) и (1,7), в результате должно получиться уравнение y=-2.50x+9.50.
Если введены координаты (1,2) и (3,7), в результате должно получиться уравнение y=2.50x-0.50.
Если введены координаты (1,0.75) и (-1,-0.75), в результате должно получиться уравнение y=0.75x.

Если введены координаты (1,1) и (1,0), в результате должно получиться уравнение х=1.00.
Если введены координаты (0,1) и (1,1), в результате должно получиться уравнение y=1.00.
Input: 
1 2
3 7
Output: 
y=2.50x-0.50
*/
#include <stdio.h>

int main()
{
	float x1, y1, x2, y2;
	float k, b;
	scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);

	k = (y1 - y2) / (x1 - x2);
	b = y2 - (k * x2);
	
	if ((x1 - x2) == 0 || (x1 - x2) == -0)
		printf("x=%.2f", y1 - y2);
	else if (k == 0 || k == -0)
		printf("y=%.2f", b);
	else if (b > 0)
		printf("y=%.2fx+%.2f", k, b);
	else if(b < 0)
		printf("y=%.2fx%.2f", k, b);
	else if(b == 0)
		printf("y=%.2fx", k);

	return 0;
}
