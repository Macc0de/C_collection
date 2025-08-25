#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* input_file = "examp.txt";
	char* output_file = "res.txt";
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
	int n = 0;
	char c = 0;
	while ((c = fgetc(file)) != EOF) // fgetc - получить один символ из файла
    {
        buffer[n++] = c;
    }
	
	fclose(file);
	
	// Перевернули + Записали в новый файл
	strrev(buffer);
	FILE* file2 = fopen(output_file, "w");
	fprintf(file2, buffer); // Записываем в файл содержимое buffer
	
	fclose(file2);
	
	return 0;
}
