// Функции, которые определены в "Header.h" и используются в "main.c"
#include "Header.h"

// (1) Определение длины строки
int dlina_stroki(char* stroka) 
{
	if (stroka == NULL || stroka[0] == '\n')
		return 0;
		
	int counter = 0;
	for (int i = 0; stroka[i] != '\0'; i++) // (2) Способ: stroka[counter] != '\0'; counter++
		counter++;
	
	return counter;
}

// (2) Сравнение строк в лексикографическом порядке
int leks_order(char* stroka1, char* stroka2) 
{
	if (stroka1 == NULL || stroka2 == NULL || stroka1[0] == '\n' || stroka2[0] == '\n') 
		return 0;
	
	for (; *stroka1 && (*stroka1 == *stroka2); stroka1++, stroka2++) 
	{	}
	
	int result = *stroka1 - *stroka2;
	if (result >= 0)
		return 1;
	else // sorted
		return 2;
}

// (3) Сравнение строк по длине
int cmp_strok(char* stroka1, char* stroka2) 
{
	if (stroka1 == NULL || stroka2 == NULL || stroka1[0] == '\n' || stroka2[0] == '\n') 
		return 0;
	
	int len1 = dlina_stroki(stroka1);
	int len2 = dlina_stroki(stroka2);
	if (len1 == len2) 
		return 1;
	else if (len1 < len2) 
		return 2;
	else
		return 3;
}

// (4) Копирование строк
char* cpy_strok(char* stroka1, char* stroka2) 
{
	if (stroka1 == NULL || stroka2 == NULL || stroka1[0] == '\n' && stroka2[0] == '\n')
		return 0;
	
	int i;
	for (i = 0; stroka1[i]; i++) 
	{
		stroka2[i] = stroka1[i];
	}
	stroka2[i] = '\0'; // Строка закончена | i - последний элемент?
	
	return stroka2;
}

// (5) Поиск подстроки в строке 
int poisk_podstroki(char* stroka1, char* stroka2) 
{
	if (stroka1 == NULL || stroka2 == NULL || stroka1[0] == '\n' || stroka2[0] == '\n') 
		return 0;
	
	while (*stroka1) 
	{
		while (*stroka1 && *stroka2 && (*stroka1 == *stroka2)) 
		{
			// *stroka1 && *stroka2 (проверяем что не указывают на 0)
			stroka1++;
			stroka2++;
		}
		if (*stroka2 == '\0') // Found
			return 1;
		
		stroka1 = stroka1 + 1; // Итерация
	}
	
	return 2; // Not Found
}

// (6) Исключение лишних пробелов
char* iskl_probelov(char* stroka1) 
{
	if (stroka1 == NULL || stroka1[0] == '\n') 
		return 0;
	
	char* result = (char*)calloc(strlen(stroka1) + 1, sizeof(char));
	char* token = strtok(stroka1, " ");
	
	while (token != NULL) 
	{
		strcat(result, token);
		strcat(result, " ");
		//printf("%s ", token);
		token = strtok(NULL, " ");
	}
	
	return result;
}

// (7) Перевод строки цифр в число
int cifra_chislo(const char* str) 
{
	int result = 0;
	int sign = 1; // '+'
	
	if (str == NULL)
		return 0;
	
	while (*str == ' ' || *str == '\n')
		str++; // Пропускаем их 
	
	if (*str == '+' || *str == '-') 
	{
		if (*str == '-')
			sign = -1;
		
		str++; // Если нашли знак +, то пропускаем его
	}
	while (*str >= '0' && *str <= '9') 
	{
		result = (result * 10) + (*str - '0'); // * 10 (прибавляем след. число)
		str++; // Итерация
	}
	// 123
	// 10 + 2 = 12 | 12*10=120+3=123
	return result * sign;
}

// (8) Перевод числа в строку символов 
int chislo_stroka(int value, char* stroka, int base) 
{
	if (base < 2 || base > 36 || stroka == NULL) 
	{
		*stroka = '\0';
		return 0;
	} 
	
	char* originalStr = stroka;
	int quotient = value;
	
	do 
	{
		*stroka = '0' + abs(quotient % base);
		stroka++;
		quotient /= base;
	} 
	while (quotient);
	
	if (value < 0 && base == 10) 
	{
		*stroka = '-';
		stroka++;
	}
	*stroka = '\0';
	
	// Reverse the string
	char* start = originalStr;
	char* end = stroka - 1;

	while (start < end) 
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	
	return 1;
}

// (9) Перекодировка букв латинского алфавита из верхнего регистра в нижний
int verhniy_nizhniy(char* stroka1) 
{
	if (stroka1 == NULL || stroka1[0] == '\n') 
		return 0;
	
	for (int i = 0; stroka1[i] != '\0'; i++) 
	{
		if (stroka1[i] >= 'A' && stroka1[i] <= 'Z') 
			stroka1[i] = stroka1[i] + ('a' - 'A');
	}
	
	return 1;
}

// (10) Инвертирование строки
int inverse(char* stroka1) 
{
	if (stroka1 == NULL || stroka1[0] == '\n')
		return 0;
	
	int i, len, temp;
	len = dlina_stroki(stroka1);
	
	for (i = 0; i < len / 2; i++) 
	{
		temp = stroka1[i];
		stroka1[i] = stroka1[len - i - 1];
		stroka1[len - i - 1] = temp;
	}
	
	return 1;
}
