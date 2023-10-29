// Пример вывода: "служебное слово" - "кол-во в файле"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
	FILE* file = fopen("sys.txt", "r");
	char buffer[30];
	char* list[] = {"struct", "union", "for", "int"}; // Список служебных слов
	
	// Кол-во слов в словаре
	int count_special_words = 0, i;
	for(i = 0; i < sizeof(list) / sizeof(list[0]); i++)
	{
		count_special_words++;
	}
	
	int* count_words = calloc(count_special_words, sizeof(int)); // Массив кол-ва служебных слов
	while(fscanf(file, "%s", buffer) == 1) // Проход по каждому слову в файле
	{
		for(i = 0; i < count_special_words; i++)
		{
			if(strcmp(list[i], buffer) == 0)
			{
				count_words[i]++; // Кол-во слов
			}
		}
	}
	
	for(i = 0; i < count_special_words; i++)
	{
		if(count_words[i]) // Выводит только те служебные слова, которые встречаются
			printf("%s: %d\n", list[i], count_words[i]);
	}
		
	free(count_words);
	
	fclose(file);
	
	return 0;
}
