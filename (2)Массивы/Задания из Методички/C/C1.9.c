#include <stdio.h>
#include <string.h>
 
char reVal(int num) // Из числа в символы
{
    if (num >= 0 && num <= 9) // Если число от 0 до 9
        return (char)(num + '0'); // Возвращаем как символ
		
    else // Если число больше 9 или буква
        return (char)(num - 10 + 'A'); // Возвращаем как символ(по порядку)
}
 
void strev(char *str) // Переворачивает строку
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) // По длине строки (/2 - только до середины строки-числа)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;
	
    // Разделить на основание и взять остаток
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base); // 48
        inputNum /= base; // Записавши в массив, переходим к другой цифре числа
    }
    res[index] = '\0'; // Конец строки
	
    strev(res); // Перевернуть результат
	
    return res;
}

int main()
{	
	// base - основание может быть любым
	int inputNum = 0, base = 0;
    char res[100];
	
	printf("Vvedite chislo and base: ");
	
	scanf("%d %d", &inputNum, &base);
	printf ("%s", fromDeci(res, base, inputNum));
	
	return 0;
}
