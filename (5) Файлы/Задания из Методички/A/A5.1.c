#include <stdio.h>
#include <string.h>

int main()
{
	FILE* file = fopen("data.txt", "r"); // Если в папке - "dr\\file.txt"
	
	char buffer[30];
	int count_str = 2; // Кол-во строк введеное пользователем

	for(int i = 0; i < count_str && fgets(buffer, 30, file); i++)
	{// fgets() проверяет можно ли еще считывать файл
		int len = strlen(buffer);
		if(buffer[len - 1] == '\n') // -2 (вывод с переносом)
			buffer[strlen(buffer) - 1] = '\0';		
		
		printf("%s", buffer);
	}
		
	fclose(file);
	
	return 0;
}
