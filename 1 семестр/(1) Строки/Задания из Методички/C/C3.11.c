// кот. код. для
// кот. собака. Пес, вот: так! получается
#include <stdio.h>
#include <string.h>
#include <windows.h> // Для кириллицы

int MyToUpper(char r)
{
	switch (r)
	{
	case 'а': r = 'А'; break;
	case 'б': r = 'Б'; break;
	case 'в': r = 'В'; break;
	case 'г': r = 'Г'; break;
	case 'д': r = 'Д'; break;
	case 'е': r = 'Е'; break;
	case 'ё': r = 'Ё'; break;
	case 'ж': r = 'Ж'; break;
	case 'з': r = 'З'; break;
	case 'и': r = 'И'; break;
	case 'й': r = 'Й'; break;
	case 'к': r = 'К'; break;
	case 'л': r = 'Л'; break;
	case 'м': r = 'М'; break;
	case 'н': r = 'Н'; break;
	case 'о': r = 'О'; break;
	case 'п': r = 'П'; break;
	case 'р': r = 'Р'; break;
	case 'с': r = 'С'; break;
	case 'т': r = 'Т'; break;
	case 'у': r = 'У'; break;
	case 'ф': r = 'Ф'; break;
	case 'х': r = 'Х'; break;
	case 'ц': r = 'Ц'; break;
	case 'ч': r = 'Ч'; break;
	case 'ш': r = 'Ш'; break;
	case 'щ': r = 'Щ'; break;
	case 'ъ': r = 'Ъ'; break;
	case 'ы': r = 'Ы'; break;
	case 'ь': r = 'Ь'; break;
	case 'э': r = 'Э'; break;
	case 'ю': r = 'Ю'; break;
	case 'я': r = 'Я'; break;
	}
	
	return r;
}

int MyIsLower(char r)
{
	const char* alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"; // маленькими
	for (int i = 0; alph[i] != '\0'; i++) 
	{
		if (alph[i] == r)
			return 1;
	}
	
	return 0;
}

int func(char* str) 
{
	int len_pred = 0, count_ident = 0, width = 0, cur_width = 0;
	char* pred_slovo = NULL; 
	scanf("%d", &width);

	char* token = strtok(str, " "); // Лишние пробелы учитываются
	while (token != NULL) 
	{
		if (pred_slovo != NULL) 
		{
			len_pred = strlen(pred_slovo);
		}
		
		if (MyIsLower(token[0]) && ((count_ident == 0) || (pred_slovo != NULL && (pred_slovo[len_pred - 1] == '.' 
		|| pred_slovo[len_pred - 1] == '?' || pred_slovo[len_pred - 1] == '!')))) 
		{
			token[0] = MyToUpper(token[0]);
		}
		
		cur_width += strlen(token); // Записываем длину текущего слова
		count_ident++;
		
		if (cur_width >= width) // Форматирование по ширине
		{
			printf("\n%s ", token);
			cur_width = strlen(token);
		}
		else
			printf("%s ", token);
		
		pred_slovo = token;
		token = strtok(NULL, " ");
	}
	
	return 0;
}

int main() 
{
	char msg[600];
	
	// Кириллица
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	fgets(msg, 600, stdin);

	func(msg);
	
	return 0;
} 
