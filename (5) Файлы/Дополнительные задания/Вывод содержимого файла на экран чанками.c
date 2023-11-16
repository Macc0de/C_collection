#include <stdio.h>
#include <string.h>
#define CHUNK 1 // Кол-во считиваемых символов

int main(int argc, char const* argv[])
{
	char buf[CHUNK];
	FILE* file;
	size_t nread;
	
	file = fopen("test.txt", "r");
	
	if(file)
	{
		/* Считывает sizeof(buf) объектов - каждый объект по 1 символу в длину из file
		и помещает их в массив buf. Возвращает кол-во действительно считанных объектов */
		while((nread = fread(buf, CHUNK, sizeof(buf), file)) > 0)
		{
			/* Записывает nread объектов — каждый объект по 1 символу
			в длину — в file из buf */
			fwrite(buf, CHUNK, nread, stdout); // Выводит CHUNK символов
		}
			
		if(ferror(file)) // Проверяет наличие ошибок чтения или записи в файле
			perror("Error"); // Выводит сообщение об ошибке
			
		fclose(file);
	}
	
	return 0;
}
