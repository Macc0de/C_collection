/* Склеивание двух односвязных списков, Застёжка-молния. Остаток более длинного списка записывается подряд.
Сначала идет первый элемент первого списка, затем первый элемент второго списка и тд. */
void merge(struct List First, struct List Second)
{
	struct List first_current = First, second_current = Second;
	
	while(first_current && second_current)
	{
		struct List* first_next = first_current->Next;
		struct List* second_next = second_current->Next;
		
		// Перестановки
		first_current->Next = second_current;
		second_current->Next = first_next;
		
		// Следующие элементы при итерации
		first_current = first_next;
		second_current = second_next;
	}
	
	/* Если во втором списке остались лишние элементы после перестановки,
	то дописываем в конец первого */
	if(second_current)
	{
		first_current = First;
		while(first_current->Next)
		{
			first_current = first_current->Next;
		}
		first_current->Next = second_current;
	}
	
	Second = second_current; // Меняется корень второго списка
}

// Для двусвязных списков
void merge(struct List* First, struct List** Second)
{
	struct List* first_current = First, *second_current = *Second;
	
	while(first_current && second_current)
	{
		struct List* first_next = first_current->Next;
		struct List* second_next = second_current->Next;
		
		// Перестановки
		second_current->Next = first_next; // NULL <- 4 -> 2 
		second_current->Previous = first_current; // 1 <- 4 -> 2
		first_current->Next = second_current; // 1 <-> 4 -> 2
		
		if(first_next)
		{
			first_next->Previous = second_current;
		}
		
		// Следующие элементы при итерации	
		first_current = first_next;
		second_current = second_next;
	}
	
	/* Если во втором списке остались лишние элементы после престановки,
	то дописываем в конец первого */
	if(second_current)
	{
		first_current = First;
		while(first_current->Next)
		{
			first_current = first_current->Next;
		}
		first_current->Next = second_current;
	}
	
	*Second = second_current; // Меняется корень второго списка
}
