// Подсчет общего кол-ва гласных и согласных букв в строке
// (1) Способ
#include <stdio.h>
#include <ctype.h>

void func(char* msg)
{
	int vowels = 0, consonants = 0, i;
	for (i = 0; msg[i] != '\0'; i++) 
	{
		if ((tolower(msg[i]) == 'b') || (tolower(msg[i]) == 'c') || (tolower(msg[i]) == 'd') || (tolower(msg[i]) == 'f') || 
		(tolower(msg[i]) == 'g') || (tolower(msg[i]) == 'h') || (tolower(msg[i]) == 'j') || (tolower(msg[i]) == 'k') || 
		(tolower(msg[i]) == 'l') || (tolower(msg[i]) == 'm') || (tolower(msg[i]) == 'n') || (tolower(msg[i]) == 'p') || 
		(tolower(msg[i]) == 'q') || (tolower(msg[i]) == 'r') || (tolower(msg[i]) == 's') || (tolower(msg[i]) == 't') || 
		(tolower(msg[i]) == 'v') || (tolower(msg[i]) == 'w') || (tolower(msg[i]) == 'x') || (tolower(msg[i]) == 'y') || 
		(tolower(msg[i]) == 'z')) 
		{
			consonants++;
		}
		else if ((tolower(msg[i]) == 'a') || (tolower(msg[i]) == 'e') || (tolower(msg[i]) == 'o') || 
		(tolower(msg[i]) == 'u') || (tolower(msg[i]) == 'y') || (tolower(msg[i]) == 'i')) 
		{
			vowels++;
		}
	}
	printf("Total score: %d %d", consonants, vowels);
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	
	func(msg);
	
	return 0;
}
//======================================================================================================
// (2) Способ
#include <stdio.h>
#include <ctype.h>

void func(char* msg)
{
	int vowels = 0, consonants = 0, i, j;
	int len = strlen(not_vowels), len1 = strlen(str_vowels);
	const char* not_vowels = "bcdfghjklmnpqrstvwxyz";
	const char* str_vowels = "aeouyi";
	for (i = 0; msg[i] != '\0'; i++) 
	{
		int is_not_vowel = 0;
		for (j = 0; j < len; j++) // CONSONANTS
		{
			if (tolower(msg[i]) == not_vowels[j]) // msg[i] - текущий, not_vowels - не гласная
			{
				is_not_vowel = 1;
				break;
			}
		}
		if (is_not_vowel) 
		{
			consonants++;
		}
		else // VOWELS
		{
			int isvowel = 0;
			for (j = 0; j < len1; j++) {
				if (tolower(msg[i]) == str_vowels[j]) {
					isvowel = 1;
					break;
				}
			}
			if (isvowel) {
				vowels++;
			}
		}
	}
	printf("Total score: %d %d", consonants, vowels);
}

int main()
{
	char msg[30];
	fgets(msg, 30, stdin);
	
	func(msg);
	
	return 0;
}
