/*
Вводится предложение, содержащее слова, разделенные пробелами. Слова состоят из строчных букв латинского алфавита. 
Первое слово в предложении начинается с большой буквы. Ввод предложения заканчивается точкой.

Написать программу, которая меняет порядок слов в заданном предложении на обратный и выводит результат на печать.

После перестановки слов первое слово в предложении должно начинаться с большой буквы, 
а остальные слова должны состоять из строчных букв.

Input:
Mama mila ramy.
Output:
Ramy mila mama.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void low_reg(char** array, int count) // Перевод в нижний регистр
{
    int i = 0, j = 0;
    for (i = 0; i < count; i++)
    {
        for (j = 0; array[i][j]; j++)
        {
            array[i][j] = tolower(array[i][j]);
        }
    }
}

char** reverse(char** array, int count) // Переворот каждого слова
{
    low_reg(array, count);

    int i = 0, j = count - 1;
    for (i = 0; i < count / 2; i++, j--)
    {
        char* temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    array[0][0] = toupper(array[0][0]); // Самое первое слово с большой буквы - начало предложения

    return array;
}

int main()
{
    char str[600];
    fgets(str, 600, stdin);

    for(int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
            str[i] = '\0';
    }

    int count_words = 0;
    char* arr_words[100] = {};

    char* token = strtok(str, " ");
    while (token)
    {
        arr_words[count_words++] = token; // Запись в массив слов

        token = strtok(NULL, " ");
    }

    reverse(arr_words, count_words);

    for (int i = 0; i < count_words; i++)
    {
        if (i == count_words - 1)
            printf("%s.", arr_words[i]);
        else
            printf("%s ", arr_words[i]);
    }

    return 0;
}
