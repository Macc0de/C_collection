struct List* func()
{
	if(First == NULL || First->Next == NULL)
		return First;
	
	// Поменять местами первый и последний элемент
	struct List* last = First, *p_last = First, *temp;
	
	// Поиск последнего элемента
	while(last->Next)
		last = last->Next;
	
	// Поиск предпоследнего элемента
	while(p_last->Next != last)
		p_last = p_last->Next;
		
	p_last->Next = First; // Перестановка первого элем. на последний
	last->Next = First->Next; // Перестановка последнего элем. на первый
	First->Next = NULL; // Последний элем.
	
	// Указание корня списка
	temp = First;
	First = last;
	last = temp;
	
	return First;
}
