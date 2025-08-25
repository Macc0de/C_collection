#include <stdio.h>
#include <string.h>

char* func_strstr(char* string, char* search_word)
{
	if(string == NULL || search_word == NULL)
		return NULL;
	
	int len_word = strlen(search_word);
	if(len_word == 0)
		return string;
	
	for(int i = 0, j = 0; string[i]; i++)
	{
		if(string[i] == search_word[j])
		{
			j++;
			if(j == len_word)
				return &string[i - len_word + 1];
		}
		else
			j = 0;
	}
	
	return NULL;
}

int main()
{
	char* str = "swimmingpool";
	char* word = "pool";
	
	char* res = func_strstr(str, word);
	
	if(res == NULL)
		printf("Not found");
	else
		printf("Found - substring starts with character: %d", res-str+1);
	
	return 0;
}
