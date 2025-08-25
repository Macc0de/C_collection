// Дано 2 односвязных списка элементов
struct List
{
	int Value;
	struct List* Next;
} *FirstA, *FirstB;

/* Написать функцию, которая объединяет эти списки, записывая элементы через один(как в застежке-молнии), 
начиная со списка А. Остаток более длинного списка записывается подряд. */
struct List* merge()
{
	if(FirstA == NULL && FirstB == NULL)
		return FirstA;
	
	struct List *first_current = FirstA, *second_current = FirstB, *first_next, *second_next;
	
	while(first_current != NULL && second_current != NULL)
	{
		first_next = first_current->Next;
		second_next = second_current->Next;
		
		// Перестановки
		first_current->Next = second_current;
		second_current->Next = first_next;
		
		// Следующие элементы при итерации
		first_current = first_next;
		second_current = second_next;
	}
	
	/* Если во втором списке остались лишние элементы после перестановки,
	то дописываем в конец первого */
	if(FirstA == NULL) // Если первый список пуст
	{
		FirstA = FirstB;
		second_current = NULL; // Второй список
	}
	else // Если первый список не пуст
	{
		if(second_current != NULL)
		{
			first_current = FirstA;
			while(first_current->Next != NULL)
			{
				first_current = first_current->Next;
			}
			first_current->Next = second_current;
			second_current = NULL; // Второй список
		}
	}
	
	FirstB = second_current; // Меняется корень второго списка
	
	return FirstA;
}
