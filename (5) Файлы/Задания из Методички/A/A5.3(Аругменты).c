// Пример запуска через cmd: ./a.exe examp.txt res.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Incorrect!");
		return 1;
	}
	
	char* data = argv[1];
	FILE* file = fopen(data, "r"); // Откуда считывать(файл)
	
	if(file == NULL)
	{
		printf("Incorrect");
		return 1;
	}
	
	fseek(file, 0L, SEEK_END);
	long sz = ftell(file);
	fseek(file, 0L, SEEK_SET); // В начало файла вернулись
	
	char* buffer = malloc(sz * sizeof(char) + 1);
	int n = 0, c = 0;
	
	while ((c = fgetc(file)) != EOF)
    {
        buffer[n++] = (char) c;
    }
	fclose(file);
	
	// Перевернули + Записали в новый файл
	strrev(buffer);
	char* data2 = argv[2];
	file = fopen(data2, "w");
	
	if(file == NULL)
	{
		printf("Incorrect");
		return 1;
	}
	fprintf(file, buffer);
	
	fclose(file);
	
	return 0;
}
