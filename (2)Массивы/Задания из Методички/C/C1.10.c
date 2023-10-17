/*
Пример ввода:
4 2   Yes     2 2   No
2 1           1 1
1 1           2 2
*/
#include <stdio.h>
#include <math.h>

int geometry(float Ax, float Ay, float Bx, float By, float Cx, float Cy)
{
	// Длина каждой стороны треугольника должны быть меньше суммы длин остальных сторон 
	float Ab = 0.0, Ac = 0.0, Bc = 0.0;
	
	// Справа в комментариях записаны значения, если ввод был как в примере
	Ab = sqrt((pow((Ax - Bx), 2)) + (pow((Ay - By), 2))); // 2.24
	Ac = sqrt((pow((Ax - Cx), 2)) + (pow((Ay - Cy), 2))); // 3.16
	Bc = sqrt((pow((Bx - Cx), 2)) + (pow((By - Cy), 2))); // 1
	
	int flag = 0;
	if (((Ab + Ac) > Bc) && ((Ab + Bc) > Ac) && ((Bc + Ac) > Ab)) // Являются ли вершинами треугольника?
	{
		printf("(1)\nYes");
		flag = 1;
	}
	else
	{
		printf("No.");
		return 1;
	}
	
	if (flag == 1)
	{
		printf("\n(2)"); // Уравнения сторон
		
		float k1 = 0.0, b1 = 0.0, k2 = 0.0, b2 = 0.0, k3 = 0.0, b3 = 0.0;
		
		k1 = ((Ay - By) / (Ax - Bx)); // 0.5
		b1 = (By - (k1 * Bx)); // 0
		
		printf("\nEquation of AB: y = %.1fx + %.1f", k1, b1);
		
		k2 = ((By - Cy) / (Bx - Cx)); // 0
		b2 = (Cy - (k2 * Cx)); // 1
		
		printf("\nEquation of BC: y = %.1fx + %.1f", k2, b2);
		
		k3 = ((Ay - Cy) / (Ax - Cx)); // 0.333333
		b3 = (Cy - (k3 * Cx)); // 0.7
		
		printf("\nEquation of AC: y = %.1fx + %.1f", k3, b3);
		
		
		printf("\n(3)\n"); // Уравнения биссектрис
		
		float l2 = 0.0, Mx1 = 0.0, My1 = 0.0, k4 = 0.0, b4 = 0.0; // Биссектриса (AM)
		
		l2 = (Ab / Ac);
		Mx1 = ((Cx + (l2 * Bx)) / (1 + l2)); // 1.41
		My1 = ((Cy + (l2 * By)) / (1 + l2)); // 1
		k4 = ((My1 - Ay) / (Mx1 - Ax)); // 0.39
		b4 = (My1 - (k4 * Mx1)); // 0.45
		
		printf("Equation of Bisector(AM): y = %.2fx + %.2f", k4, b4);
		
		float l1 = 0.0, Mx2 = 0.0, My2 = 0.0, k5 = 0.0, b5 = 0.0;; // Биссектриса (BM)
		
		l1 = (Ab / Bc);
		Mx2 = ((Ax + (l1 * Cx)) / (1 + l1)); // 1.93
		My2 = ((Ay + (l1 * Cy)) / (1 + l1)); // 1.31
		k5 = ((My2 - By) / (Mx2 - Bx)); // -4.24
		//((By - My2) / (Bx - Mx2)) без разницы
		b5 = (My2 - (k5 * Mx2)); // 9.47
		
		printf("\nEquation of Bisector(BM): y = %.2fx + %.2f", k5, b5);
		
		float l3 = 0.0, Mx3 = 0.0, My3 = 0.0, k6 = 0.0, b6 = 0.0; // Биссектриса (CM)
		
		l3 = (Ac / Bc);
		Mx3 = ((Ax + (l3 * Bx)) / (1 + l3)); // 2.48
		My3 = ((Ay + (l3 * By)) / (1 + l3)); // 1.24
		k6 = ((My3 - Cy) / (Mx3 - Cx)); // 0.16
		b6 = (My3 - (k6 * Mx3)); // 0.84
		
		printf("\nEquation of Bisector(CM): y = %.2fx + %.2f", k6, b6);
		
		
		printf("\n(4)\n"); // Уравнения медиан
		
		float Kx1 = 0.0, Ky1 = 0.0, k7 = 0.0, b7 = 0.0; // Медиана (AK)
		
		Kx1 = ((Bx + Cx) / 2); // 1.5
		Ky1 = ((By + Cy) / 2); // 1
		k7 = ((Ky1 - Ay) / (Kx1 - Ax)); // 0.4
		b7 = (Ky1 - (k7 * Kx1)); // 0.4
		
		printf("Equation of Median(AK): y = %.2fx + %.2f", k7, b7);
		
		float Kx2 = 0.0, Ky2 = 0.0, k8 = 0.0, b8 = 0.0; // Медиана (BK)
		
		Kx2 = ((Ax + Cx) / 2); // 2.5
		Ky2 = ((Ay + Cy) / 2); // 1.5
		k8 = ((Ky2 - By) / (Kx2 - Bx)); // 1
		b8 = (Ky2 - (k8 * Kx2)); // -1
		
		printf("\nEquation of Median(BK): y = %.2fx + %.2f", k8, b8);
		
		float Kx3 = 0.0, Ky3 = 0.0, k9 = 0.0, b9 = 0.0; // Медиана (CK)
		
		Kx3 = ((Ax + Bx) / 2); // 3
		Ky3 = ((Ay + By) / 2); // 1.5
		k9 = ((Ky3 - Cy) / (Kx3 - Cx)); // 0.25
		b9 = (Ky3 - (k9 * Kx3)); // 0.75
		
		printf("\nEquation of Median(CK): y = %.2fx + %.2f", k9, b9);
		
		
		printf("\n(5)\n"); // Уравнения высот
		
		float k_AD = 0.0, b10 = 0.0;
		
		if (k2 == 0)
			printf("Undefined k! (for Height AD)");
		else
		{
			k_AD = ((-1) / k2);
			b10 = (Ax - (Ay * k_AD));
			
			printf("Equation of Height(AD): y = %.2fx + %.2f", k_AD, b10);
		}
		
		float k_BD = 0.0, b11 = 0.0;
		
		k_BD = ((-1) / k3); // 3
		b11 = (Bx - (By * k_BD)); // 5
		
		printf("\nEquation of Height(BD): y = %.2fx + %.2f", k_BD, b11);
		
		float k_CD = 0.0, b12 = 0.0;
		
		k_CD =  ((-1) / k1); // -2
		b12 = (Cx - (Cy * k_CD)); // 3
		
		printf("\nEquation of Height(CD): y = %.2fx + %.2f", k_CD, b12);
		
		
		printf("\n(6)\n"); // Находится точка внутри или снаружи треугольника?
		
		float Px = 0, Py = 0;
		
		printf("Coordinations of 4th point: "); // 3 1.5(1.66)
		scanf("%f %f", &Px, &Py);
		printf("P(%.2f;%.2f)", Px, Py);
		
		float a = (((Ax - Px)*(By - Ay))-((Bx - Ax)*(Ay - Py)));
		float b = (((Bx - Px)*(Cy - By))-((Cx - Bx)*(By - Py)));
		float c = (((Cx - Px)*(Ay - Cy))-((Ax - Cx)*(Cy - Py)));
		
		if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
		{
			printf("\nYes\n");
			return 2;
		}
		else 
			printf("\nNo\n");
		
		return 0;
	}
}

int main()
{
	int A_x = 0, A_y = 0;
	int B_x = 0, B_y = 0;
	int C_x = 0, C_y = 0;
	
	printf("Coordinations of A: ");
	scanf("%d %d", &A_x, &A_y);
	
	printf("Coordinations of B: ");
	scanf("%d %d", &B_x, &B_y);
	
	printf("Coordinations of C: ");
	scanf("%d %d", &C_x, &C_y);
	
	printf("A(%d;%d) B(%d;%d) C(%d;%d)\n\n", A_x, A_y, B_x, B_y, C_x, C_y);
	
	geometry(A_x, A_y, B_x, B_y, C_x, C_y); // Функция всех вычислений
	
	return 0;
}
