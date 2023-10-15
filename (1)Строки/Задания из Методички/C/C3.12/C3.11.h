#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
Функции:
1 Определение длины строки 
2 Сравнение строк в лексикографическом порядке
3 Сравнение строк по длине
4 Копирование строк
5 Поиск подстроки в строке
6 Исключение лишних пробелов
7 Перевод строки цифр в число
8 Перевод числа в строку символов 
9 Перекодировка букв латинского алфавита из верхнего регистра в нижний
10 Инвертирование строки
*/
int dlina_stroki(char* stroka); 
int leks_order(char* stroka1, char* stroka2);
int cmp_strok(char* stroka1, char* stroka2);
char* cpy_strok(char* stroka1, char* stroka2); 
int poisk_podstroki(char* stroka1, char* stroka2); 
char* iskl_probelov(char* stroka1);
int cifra_chislo(const char* stroka1); 
int chislo_stroka(int value, char* msg, int base); 
int verhniy_nizhniy(char* stroka1);
int inverse(char* stroka1);		

#endif
