#include "Header.h"

int main() 
{
	char msg[600];
	char str[600];
	int choose = 0, result = 0;
	char* string_result = NULL;
	
	printf(" Enter (1-10):\n---> ");
	scanf("%d", &choose);
	getc(stdin);
	
	switch (choose) 
	{
	case 1:
		fgets(msg, 600, stdin);
		
		printf("%d", dlina_stroki(msg));
		
		break;
	case 2:
		fgets(msg, 600, stdin);
		fgets(str, 600, stdin);
		
		printf("%d", leks_order(msg, str));
		
		if (leks_order(msg, str) == 2) 
			printf("\nSorted");
		else if (leks_order(msg, str) == 1) 
			printf("\nUnsorted");
		
		break;
	case 3:
		fgets(msg, 600, stdin);
		fgets(str, 600, stdin);
		
		printf("%d", cmp_strok(msg, str));
		
		if (cmp_strok(msg, str) == 1) 
			printf("\nmsg = str");
		else if (cmp_strok(msg, str) == 2)
			printf("\nmsg < str");
		else if (cmp_strok(msg, str) == 3)
			printf("\nmsg > str");
		
		break;
	case 4:
		fgets(msg, 600, stdin);
		fgets(str, 600, stdin);
		
		printf("%s", cpy_strok(msg, str));
		
		break;
	case 5:
		fgets(msg, 600, stdin);
		fgets(str, 600, stdin);
		
		printf("%d", poisk_podstroki(msg, str));
		
		if (poisk_podstroki(msg, str) == 1)
			printf("\nFound 2 string in 1");
		else if (poisk_podstroki(msg, str) == 2)
			printf("\nNot found");
		
		break;
	case 6:
		fgets(msg, 600, stdin);
		
		string_result = iskl_probelov(msg);
		printf("%s", string_result);
		
		free(string_result);
		
		break;
	case 7:
		fgets(msg, 600, stdin);
		
		result = cifra_chislo(msg);
		printf("%d", result);
		
		break;
	case 8:
		int chislo, base;
		(void)scanf("%d", &chislo); // void из-за visual studio
		(void)scanf("%d", &base);
		
		result = chislo_stroka(chislo, msg, base);
		if (msg[0] == '\0')
			;
		else
			printf("%s\n", msg);
		printf("%d", result);
		
		break;
	case 9:
		fgets(msg, 600, stdin);
		
		result = verhniy_nizhniy(msg);
		printf("%s\n", msg);
		printf("%d", result);
		
		break;
	case 10:
		fgets(msg, 600, stdin);
		
		result = inverse(msg);
		printf("%s\n", msg);
		printf("%d", result);
		
		break;
	default:
		printf("Incorrect Input");
		break;
	}
	return 0;
}
