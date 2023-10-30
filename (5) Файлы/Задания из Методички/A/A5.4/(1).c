#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* input_file = "examp.txt";
	char* output_file = "res.txt"; // Создадим новый файл
	FILE* file = fopen(input_file, "r"); // Откуда считывать(файл)
	
	if(file == NULL)
	{
		printf("Incorrect");
		return 1;
	}
	
	fseek(file, 0L, SEEK_END); // Переводит указатель в конец файла
	long sz = ftell(file); // Кол-во символов между началом и концом файла
	fseek(file, 0L, SEEK_SET); // В начало файла вернулись
	
	char* buffer = malloc(sz * sizeof(char) + 1);
	char c = 0;
	int n = 0;
	
	while ((c = fgetc(file)) != EOF) // fgetc - получает один символ из файла
    {
        buffer[n++] = c;
    }
	
	fclose(file);
	
	// с malloc не работает
	char* reversed_words = calloc(sz + 1, sizeof(char)); // Для целой строки(+заполн. 0)
	char* token = strtok(buffer, " ");
	char temp_buff[50] = {};
	
	while(token)
	{
		strrev(token);
		strcpy(temp_buff, token); // Записываем слова
		token = strtok(NULL, " "); // Получаем следующее слово, после того которое только что обработали
		strcat(reversed_words, temp_buff); // Перевернутые слова запсиываем в reversed_words
		
		if(token) // Если следующее слово есть, то ставим пробел после него
		{
			strcat(reversed_words, " ");
		}
	}
	reversed_words[sz] = '\0';
	
	// Записали в новый файл
	FILE* file2 = fopen(output_file, "w");
	fprintf(file2, reversed_words); // Записываем в файл содержимое buffer
	
	fclose(file2);
	
	return 0;
}
