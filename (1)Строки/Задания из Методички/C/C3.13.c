/* 
x = y + z
a = x + y
x = y + z

В приведенной последовательности действий третий оператор должен быть исключен
*/
#include <stdio.h>
#include <string.h>

int main() 
{
    int numStatements = 0;
    char input[100];
    char statements[100][100];

    // Считывание
    while (fgets(input, sizeof(input), stdin)) 
    {
        input[strcspn(input, "\n")] = '\0'; // Удаление переноса строки новой строки
        // strcspn - определение длины участка строки не содержащего указанный символ
        if (strlen(input) == 0) 
        { // Если ничего не ввел - беск. цикл
            break;
        }
		
        // Копируем оператор в массив операторов
        strcpy(statements[numStatements++], input); // Кол-во строк которые ввели(numState)
    }

    // Удаляет повторяющиеся операторы присваивания
    for (int i = 0; i < numStatements; i++) 
	{
        if (strstr(statements[i], "=") != NULL) // Поиск внутри строки "=" 
		{
            // strstr поиск первого вхождения "=" в statements[i]
            for (int j = i + 1; j < numStatements; j++) // Начиная со следующего элемента
			{
                // После текущего элемента если есть такой же самый, то удаляем
                if (strcmp(statements[i], statements[j]) == 0) 
				{
                    strcpy(statements[j], ""); // Копируем пустую строку (удаляем если изменяется значение)
                }
            }
        }
    }
	
    printf("Modified Program:\n");
    for (int i = 0; i < numStatements; i++) 
	{
        if (strlen(statements[i]) > 0) // из-за 29
            printf("%s\n", statements[i]);
    }
	
    return 0;
}
